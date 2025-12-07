#include <cassert>
#include <vector>
#include <optional>
#include <iostream>

#include "math_functors.hpp"
#include "functor_laws.hpp"
#include "subfunctors.hpp"
#include "contravariant_functors.hpp"

using namespace mathfun;

void test_vector_functor_laws() {
    VectorFunctor vecF;

    std::vector<int> xs{1, 2, 3, 4};

    // Identity
    assert(check_identity(vecF, xs));

    // Composition
    auto f = [](int x) { return x + 1; };
    auto g = [](int x) { return x * 2; };
    assert(check_composition(vecF, f, g, xs));
}

void test_optional_functor_laws() {
    OptionalFunctor optF;

    std::optional<int> just10 = 10;
    std::optional<int> nothing; // empty

    // Identity
    assert(check_identity(optF, just10));
    assert(check_identity(optF, nothing));

    // Composition
    auto f = [](int x) { return x + 2; };
    auto g = [](int x) { return x * 3; };

    assert(check_composition(optF, f, g, just10));
    assert(check_composition(optF, f, g, nothing));
}

void test_nonempty_vector_functor_laws() {
    NonEmptyVectorFunctor nevF;

    NonEmptyVector<int> xs{1, 2, 3};

    // Identity
    assert(check_identity(nevF, xs));

    // Composition
    auto f = [](int x) { return x + 1; };
    auto g = [](int x) { return x * 2; };
    assert(check_composition(nevF, f, g, xs));
}

void test_nonempty_vector_is_nonempty() {
    NonEmptyVectorFunctor nevF;

    NonEmptyVector<int> xs{1, 2, 3};

    auto double_fn = [](int x) { return x * 2; };

    auto ys = nevF.map(double_fn, xs);

    // Check that size is preserved and non-zero
    assert(ys.size() == xs.size());
    assert(ys.size() > 0);
}

void test_predicate_contravariant_sample() {
    PredicateContravariant predF;

    // Predicate on int: is_even
    Predicate<int> is_even{
        std::function<bool(const int&)>(
            [](const int& x) { return x % 2 == 0; }
        )
    };

    // h : double --> int, truncate
    auto truncate = [](double y) { return static_cast<int>(y); };

    // F(truncate)  : Predicate<int> --> Predicate<double>
    auto even_after_trunc = predF.contramap<int, double>(truncate, is_even);

    // Sample checks
    assert(even_after_trunc(3.9) == is_even(3));
    assert(even_after_trunc(4.1) == is_even(4));

    // Identity law sample: F(id) = id (extensional equality, sampled)
    auto id = [](int x) { return x; };
    auto p_id = predF.contramap<int, int>(id, is_even);

    for (int x : {-2, -1, 0, 1, 2, 3, 4}) {
        assert(p_id(x) == is_even(x));
    }

    // Composition Law sample:
    // f : int --> int (shift), g : double --> int (truncate)
    auto f = [](int x) { return x + 1; };
    auto g = [](double y) { return static_cast<int>(y); };

    auto fg = [&](double y) { return f(g(y)); }; // f ? g : double --> int

    auto left  = predF.contramap<int, double>(fg, is_even);
    auto temp  = predF.contramap<int, int>(f, is_even);
    auto right = predF.contramap<int, double>(g, temp);

    for (double d : {-1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 2.3, 3.7}) {
        assert(left(d) == right(d));
    }
}

int main() {
    std::cout << "Running functor laws tests...\n";

    test_vector_functor_laws();
    test_optional_functor_laws();
    test_nonempty_vector_functor_laws();
    test_nonempty_vector_is_nonempty();
    test_predicate_contravariant_sample();

    std::cout << "All tests passed!\n";
    return 0;
}
