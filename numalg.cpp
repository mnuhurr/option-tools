
#include <cmath>

#include "utils.hpp"
#include "numalg.hpp"


#include <iostream>

double numalg::root_bisect(const std::function<double(double)>& f, const double& a, const double& b, const double& tolerance) {
    /**
     * find a root with the bisect method. f(a) and f(b) should have different signs.
     * 
     * arguments:
     * f: function 
     * a: the first endpoint of the search interval
     * b: the another endpoint of the search interval
     * 
     * returns: root for f.
     */
    double x_0 = a;
    double x_1 = b;
    double x_new = 0;

    double y_0 = f(x_0);
    double y_1 = f(x_1);
    double y_new = 0;

    const unsigned int max_rounds = 1000;
    unsigned int round = 0;

    while ((std::abs(y_0) > tolerance || std::abs(y_1) > tolerance) && round <= max_rounds) {
        // sanity check
        if ((y_0 < 0 && y_1 < 0) || (y_0 > 0 && y_1 > 0)) {
            // same sign, unable to find root
            throw "unable to find root";
        }

        // split the interval
        x_new = 0.5 * (x_0 + x_1);
        y_new = f(x_new);

        if (utils::sgn<double>(y_new) == utils::sgn(y_0)) {
            x_0 = x_new;
            y_0 = y_new;
        } else {
            x_1 = x_new;
            y_1 = y_new;
        }


        round++;
    }

    std::cout << "bisect rounds: " << round << std::endl;

    // check which one of the points we should return
    if (std::abs(y_1) < std::abs(y_0)) {
        return x_1;
    } else {
        return x_0;
    }
}

double numalg::root_secant(const std::function<double(double)>& f, const double& a, const double& b, const double& tolerance) {
    /**
     * find a root with the secant method. the given function arguments of f should reside near the root.
     * 
     * arguments:
     * f: function 
     * a: some argument for f
     * b: another argument for f
     * 
     * return: x for which f(x) = 0.
     */

    double x_0 = a;
    double x_1 = b;
    double x_new = 0;

    double y_0 = f(x_0);
    double y_1 = f(x_1);
    double y_new = tolerance + 1;

    const unsigned int max_rounds = 1000;
    unsigned int round = 0;

    while (round <= max_rounds) {
        x_new = x_1 - y_1 * (x_1 - x_0) / (y_1 - y_0);
        y_new = f(x_new);

        if (std::abs(y_new) < tolerance) {
            std::cout << "secant rounds: " << round << std::endl;
            return x_new;
        }

        x_0 = x_1;
        y_0 = y_1;

        x_1 = x_new;
        y_1 = y_new;

        round++;
    }

    return x_new;
}