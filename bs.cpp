
#include <iostream>

#include <cmath>
#include "numalg.hpp"
#include "utils.hpp"

#include "bs.hpp"    


double black_scholes::call_price(double S, double K, double t, double r, double sigma) {
    double d1 = (std::log(S) - std::log(K) +  (r + 0.5 * sigma*sigma) * t) / (sigma * std::sqrt(t));
    double d2 = d1 - sigma * std::sqrt(t);

    return utils::normal_cdf(d1) * S - utils::normal_cdf(d2) * K * std::exp(-r * t);
}

double black_scholes::put_price(double S, double K, double t, double r, double sigma) {
    double d1 = (std::log(S / K) +  (r + 0.5 * sigma*sigma) * t) / (sigma * std::sqrt(t));
    double d2 = d1 - sigma * std::sqrt(t);

    return utils::normal_cdf(-d2) * K * std::exp(-r * t) - utils::normal_cdf(-d1) * S;
}


double black_scholes::call_impvol(double S, double K, double t, double C, double r) {
    auto f = [&] (double sigma) { return call_price(S, K, t, r, sigma) - C; };

    // bisect may be more stable
    // double iv = numalg::root_bisect(f, iv_min_sigma, iv_max_sigma);
    double iv = numalg::root_secant(f, 0.05, 1.0);

    return iv;
}

double black_scholes::put_impvol(double S, double K, double t, double P, double r) {
    auto f = [&] (double sigma) { return put_price(S, K, t, r, sigma) - P; };

    // using bisect could be more stable
    double iv = numalg::root_secant(f, 0.05, 1.0);

    return iv;
}

