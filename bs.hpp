//
// Methods for option pricing with Black-Scholes-Merton model. 
//  
 

namespace black_scholes {
// some constants for numeric recipes
const double iv_min_sigma = 1e-6;
const double iv_max_sigma = 100.0;

const unsigned int iv_max_rounds = 1000;
const double iv_tolerance = 1e-9;


// Compute price for an european call option using black-scholes-merton model.
// 
// arguments:
//  S: underlying price
//  K: strike price
//  t: time to maturity
//  r: rate
//  sigma: volatility
double call_price(double S, double K, double t, double r, double sigma);

// Compute price for an european put option using black-scholes-merton model.
// 
// arguments:
//  S: underlying price
//  K: strike price
//  t: time to maturity
//  r: rate
//  sigma: volatility
double put_price(double S, double K, double t, double r, double sigma);

// Method to find numerically Black-Scholes-Merton model implied volatility 
// 
// arguments:
//  S: underlying price
//  K: strike price
//  t: time to maturity
//  C: call price
//  r: rate
double call_impvol(double S, double K, double t, double C, double r);

// Method to find numerically Black-Scholes-Merton model implied volatility 
// 
// arguments:
//  S: underlying price
//  K: strike price
//  t: time to maturity
//  P: put price
//  r: rate
double put_impvol(double S, double K, double t, double P, double r);


} // namespace black_scholes