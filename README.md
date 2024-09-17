# about
**lucialib** is a set of common tools i use when programming in C++

# ideas / todos
**Logger** - simple logging tool :3
**Vector** - a better wrapped vector

## Logger
logging ft. good `error()`, `warning()`, and `print()` functions, including an option to log to a file.

## Vector
wrap functions in the `algorithm` header better.

```C++
// instead of this
std::vector<int> x{1, 2, 3, 4, 5};
std::for_each(x.begin(), x.end(), []() {});

// do this
lucia::vector<int> x{1, 2, 3, 4, 5};
x.for_each([]() {});
```