#pragma once

#include <vector>

#include "cvec.hpp"

namespace consts {
    const double pi = 3.141592653589793238463;
}

namespace utils {
    double normal_cdf(double x);
    void print_cv(const complex_vector& v);


    template<typename T>
    std::vector<T> range(const T& start, const T& end, const T& incr = 1) {
        std::vector<T> ret;
        for (T it = start; it < end; it += incr) {
            ret.push_back(it);
        }
        return ret;
    }

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
}


