#include <iostream>
#include <functional>
#include <algorithm>

#define USE_STL_VECTOR 1

#ifdef USE_STL_VECTOR
#include "CustomVector.h"
template<typename T>
using CV = CustomVector<T>;
#else
#include <vector>
template<typename T>
using CV = std::vector<T>;
#endif

template <typename Iterator, typename Function>
void my_for_each(Iterator begin, Iterator end, Function func) {
    for (auto it = begin; it != end; ++it) {
        func(*it);
    }
}

int main() {


    CV<int> v = { 3,4,6,1,3,8,2,3,7,3,4,9,1,5,89,1,2 };

    my_for_each(v.begin(), v.end(), [](int n) {
        std::cout << n << " ";
        });
    std::cout << std::endl;

    //std::sort(v.begin(), v.end());

    int i = 0;
    std::for_each(v.begin(), v.end(), [&v, &i](int n)
        {
            if (n % 2 == 0)
            {
                v[i] *= 2;
            }
            i++;
        });

    std::for_each(v.begin(), v.end(), [](const int& n) { std::cout << n << " "; });
    std::cout << std::endl;

    auto max = std::find(v.begin(), v.end(), 89);
    std::cout << max - &v[0] << std::endl;

    auto result = std::find_if(v.begin(), v.end(), [](int n) { return n == 8; });

    std::for_each(v.begin(), v.end(), [result, &v](const int& n)
    {
        if (n == *result)
    { 
            
            std::cout << result - &v[0] << std::endl;
    }});
    return 0;
}
