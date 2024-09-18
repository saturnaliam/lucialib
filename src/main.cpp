#include "luciavector.hpp"
#include <iostream>

auto main(void) -> int {
    lstd::vector<int> x({1, 2, 3});
    std::cout << x.pop();
    std::cout << " " << x.pop();
    x.push(5);
    x.reverse();
    
}