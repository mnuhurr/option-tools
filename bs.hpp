

namespace black_scholes {
    const double iv_min_sigma = 1e-6;
    const double iv_max_sigma = 100.0;

    const unsigned int iv_max_rounds = 1000;
    const double iv_tolerance = 1e-9;

    double call_price(double S, double K, double t, double r, double sigma);
    double put_price(double S, double K, double t, double r, double sigma);

    double call_impvol(double S, double K, double t, double C, double r);
    double put_impvol(double S, double K, double t, double P, double r);
}