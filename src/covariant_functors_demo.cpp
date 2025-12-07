#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <optional>

#include "math_functors.hpp"
#include "functor_laws.hpp"

int main() {
    using namespace mathfun;

    std::cout << "=== Covariant Functors Demo (VectorFunctor + OptionalFunctor) ===\n\n";

    // Testing VectorFunctor
    VectorFunctor vecF;

    std::vector<int> xs{1, 2, 3, 4};

    auto square = [](int x) { return x * x; };
    auto ys = vecF.map(square, xs);

    std::cout << "Attempted Vector Example:\n";
    std::cout << "xs = " << to_string(xs) << "\n";
    std::cout << "vecF.map(square, xs) = " << to_string(ys) << "\n\n";

    bool v_id_ok = check_identity(vecF, xs);

    auto f = [](int x) { return x + 1; };
    auto g = [](int x) { return x * 2; };
    bool v_comp_ok = check_composition(vecF, f, g, xs);

    std::cout << "VectorFunctor identity law on xs?? " << (v_id_ok ? "true" : "false") << "\n";
    std::cout << "VectorFunctor composition law on xs?? " << (v_comp_ok ? "true" : "false") << "\n\n";

    // Testing OptionalFunctor
    OptionalFunctor optF;

    std::optional<int> a = 10;
    std::optional<int> b; // Nothing..

    auto plus1 = [](int x) { return x + 1; };

    auto a_mapped = optF.map(plus1, a);
    auto b_mapped = optF.map(plus1, b);

    std::cout << "Attempted Optional Example:\n";
    std::cout << "a = " << to_string(a) << "\n";
    std::cout << "optF.map(plus1, a) = " << to_string(a_mapped) << "\n\n";
    std::cout << "b = " << to_string(b) << "\n";
    std::cout << "optF.map(plus1, b) = " << to_string(b_mapped) << "\n\n";

    bool o_id_ok_a = check_identity(optF, std::optional<int>(10));
    bool o_id_ok_b = check_identity(optF, std::optional<int>{});

    auto f2 = [](int x) { return x + 2; };
    auto g2 = [](int x) { return x * 3; };

    bool o_comp_ok_a = check_composition(optF, f2, g2, std::optional<int>(10));
    bool o_comp_ok_b = check_composition(optF, f2, g2, std::optional<int>{});

    std::cout << "OptionalFunctor identity law on Just(10)?? " << (o_id_ok_a ? "true" : "false") << "\n";
    std::cout << "OptionalFunctor identity law on Nothing?? " << (o_id_ok_b ? "true" : "false") << "\n\n";

    std::cout << "OptionalFunctor composition law on Just(10)?? " << (o_comp_ok_a ? "true" : "false") << "\n";
    std::cout << "OptionalFunctor composition law on Nothing?? " << (o_comp_ok_b ? "true" : "false") << "\n\n";

    std::cout << "Here, both VectorFunctor and OptionalCunftor are covariant endofunctors\n"
                 "on (a fragment of) the category of C++ types and functions between them.\n";

    return 0;
}
