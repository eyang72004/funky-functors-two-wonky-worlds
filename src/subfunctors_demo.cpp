#include <iostream>

#include "contravariant_functors.hpp"
#include "functor_laws.hpp"
#include "subfunctors.hpp"
#include "math_functors.hpp"

int main() {
    using namespace mathfun;

    std::cout << "=== Subfunctors Demo (NonEmptyVector) ===\n\n";

    NonEmptyVectorFunctor nevF;

    NonEmptyVector<int> xs{1, 2, 3};

    auto double_fn = [](int x) { return x * 2; };

    auto ys = nevF.map(double_fn, xs);

    std::cout << "xs (NonEmptyVector) = " << to_string(xs) << "\n";
    std::cout << "nevF.map(double_fn, xs) = " << to_string(ys) << "\n\n";

    bool id_ok = check_identity(nevF, xs);

    auto f = [](int x) { return x + 1; };
    auto g = [](int x) { return x * 2; };
    bool comp_ok = check_composition(nevF, f, g, xs);

    std::cout << "NonEmptyVectorFunctor identity law on xs?? " << (id_ok ? "true" : "false") << "\n";
    std::cout << "NonEmptyVectorFunctor composition law on xs?? " << (comp_ok ? "true" : "false") << "\n\n";

    std::cout << "For each type T, NonEmptyVector<T> is a subset of std::vector<T>.\n"
                 "Elementwise mapping preserves length, so non-emptiness is preserved.\n"
                 "I hope this gives a concrete example of a subfunctor of the vector functor..\n";

    return 0;
}
