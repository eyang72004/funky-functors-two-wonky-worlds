#pragma once

#include <vector>
#include <stdexcept>
#include <sstream>
#include <utility>
#include <initializer_list>

namespace mathfun {

// NonEmptyVector<T> : runtime-enforced non-empty vectors of T
// For each T, NonEmptyVector<T> corresponds to a subset of std::vector<T>

template <typename T>
class NonEmptyVector {

public:
    using value_type = T;

    NonEmptyVector() = delete; // cannot default-construct empty

    explicit NonEmptyVector(const std::vector<T>& xs) {
        if (xs.empty()) {
            throw std::invalid_argument("NonEmptyVector cannot be empty");
        }
        data_ = xs;
    }

    explicit NonEmptyVector(std::vector<T>&& xs) {
        if (xs.empty()) {
            throw std::invalid_argument("NonEmptyVector cannot be empty");
        }
        data_ = std::move(xs);
    }

    NonEmptyVector(std::initializer_list<T> xs) {
        if (xs.size() == 0) {
            throw std::invalid_argument("NonEmptyVector cannot be empty");
        }
        data_ = xs;
    }

    const std::vector<T>& underlying() const { return data_; }
    std::vector<T>& underlying() { return data_; }

    std::size_t size() const { return data_.size(); }

    const T& operator[](std::size_t i) const { return data_[i]; }
    T& operator[](std::size_t i) { return data_[i]; }

    bool operator==(const NonEmptyVector<T>& other) const {
        return data_ == other.data_;
    }

private:
    std::vector<T> data_;
};


// Attempted helper for printing NonEmptyVector

template <typename T>
std::string to_string(const NonEmptyVector<T>& xs) {
    std::ostringstream oss;
    oss << "NE[";
    const auto& v = xs.underlying();
    bool first = true;

    for (const auto& x : v) {
        if (!first) oss << ", ";
        first = false;
        oss << x;
    }
    oss << "]";
    return oss.str();
}


// Subfunctor: NonEmptyVectorFunctor
// 
//  Objects: types T
// G(T) = NonEmptyVector<T>, subset of std::vector<T>
// Morphisms: functions from T to U lifted elementwise, preserves non-emptiness

struct NonEmptyVectorFunctor {
    template <typename F, typename T>
    auto map(F f, const NonEmptyVector<T>& xs) const {
        using U = decltype(f(std::declval<T>()));

        const auto& v = xs.underlying();

        std::vector<U> result;
        result.reserve(v.size());
        for (const auto& x : v) {
            result.push_back(f(x));
        }

        return NonEmptyVector<U>(std::move(result));
    }
};

} // namespace mathfun
