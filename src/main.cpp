#include "lucialog.hpp"
#include "luciavector.hpp"
auto main(void) -> int {
    lucia::vector<int> x({1, 2, 3});
    lucia::vector<int> y;
    y = x.map([](int z) { return z * 2; });
    std::cout << y[0];
}