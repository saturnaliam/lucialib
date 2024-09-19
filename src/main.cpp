#include "luciaoptional.hpp"
#include <iostream>


auto main(void) -> int {
    lstd::optional<int> x = std::nullopt;
    std::cout << x.value(3);
}