
#include <iostream>

#include <cmath>
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


/*
 calculate implied volatility using bisection method
*/
double black_scholes::call_impvol(double S, double K, double t, double C, double r) {
    unsigned int round = 0;
    
    auto f = [&] (double sigma) { return call_price(S, K, t, r, sigma) - C; };

    double sig_0 = iv_min_sigma;
    double sig_1 = iv_max_sigma;

    double y_0 = f(sig_0);
    double y_1 = f(sig_1);
   
    if (y_0 > 0 || y_1 < 0) {
        return 0;
    }

    while (std::abs(y_0) > iv_tolerance || std::abs(y_1) > iv_tolerance || round >= iv_max_rounds) {

        double sigma_new = 0.5 * (sig_0 + sig_1);
        double y_new = f(sigma_new);

        if (y_new < 0) {
            sig_0 = sigma_new;
            y_0 = y_new;
        } else {
            sig_1 = sigma_new;
            y_1 = y_new;
        }

        round++;
    }

    double rv = 0;

    if (std::abs(y_0) < std::abs(y_1)) {
        rv = sig_0;
    } else {
        rv = sig_1;
    }

    return rv;
}

double black_scholes::put_impvol(double S, double K, double t, double P, double r) {

    unsigned int round = 0;
    
    auto f = [&] (double sigma) { return put_price(S, K, t, r, sigma) - P; };


    double sig_0 = iv_min_sigma;
    double sig_1 = iv_max_sigma;

    double y_0 = f(sig_0);
    double y_1 = f(sig_1);
   
    while (std::abs(y_0) > iv_tolerance || std::abs(y_1) > iv_tolerance || round >= iv_max_rounds) {
        double sigma_new = 0.5 * (sig_0 + sig_1);
        double y_new = f(sigma_new);
        
        if (y_new < 0) {
            sig_0 = sigma_new;
            y_0 = y_new;
        } else {
            sig_1 = sigma_new;
            y_1 = y_new;
        }
        

        round++;
    }

    double rv = 0;

    if (std::abs(y_0) < std::abs(y_1)) {
        rv = sig_0;
    } else {
        rv = sig_1;
    }

    return rv;
}

