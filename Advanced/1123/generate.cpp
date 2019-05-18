#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <array>
#include <type_traits>
using namespace std;

template<size_t N>
constexpr void foo(const char (&str)[N]) {
    cout << N;
}

constexpr int f(int i) {
    return i / 2;
}

template <typename T, T ...t>
struct MyArr {
    T data[sizeof...(t)]{t...};
};

struct MyStr {
    template<size_t N>
    constexpr MyStr(const char (&str)[N])
        : num(N - 1)
        , data(&str[0]) {}

    size_t num{0};
    const char* data = nullptr;
};

struct MyArray {
    template<size_t N>
    constexpr MyArray(const array<int, N> &arr) {}
};

struct MyVec {
    template <size_t N>
    constexpr MyVec(const int (&arr)[N]) 
        : num(N)
        , data(arr) /* 这一段不行？*/
    {}

    template <size_t N>
    constexpr MyVec(const array<int, N> &arr) 
        // : num(N), data(&arr[0])
     {}

    constexpr size_t size() const {
        return num;
    }

    size_t num{0};
    const int data[];
};

template <typename T, size_t N>
constexpr int len(const T (&arr)[N]) {
    return N;
}

struct TestArrBinding {
    template<size_t N>
    constexpr TestArrBinding(const int (&arr)[N]) 
     : data(&arr[0]) {}

     const int* data = nullptr;
};

int main() {
    constexpr int i = 10;
    static_assert(f(i) == 5, "Fales");
    constexpr int arr[]{1, 2, 3};
    const array<int, 3> arr1{1, 2, 3};
    constexpr int l = len(arr); // 
    cout << len(arr) << "\n";
    static_assert(arr1.size() == 3, "False");
    cout << is_trivially_destructible<MyVec>::value << "\n";
    constexpr MyVec vec(arr);
    // static_assert(vec.size() == 3, "False");
    // constexpr TestArrBinding test_arr_binding(arr);
    const int* data = &arr[0];

    constexpr MyStr my("Helloi");
    constexpr char s[] = "Hello";
    MyStr my1(s);
}