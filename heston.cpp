/*

option pricing with heston model

*/


#include <vector>
#include <complex>
#include <cmath>

#include "heston.hpp"
#include "utils.hpp"
#include "cvec.hpp"
#include "fft.hpp"

using consts::pi;


std::vector<double> heston::call_prices_fft(parameters* model, const double& S, const double& v_0, const std::vector<double>& strikes, const double& T, const unsigned int n_steps) {
    std::vector<double> cp;

    std::complex<double> i(0, 1);

    double x0 = std::log(S);
    double alpha = 1.25;
    double c = 600.0;
    double eta = c / n_steps;
    double b = pi / eta;
    complex_vector u(utils::range<double>(0, c, eta));

    complex_vector v = u - i * (alpha + 1);
    complex_vector zeta = -0.5 * (i * v + v.square());
    complex_vector gamma = v * (-i) * model->rho * model->xi  + model->kappa;
    
    complex_vector phi = complex_vector::sqrt(gamma.square() - zeta * 2 * std::pow(model->xi, 2));
    
    complex_vector A = i * v* (x0 + model->mu * T);
    complex_vector B =  v_0 * ((2 * zeta * (1 - complex_vector::exp(-phi * T))) / (2 * phi - (phi - gamma) * (1 - complex_vector::exp(-phi * T))));
    complex_vector C =  -model->kappa * model->theta / std::pow(model->xi, 2) * (2 * complex_vector::log((2 * phi - (phi - gamma) * (1 - complex_vector::exp(-phi * T))) / (2 * phi)) + (phi - gamma) * T);


    complex_vector char_func = complex_vector::exp(A + B + C);  
    complex_vector mod_cf = char_func * std::exp(-model->mu * T) / (std::pow(alpha, 2) + alpha - u.square() + i * (2 * alpha + 1) * u);

    complex_vector weights = 3.0 + complex_vector::pow(-i, utils::range<double>(1, n_steps + 1));
    weights[0] -= 1.0;
    weights /= 3.0;
    
    complex_vector cmplx_payoff = fft::fft(complex_vector::exp(i * b * u) * mod_cf * eta * weights);
    
    // collect payoffs
    double lam = 2 * b / n_steps;

    for (auto K : strikes) {
        unsigned long pos = std::round((std::log(K) + b) / lam);
        double payoff = cmplx_payoff[pos].real();

        double cv = std::exp(-std::log(K) * alpha) * payoff / pi;

        cp.push_back(cv);
    }

    return cp;
}