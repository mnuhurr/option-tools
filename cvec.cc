
#include <cmath>
#include "cvec.h"


complex_vector::complex_vector(const unsigned long& dim) : _dim(dim) {
    _v = new std::complex<double>[_dim];

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] = 0;
    }
}

complex_vector::complex_vector(const std::vector<std::complex<double>> cv) {
    _dim = cv.size();
    _v = new std::complex<double>[_dim];

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] = cv[k];
    }   
}

complex_vector::complex_vector(const std::vector<double> dv) {
    _dim = dv.size();
    _v = new std::complex<double>[_dim];

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] = dv[k];
    }   
}

complex_vector::~complex_vector() {
    if (_v) {
        delete[] _v;
    }
}

complex_vector complex_vector::operator= (const complex_vector& cv) {
    if (_v) {
        delete[] _v;
    }

    _dim = cv._dim;
    _v = new std::complex<double>[_dim];
    
    complex_vector w(_dim);
    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] = cv._v[k];
        w._v[k] = _v[k];
    }

    return w;
}

complex_vector::complex_vector(const complex_vector& v) : _dim(v._dim) {
    _v = new std::complex<double>[_dim];

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] = v._v[k];
    }
}

unsigned long complex_vector::length() const {
    return _dim;
}


double complex_vector::norm() const {
    double n = 0;

    for (unsigned long k = 0; k < _dim; ++k) {
        n += _v[k].real() * _v[k].real() + _v[k].imag() * _v[k].imag();
    }

    return std::sqrt(n);
}

// element access
std::complex<double> complex_vector::operator[] (const unsigned long& i) const {
    return _v[i];
}

std::complex<double>& complex_vector::operator[] (const unsigned long& i) {
    return _v[i];
}

// negate
complex_vector complex_vector::operator- () const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = -_v[k];
    }
    return w;
}

// scalars
complex_vector complex_vector::operator* (const double& d) const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] * d;
    }

    return w;
}

complex_vector complex_vector::operator/ (const double& d) const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] / d;
    }

    return w;
}

complex_vector complex_vector::operator+ (const double& d) const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] + d;
    }

    return w;
}

complex_vector complex_vector::operator- (const double& d) const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] - d;
    }

    return w;
}


complex_vector complex_vector::operator* (const std::complex<double>& z) const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] * z;
    }

    return w;    
}

complex_vector complex_vector::operator/ (const std::complex<double>& z) const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] / z;
    }

    return w;    
}

complex_vector complex_vector::operator+ (const std::complex<double>& z) const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] + z;
    }

    return w;    
}

complex_vector complex_vector::operator- (const std::complex<double>& z) const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] - z;
    }

    return w;    
}

complex_vector complex_vector::operator*= (const double& d) {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] *= d;
        w._v[k] = _v[k];
    }

    return w;
}

complex_vector complex_vector::operator/= (const double& d) {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] /= d;
        w._v[k] = _v[k];
    }

    return w;
}

complex_vector complex_vector::operator+= (const double& d) {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] += d;
        w._v[k] = _v[k];
    }

    return w;
}

complex_vector complex_vector::operator-= (const double& d) {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] -= d;
        w._v[k] = _v[k];
    }

    return w;
}

complex_vector complex_vector::operator*= (const std::complex<double>& z) {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] *= z;
        w._v[k] = _v[k];
    }

    return w;
}

complex_vector complex_vector::operator/= (const std::complex<double>& z) {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] /= z;
        w._v[k] = _v[k];
    }

    return w;
}

complex_vector complex_vector::operator+= (const std::complex<double>& z) {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] += z;
        w._v[k] = _v[k];
    }

    return w;
}

complex_vector complex_vector::operator-= (const std::complex<double>& z) {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] -= z;
        w._v[k] = _v[k];
    }

    return w;
}




// linalg stuff
complex_vector complex_vector::operator + (const complex_vector& cv) const {
    complex_vector w(_dim);

    if (_dim != cv._dim) {
        throw "dimension mismatch";
    }

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] + cv._v[k];
    }

    return w;    
}

complex_vector complex_vector::operator - (const complex_vector& cv) const {
    complex_vector w(_dim);

    if (_dim != cv._dim) {
        throw "dimension mismatch";
    }

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] - cv._v[k];
    }

    return w;    
}

