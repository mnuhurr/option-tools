
#pragma once

#include <functional>

namespace numalg {
    const double tol = 1e-12;

    // Find the root of a function with the bisection method. The root should 
    // lie between a and b.
    double root_bisect(const std::function<double(double)>& f, 
        const double& a, const double& b, const double& tolerance = tol);

    // Find a root of a function using the secant method. The given points a 
    // and b should reside near the root
    double root_secant(const std::function<double(double)>& f, 
        const double& a, const double& b, const double& tolerance = tol);
}