/*
 * methods for option pricing with black-scholes-merton model. also methods for implied volatility.
 *  
 * */

namespace black_scholes {
    // some constants for numeric recipes
    const double iv_min_sigma = 1e-6;
    const double iv_max_sigma = 100.0;

    const unsigned int iv_max_rounds = 1000;
    const double iv_tolerance = 1e-9;

    // option pricing
    double call_price(double S, double K, double t, double r, double sigma);
    double put_price(double S, double K, double t, double r, double sigma);

    // implied volatility
    double call_impvol(double S, double K, double t, double C, double r);
    double put_impvol(double S, double K, double t, double P, double r);
}