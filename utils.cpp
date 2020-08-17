
#include <cmath>
#include <iostream>

#include "utils.hpp"
#include "cvec.hpp"


double utils::normal_cdf(double x) {
    return std::erfc(-x / std::sqrt(2)) / 2;
}

void utils::print_cv(const complex_vector& v) {
    for (unsigned int k = 0; k < v.length(); ++k) {
        std::cout << v[k] << " ";
    }

    std::cout << std::endl;
}


