#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>

// Here I will try to implement a classic C++ function object (functor)...

class Multiplier {
    int factor;

public:
    explicit Multiplier(int f) : factor(f) {}

    int operator()(int x) const {
        return x * factor;
    }
};

// Here is what seems to be a stateful functor that remembers how many times it was called....

class CountingPredicate {
    int threshold;
    mutable int count; // allows modification in the const operator()

public:
    explicit CountingPredicate(int t) : threshold(t), count(0) {}

    bool operator()(int x) const {
        ++count;
        return x > threshold;
    }

    int calls() const {
        return count;
    }
};

int main() {
    std::cout << "=== C++ Functors (Function Objects) Demo ===\n\n";

    std::vector<int> nums{1, 2, 3, 4};
    std::vector<int> doubled(nums.size());

    std::transform(nums.begin(), nums.end(), doubled.begin(), Multiplier(2)); // function object

    std::cout << "Original numbers: ";
    for (int n : nums) {
        std::cout << n << " ";
    }

    std::cout << "\nDoubled numbers: ";
    for (int n : doubled) {
        std::cout << n << " ";
    }
    std::cout << "\n\n";

    CountingPredicate greater_than_two(2);
    std::vector<int> filtered;

    std::copy_if(nums.begin(), nums.end(), std::back_inserter(filtered), greater_than_two);

    std::cout << "Numbers greater than 2: ";
    for (int n : filtered) {
        std::cout << n << " ";
    }
    std::cout << "\nCountingPredicate was called " << greater_than_two.calls() << " times.\n\n";

    auto add_prefix = [](const std::string& s) {
        return std::string{"fun_"} + s;
    };

    std::vector<std::string> names{"ctor", "dtor", "lambda"};
    std::vector<std::string> tagged(names.size());

    std::transform(names.begin(), names.end(), tagged.begin(), add_prefix);

    std::cout << "\nNote: These are 'functors' only in the C++ sense "
                 "(callable objects). They are not required to preserve "
                 "any mathematical structure like in category theory.\n";

    return 0;
}
