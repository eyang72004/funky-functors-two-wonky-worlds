#pragma once 

#include <vector>
#include <optional>
#include <sstream>
#include <utility>



namespace mathfun {

// These will likely serve as helpers for printing...

template <typename T>

std::string to_string(const std::vector<T>& xs) {
    std::ostringstream oss;

    oss << "[";

    bool first = true;

    for (const auto& x : xs) {
        if (!first) {
            oss << ", ";
        }
        first = false;
        oss << x;
    }

    oss << "]";
    return oss.str();
}


template <typename T>
std::string to_string(const std::optional<T>& opt) {
    if (opt.has_value()) {
        std::ostringstream oss;
        oss << "Just(" << *opt << ")";
        return oss.str();
    } else {
        return "Nothing";
    }





}



// Here I will try to implement the covariant functor as VectorFunctor......
//
// Objects: types T
// Morphisms: functions from T to U
// Functor F: maps type T to std::vector<T>
// F(f) = elementwise map(f)


struct VectorFunctor {
    template <typename F, typename T>

    auto map(F f, const std::vector<T>& xs) const {

        using U = decltype(f(std::declval<T>()));
        std::vector<U> result;
        result.reserve(xs.size());
        for (const auto& x : xs) {
            result.push_back(f(x));
        }
        return result;
    }



};


// Now here I will try to implement the covariant functor of OptionalFunctor.....
//
// Objects: types T
// Morphisms: functions from T to U
// Functor F: maps type T to std::optional<T>
// F(f) = apply f when there is a value

struct OptionalFunctor {

    template <typename F, typename T>

    auto map(F f, const std::optional<T>& opt) const {

        using U = decltype(f(std::declval<T>()));
        if (opt.has_value()) {
            return std::optional<U>(f(*opt));
        } else {
            return std::optional<U>{};
        }
    }
};

} // namespace mathfun
