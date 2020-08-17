
#pragma once


#include <vector>

namespace heston {

    struct parameters {
        double mu;    // rate
        double theta; // long term volatility
        double kappa; // mean reversion rate
        double xi;    // vol of vol
        double rho;   // correlation of the two driving random processes
    };

    std::vector<double> call_prices_fft(parameters* model, const double& S, const double& v_0, const std::vector<double>& strikes, const double& T, const unsigned int n_steps = 4096);
}

