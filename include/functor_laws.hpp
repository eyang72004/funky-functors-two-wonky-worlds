#pragma once

#include <utility>

namespace mathfun {

// These are just generic helpers for covariant functor laws.
//
// Assumptions I have tried to make:
// - Functor F has a method:
//     template <typename Func, typename Container>
//     auto map(Func f, Container& xs) const;
// - Container has a nested value_type and supports operator==.
//


template <typename Functor, typename Container>
bool check_identity(const Functor& F, const Container& xs) {
    
    
    using T = typename Container::value_type;
    auto id = [](const T& x) { return x; };
    auto mapped = F.map(id, xs);
    return mapped == xs;
}


template <typename Functor, typename F1, typename F2, typename Container>
bool check_composition(const Functor& F, F1 f, F2 g, const Container& xs) {


    using T = typename Container::value_type;

    auto composed = [&](const T& x) {
        return g(f(x)); // g ? f
    };

    auto left = F.map(composed, xs);

    auto right = F.map(g, F.map(f, xs));

    return left == right;
}
} // namespace mathfun
