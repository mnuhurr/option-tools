
#pragma once

#include <functional>

namespace numalg {
    const double tol = 1e-9;

    // find a root with a bisection method
    double root_bisect(const std::function<double(double)>& f, const double& a, const double& b, const double& tolerance = tol);
    double root_secant(const std::function<double(double)>& f, const double& a, const double& b, const double& tolerance = tol);
}