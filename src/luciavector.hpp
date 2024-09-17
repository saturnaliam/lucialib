#ifndef LUCIA_VECTOR_HPP_
#define LUCIA_VECTOR_HPP_

#include <algorithm>
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

            template<class UnaryFunc>
            constexpr auto for_each(UnaryFunc func) -> UnaryFunc {
                std::for_each(this->begin(), this->vec.end(), func);

                return func;
            }

            template<typename Functor, typename U = std::result_of<Functor(T)>::type>
            auto map(Functor &&f) -> lucia::vector<U> {
                std::vector<U> ret(this->vec.size());

                std::transform(this->begin(), this->end(), ret.begin(), f);

                return lucia::vector<U>(ret);
            }
    };
}

#endif // LUCIA_VECTOR_HPP_