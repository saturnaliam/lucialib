#ifndef LUCIA_VECTOR_HPP_
#define LUCIA_VECTOR_HPP_

#include <algorithm>
#include <numeric>
#include <vector>
namespace lucia {

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

            auto reverse() -> void {
                std::reverse(this->begin(), this->end());
            }

            auto reverse_copy() -> lucia::vector<T> {
                std::vector<T> dest(this->size());
                std::reverse_copy(this->begin(), this->end(), dest.begin());

                return lucia::vector<T>(dest);
            }

            template<class UnaryFunc>
            constexpr auto for_each(UnaryFunc &&func) -> UnaryFunc {
                std::for_each(this->begin(), this->end(), func);

                return func;
            }

            template<typename UnaryFunc, typename U = std::result_of<UnaryFunc(T)>::type>
            auto map(UnaryFunc &&f) -> lucia::vector<U> {
                std::vector<U> ret(this->size());

                std::transform(this->begin(), this->end(), ret.begin(), f);

                return lucia::vector<U>(ret);
            }

            template<class BinaryFunc>
            auto accumulate(BinaryFunc &&func) -> T {
                return std::accumulate(this->begin(), this->end(), func);
            }

            auto accumulate(const T &init) -> T {
                return std::accumulate(this->begin(), this->end(), init);
            }

            auto accumulate() -> T {
                return this->accumulate(0);
            }

            template<class BinaryFunc>
            auto reduce(BinaryFunc &&func) -> T {
                return std::reduce(this->begin(), this->end(), func);
            }

            template<class BinaryFunc>
            auto reduceRight(BinaryFunc &&func) -> T {
                return this->reverse_copy().reduce(func);
            }
    };
}

#endif // LUCIA_VECTOR_HPP_