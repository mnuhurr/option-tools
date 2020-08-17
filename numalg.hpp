
#pragma once

#include <functional>

namespace numalg {

const double tol = 1e-12;

namespace root {

// Find the root of a function with the bisection method. The root should 
// lie between a and b.
double bisect(const std::function<double(double)>& f, 
    const double& a, const double& b, const double& tolerance = tol);

// Find a root of a function using the secant method. The given points a 
// and b should reside near the root
double secant(const std::function<double(double)>& f, 
    const double& a, const double& b, const double& tolerance = tol);

} // namespace root


// Methods for numeric integration.
namespace integral {

// Compute definite integral using Simpson's rule. Here n is the number of 
// intervals, so the number of points is n + 1. Uf n is not even then use 
// n + 1 points.    
double simpson(double (*f)(double), double a, double b, unsigned long n);

// Compute definite integral using the trapezoid method. The argument n is
// the number of intervals, and the number of points is n + 1.
double trapezoid(double (*f)(double), double a, double b, unsigned long n);

} // namespace integral

} // namespace numalg