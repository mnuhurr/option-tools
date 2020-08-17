/*
 * class for vectorized computations of copmlex numbers. 
 * 
 */

#pragma once

#include <vector>
#include <complex>


// Class to handle a vector (or a finite sequence) of complex numbers.
// Operations with other objects of the same class are made element-wise.
class complex_vector {
public:
    complex_vector(const unsigned long& dim);
    complex_vector(const std::vector<std::complex<double>> cv);
    complex_vector(const std::vector<double> dv);
    complex_vector(const complex_vector& v);
    ~complex_vector();

    unsigned long length() const;
    double norm() const;

    complex_vector operator = (const complex_vector& cv);
   
    // negation
    complex_vector operator - () const;

    // element access
    std::complex<double> operator[] (const unsigned long& i) const;
    std::complex<double>& operator[] (const unsigned long& i);

    // scalar stuff
    complex_vector operator * (const double& d) const;
    complex_vector operator / (const double& d) const;
    complex_vector operator + (const double& d) const;
    complex_vector operator - (const double& d) const;
    
    complex_vector operator * (const std::complex<double>& z) const;
    complex_vector operator / (const std::complex<double>& z) const;
    complex_vector operator + (const std::complex<double>& z) const;
    complex_vector operator - (const std::complex<double>& z) const;

    complex_vector operator *= (const double& d);
    complex_vector operator /= (const double& d);
    complex_vector operator += (const double& d);
    complex_vector operator -= (const double& d);
    
    complex_vector operator *= (const std::complex<double>& z);
    complex_vector operator /= (const std::complex<double>& z);
    complex_vector operator += (const std::complex<double>& z);
    complex_vector operator -= (const std::complex<double>& z);

    // lin alg stuff
    complex_vector operator + (const complex_vector& cv) const;
    complex_vector operator - (const complex_vector& cv) const;

    complex_vector operator += (const complex_vector& cv);
    complex_vector operator -= (const complex_vector& cv);

    // these are also element-wise stuff
    complex_vector operator * (const complex_vector& cv) const;
    complex_vector operator / (const complex_vector& cv) const;
    complex_vector operator *= (const complex_vector& cv);
    complex_vector operator /= (const complex_vector& cv);

    complex_vector conj() const;
    complex_vector square() const;
    std::complex<double> sum() const;
    std::complex<double> prod() const;
    
    // static stuff
    static std::complex<double> dot(const complex_vector& u, const complex_vector& v);
    
    static complex_vector exp(const complex_vector& cv);
    static complex_vector log(const complex_vector& cv);
    static complex_vector sqrt(const complex_vector& cv);
    
    static complex_vector pow(const std::complex<double> z, const complex_vector& cv);
    static complex_vector pow(const complex_vector& cv, const std::complex<double> z);
    static complex_vector pow(const complex_vector& u, const complex_vector& v);

private:
    complex_vector();
    

    std::complex<double>* _v;
    unsigned long _dim;
};

/*
 * some operators to make life easier
 */
inline complex_vector operator+ (const double d, const complex_vector& cv) {
    return cv + d;
}

inline complex_vector operator- (const double d, const complex_vector& cv) {
    return -(cv - d);
}

inline complex_vector operator* (const double d, const complex_vector& cv) {
    return cv * d;
}

inline complex_vector operator+ (const std::complex<double> z, const complex_vector& cv) {
    return cv + z;
}

inline complex_vector operator- (const std::complex<double> z, const complex_vector& cv) {
    return -(cv - z);
}

inline complex_vector operator* (const std::complex<double> z, const complex_vector& cv) {
    return cv * z;
}



