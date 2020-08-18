
#include <cmath>

#include "numalg.h"
#include "utils.h"



// the bisection method
double numalg::root::bisect(const std::function<double(double)>& f, 
    const double& a, const double& b, const double& tolerance) {

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

    // check which one of the points we should return
    if (std::abs(y_1) < std::abs(y_0)) {
        return x_1;
    } else {
        return x_0;
    }
}

// secant method
double numalg::root::secant(const std::function<double(double)>& f, 
    const double& a, const double& b, const double& tolerance) {

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



double numalg::integral::simpson(double (*f)(double), double a, double b, unsigned long n) {

    // make n even
    if (n & 1) {
        n++;
    }

    std::vector<double> x = utils::linspace<double>(a, b, n + 1);
    double dx = x[1] - x[0];
    
    // end points
    double s = f(a) + f(b);

    // all the rest
    for (unsigned long k = 1; k < n; ++k) {
        if (k & 1) {
            s += 4 * f(x[k]);
        } else {
            s += 2 * f(x[k]);
        }
    }

    return dx/3 * s;
}

double numalg::integral::trapezoid(double (*f)(double), double a, double b, unsigned long n) {
    std::vector<double> x = utils::linspace<double>(a, b, n + 1);

    double dx = x[1] - x[0];

    // end points
    double s = f(a) + f(b);

    // all the rest
    for (unsigned long k = 1; k < n; ++k) {
        s += 2 * f(x[k]);
    }

    return dx / 2 * s;

}