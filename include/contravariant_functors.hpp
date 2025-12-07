#pragma once 

#include <functional>
#include <utility>


namespace mathfun {


// Here I try to implement a simple wrapper for a predicate A --> bool

template <typename A>
struct Predicate {
    std::function<bool(const A&)> run;

    explicit Predicate(std::function<bool(const A&)> f) : run(std::move(f)) {}

    bool operator()(const A& x) const {
        return run(x);
    }
};


// Now I will try to implement the contravariant functor for Predicate<_>.....
//
// Objects: types A
// F(A) = Predicate<A>
// Morphisms: h : B --> A
// F(h) : Predicate<A> --> Predicate<B> via precomposition: p |--> p ? h

struct PredicateContravariant {
    template <typename A, typename B, typename H>
    
    

    Predicate<B> contramap(H h, const Predicate<A>& p) const {
        return Predicate<B>(
            [h, p](const B& y) {
                return p(h(y)); // p ? h
            }
        );
    }

    // Here these are conceptual law helpers: in practice we will test them on finite samples...

    template <typename A>
    bool check_identity(const Predicate<A>& /*p*/) const {
        return true;
    }

    template <typename A, typename B, typename C, typename F, typename G>
    bool check_composition(const Predicate<A>& /*p*/, F /*f*/, G /*g*/) const {
        return true;
    }
};










} // namespace mathfun
