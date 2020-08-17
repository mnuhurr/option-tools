// 
// Methods for option pricing with the Heston stochastic volatility model.
//
//
// 
#pragma once


#include <vector>

namespace heston {

// Struct to use passing the Heston model parameters.
struct parameters {
    double mu;    // rate
    double theta; // long term volatility
    double kappa; // mean reversion rate
    double xi;    // vol of vol
    double rho;   // correlation of the two driving random processes
};

// Compute option prices for European calls using FFT. The returned vector 
// contains the option prices in the corresponding order to the strikes.
std::vector<double> call_prices_fft(parameters* model, const double& S, const double& v_0, 
    const std::vector<double>& strikes, const double& T, const unsigned int n_steps = 4096);
}

