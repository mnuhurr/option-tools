#pragma once

#include <vector>

#include "cvec.h"

// namespace for different constants
namespace consts {

const double pi = 3.141592653589793238463;

} // namespace consts



// namespace for various util functions. 
namespace utils {

// Compute standard normal CDF   
double normal_cdf(double x);

// Print a complex_vector into stdout
void print_cv(const complex_vector& v);


// Create a vector with linearly spaced elements.
template<typename T>
std::vector<T> range(const T& start, const T& end, const T& incr = 1) {
    std::vector<T> ret;
    for (T it = start; it < end; it += incr) {
        ret.push_back(it);
    }
    return ret;
}

// Create a vector with linearly spaced elements. Another way.
template <typename T>
std::vector<T> linspace(const T& a, const T& b, unsigned long n) {
    
    std::vector<T> ls(n);

    if (n > 1) {
        T delta = (b - a) / (n - 1);

        ls[0] = a;
        ls[n - 1] = b;

        for (unsigned long k = 1; k < n - 1; ++k) {
            ls[k] = a + k * delta;
        }
    }

    return ls; 
}

// Sign function.
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}


} // namespace utils


