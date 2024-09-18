#ifndef LUCIA_VECTOR_HPP_
#define LUCIA_VECTOR_HPP_

#include <algorithm>
#include <numeric>
#include <vector>

namespace lstd {

    // just a wrapper :3
    template<class T>
    class vector {
        private:
            std::vector<T> vec;

        public:
            vector(std::vector<T> vec) : vec(vec) {};
            vector() {};

            auto operator[](size_t pos) -> T {
                return this->vec[pos];
            }

            constexpr auto begin() {
                return this->vec.begin();
            }

            constexpr auto end() {
                return this->vec.end();
            }

            constexpr auto size() -> size_t {
                return this->vec.size();
            }

            constexpr auto back() -> T {
                return this->vec.back();
            }

            constexpr auto front() -> T {
                return this->vec.front();
            }

            constexpr auto reverse() -> void {
                std::reverse(this->begin(), this->end());
            }

            constexpr auto reverse_copy() -> lstd::vector<T> {
                std::vector<T> dest(this->size());
                std::reverse_copy(this->begin(), this->end(), dest.begin());

                return lstd::vector<T>(dest);
            }

            template<class UnaryFunc>
            constexpr auto for_each(UnaryFunc &&func) -> UnaryFunc {
                std::for_each(this->begin(), this->end(), func);

                return func;
            }

            template<typename UnaryFunc, typename U = std::result_of<UnaryFunc(T)>::type>
            constexpr auto map(UnaryFunc &&f) -> lstd::vector<U> {
                std::vector<U> ret(this->size());

                std::transform(this->begin(), this->end(), ret.begin(), f);

                return lstd::vector<U>(ret);
            }

            template<class BinaryFunc>
            constexpr auto accumulate(BinaryFunc &&func) -> T {
                return std::accumulate(this->begin(), this->end(), func);
            }

            constexpr auto accumulate(const T &init) -> T {
                return std::accumulate(this->begin(), this->end(), init);
            }

            constexpr auto accumulate() -> T {
                return this->accumulate(0);
            }

            constexpr auto fold() -> T {
                return this->accumulate(0);
            }

            template<class BinaryFunc>
            constexpr auto fold(BinaryFunc &&func) -> T {
                return std::reduce(this->begin(), this->end(), func);
            }

            template<class BinaryFunc>
            constexpr auto foldRight(BinaryFunc &&func) -> T {
                return this->reverse_copy().fold(func);
            }

            constexpr auto push(const T &value) -> void {
                this->vec.push_back(value);
            }

            constexpr auto pop() -> T {
                const T back = this->back();
                this->vec.pop_back();

                return back;
            }
    };
}

#endif // LUCIA_VECTOR_HPP_