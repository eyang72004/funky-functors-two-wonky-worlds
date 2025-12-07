#include <iostream>
#include <cmath>

#include "contravariant_functors.hpp"

int main() {
    using namespace mathfun;

    std::cout << "=== Contravariant Functors Demo (PredicateContravariant) ===\n\n";

    PredicateContravariant predF;

    // Predicate on int: is_even
    Predicate<int> is_even {
        [](int x) { return x % 2 == 0; }
    };

    // h : double --> int, truncate
    auto truncate = [](double y) { return static_cast<int>(y); };

    // F(truncate)  : Predicate<int> --> Predicate<double>
    auto even_after_trunc = predF.contramap<int, double>(truncate, is_even);

    std::cout << std::boolalpha;

    std::cout << "even_after_trunc(3.9) = "
              << even_after_trunc(3.9) << " (checks is_even(3))\n";

    std::cout << "even_after_trunc(4.1) = "
              << even_after_trunc(4.1) << " (checks is_even(4))\n\n";

    std::cout << "I would like to believe this illustrates a contravariant functor:\n"
                 " Objects: types A\n"
                 " F(A) = Predicate<A> --> bool\n"
                 " For h: B --> A, F(h) : Predicate<A> --> Predicate<B> via precomposition p |--> p ? h\n\n";

    return 0;
}
