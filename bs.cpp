
#include <iostream>

#include <cmath>
#include "numalg.hpp"
#include "utils.hpp"

#include "bs.hpp"    

double black_scholes::call_price(double S, double K, double t, double r, double sigma) {
    /**
     * compute price for an european call option using black-scholes-merton model
     * 
     * arguments:
     * S: underlying price
     * K: strike price
     * t: time to maturity
     * r: rate
     * sigma: volatility
     *    
     * returns: call price
    */
    
    double d1 = (std::log(S) - std::log(K) +  (r + 0.5 * sigma*sigma) * t) / (sigma * std::sqrt(t));
    double d2 = d1 - sigma * std::sqrt(t);

    return utils::normal_cdf(d1) * S - utils::normal_cdf(d2) * K * std::exp(-r * t);
}

double black_scholes::put_price(double S, double K, double t, double r, double sigma) {
    /**
     * compute price for an european put option using black-scholes-merton model
     * 
     * arguments:
     * S: underlying price
     * K: strike price
     * t: time to maturity
     * r: rate
     * sigma: volatility
     *    
     * returns: call price
    */

    double d1 = (std::log(S / K) +  (r + 0.5 * sigma*sigma) * t) / (sigma * std::sqrt(t));
    double d2 = d1 - sigma * std::sqrt(t);

    return utils::normal_cdf(-d2) * K * std::exp(-r * t) - utils::normal_cdf(-d1) * S;
}


double black_scholes::call_impvol(double S, double K, double t, double C, double r) {
    /**
     * calculate black-scholes-merton model implied volatility using bisection method
     * 
     * arguments:
     * S: underlying price
     * K: strike price
     * t: time to maturity
     * C: call option price
     * r: rate
     * 
     * returns: implied volatility. in case of some weird numbers (i.e. no root) returns zero.
    */
    
    auto f = [&] (double sigma) { return call_price(S, K, t, r, sigma) - C; };

    // bisect may be more stable
    // double iv = numalg::root_bisect(f, 0.01, 10.0);
    double iv = numalg::root_secant(f, 0.05, 1.0);

    return iv;
}

double black_scholes::put_impvol(double S, double K, double t, double P, double r) {
    /**
     * calculate black-scholes-merton model implied volatility using bisection method
     * 
     * arguments:
     * S: underlying price
     * K: strike price
     * t: time to maturity
     * C: call option price
     * r: rate
     * 
     * returns: implied volatility. in case of some weird numbers (i.e. no root) returns zero.
    */

    auto f = [&] (double sigma) { return put_price(S, K, t, r, sigma) - P; };

    // using bisect could be more stable
    double iv = numalg::root_secant(f, 0.05, 1.0);

    return iv;
}

