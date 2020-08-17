#include <iostream>
#include <vector>

#include "bs.hpp"
#include "utils.hpp"
#include "heston.hpp"
#include "numalg.hpp"


int main() {
    // just a small test for now
    double t = 7.0 / 365.0;
    double S = 6.66;
    double v_0 = 0.04;

    std::vector<double> strikes = {3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5 };
    
    heston::parameters params = { 0.02, 0.09, 2.0, 0.1, -0.3 };   
    
    std::vector<double> cp = heston::call_prices_fft(&params, S, v_0, strikes, t, 4096);    

    for (unsigned long k = 0; k < strikes.size(); ++k) {
        std::cout << strikes[k] << ": " << cp[k] << std::endl;
    }
    
    double r = 0.05; 
    double sig = 0.04;
    double T = 0.2;
    double K = 6.0;

    double C = black_scholes::call_price(S, K, T, r, sig);
    double iv = black_scholes::call_impvol(S, K, T, C, r);
    
    std::cout << sig << " " << iv << std::endl;

    return 0;
}