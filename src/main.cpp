#include "luciavector.hpp"
#include <iostream>

auto main(void) -> int {
    lucia::vector<int> x({1, 2, 3});
    auto y = x.reduce([] (auto a, auto b) { return a - b; });
    std::cout << y;
}