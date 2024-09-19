#ifndef LUCIA_OPTIONAL_HPP_
#define LUCIA_OPTIONAL_HPP_

#include <optional>
namespace lstd {
    template<typename T>
    class optional {
        private:
            std::optional<T> opt;

        public:
            optional(T input) : opt(input) {};
            optional(std::nullopt_t) : opt(std::nullopt) {};
            optional() : opt(std::nullopt) {};

            constexpr auto value() const -> T {
                return this->opt.value();
            }

            constexpr auto value(const T &default_value) const -> T {
                return this->opt.value_or(default_value);
            }

            constexpr auto value_or(const T &default_value) const -> T {
                return this->value(default_value);
            }

            constexpr auto remove_value() -> void {
                this->opt = std::nullopt;
            }

            constexpr optional operator=(const T &value) {
                this->opt = value;
            }

            constexpr optional operator=(std::nullopt_t) {
                this->opt = std::nullopt;
            }

            constexpr optional operator=(const std::optional<T> &value) {
                this->opt = value;
            }
    };
}

#endif // LUCIA_OPTIONAL_HPP_