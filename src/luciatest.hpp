#ifndef LUCIA_TEST_HPP_
#define LUCIA_TEST_HPP_

#include <string>

namespace lstd {
    template<typename T>
    constexpr auto assert(const T &val, const T &res) -> bool {
        return val == res;
    }

    template<typename T>
    constexpr auto t_assert(const T &val, const T &res, const std::string &msg) -> void {
        if (val == res) return;

        throw(msg);
    }

    template<typename T>
    constexpr auto assert_not(const T &val, const T &res) -> bool {
        return val != res;
    }

    template<typename T>
    constexpr auto t_assert_not(const T &val, const T &res, const std::string &msg) -> void {
        if (val != res) return;

        throw(msg);
    }
}

#endif // LUCIA_TEST_HPP_