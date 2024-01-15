#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

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
int main() {


    CV<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(8);
    v.push_back(8);
    v.push_back(8);
    v.push_back(2);


    for_each(v.begin(), v.end(), [](const int& n) { cout << n << " "; });
    cout << endl;
    auto result = find_if(v.begin(), v.end(), [](int n) { return n == 8; });
    for_each(v.begin(), v.end(), [](const int& n)
    {
        if (n == 8)
    { 
            
        cout << n << " "; 
    }});
    return 0;
}