complex_vector complex_vector::operator += (const complex_vector& cv) {
    complex_vector w(_dim);

    if (_dim != cv._dim) {
        throw "dimension mismatch";
    }

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] += cv._v[k];
        w._v[k] = _v[k];
    }

    return w;    
}

complex_vector complex_vector::operator -= (const complex_vector& cv) {
    complex_vector w(_dim);

    if (_dim != cv._dim) {
        throw "dimension mismatch";
    }

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] += cv._v[k];
        w._v[k] = _v[k];
    }

    return w;    
}

// element-wise stuff
complex_vector complex_vector::operator * (const complex_vector& cv) const {
    complex_vector w(_dim);

    if (_dim != cv._dim) {
        throw "dimension mismatch";
    }

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] * cv._v[k];
    }

    return w;    
}

complex_vector complex_vector::operator / (const complex_vector& cv) const {
    complex_vector w(_dim);

    if (_dim != cv._dim) {
        throw "dimension mismatch";
    }

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] / cv._v[k];
    }

    return w;    
}

complex_vector complex_vector::operator *= (const complex_vector& cv) {
    complex_vector w(_dim);

    if (_dim != cv._dim) {
        throw "dimension mismatch";
    }

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] *= cv._v[k];
        w._v[k] = _v[k];
    }

    return w;    
}

complex_vector complex_vector::operator /= (const complex_vector& cv) {
    complex_vector w(_dim);

    if (_dim != cv._dim) {
        throw "dimension mismatch";
    }

    for (unsigned long k = 0; k < _dim; ++k) {
        _v[k] /= cv._v[k];
        w._v[k] = _v[k];
    }

    return w;    
}



complex_vector complex_vector::conj() const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = std::conj(_v[k]);
    }

    return w;
}


complex_vector complex_vector::square() const {
    complex_vector w(_dim);

    for (unsigned long k = 0; k < _dim; ++k) {
        w._v[k] = _v[k] * _v[k];
    }

    return w;
}

std::complex<double> complex_vector::sum() const {
    
    std::complex<double> s(0, 0);

    for (unsigned long k = 0; k < _dim; ++k) {
        s +=_v[k];
    }

    return s;
}

std::complex<double> complex_vector::prod() const {
    
    std::complex<double> s(0, 0);

    for (unsigned long k = 0; k < _dim; ++k) {
        s *=_v[k];
    }

    return s;
}


// statics
std::complex<double> complex_vector::dot(const complex_vector& u, const complex_vector& v) {
    if (u._dim != v._dim) {
        throw "dimension mismatch";
    }

    std::complex<double> dp(0, 0);

    for (unsigned long k = 0; k < v._dim; ++k) {
        dp += v._v[k] * u._v[k];
    }

    return dp;
}


complex_vector complex_vector::sqrt(const complex_vector& cv) {
    complex_vector w(cv._dim);

    for (unsigned long k = 0; k < cv._dim; ++k) {
        w._v[k] = std::sqrt(cv._v[k]);
    }

    return w;
}


complex_vector complex_vector::exp(const complex_vector& cv) {
    complex_vector w(cv._dim);

    for (unsigned long k = 0; k < cv._dim; ++k) {
        w._v[k] = std::exp(cv._v[k]);
    }

    return w;
}

complex_vector complex_vector::log(const complex_vector& cv) {
    complex_vector w(cv._dim);

    for (unsigned long k = 0; k < cv._dim; ++k) {
        w._v[k] = std::log(cv._v[k]);
    }

    return w;
}

complex_vector complex_vector::pow(const std::complex<double> z, const complex_vector& cv) {
    complex_vector w(cv._dim);

    for (unsigned long k = 0; k < cv._dim; ++k) {
        w._v[k] = std::pow(z, cv._v[k]);
    } 

    return w;
}

complex_vector complex_vector::pow(const complex_vector& cv, const std::complex<double> z) {
    complex_vector w(cv._dim);

    for (unsigned long k = 0; k < cv._dim; ++k) {
        w._v[k] = std::pow(cv._v[k], z);
    } 
    
    return w;

}

complex_vector complex_vector::pow(const complex_vector& u, const complex_vector& v) {
    if (u._dim != v._dim) {
        throw "dimension mismatch";
    }

    complex_vector w(u._dim);

    for (unsigned long k = 0; k < u._dim; ++k) {
        w._v[k] = std::pow(u._v[k], v._v[k]);
    } 
    
    return w;
}
