
#include "fft.h"
#include "utils.h"

using consts::pi;

// private helper funcs
namespace fft {
    unsigned long bit_reverse(unsigned long x, unsigned int log2n) {
        unsigned long n = 0;
        
        for (unsigned int i = 0; i < log2n; ++i) {
            n <<= 1;
            n |= (x & 1);
            x >>= 1;
        }

        return n;
    }

    complex_vector fft_func(const complex_vector& cv) {
        // assume length is a power of 2
        unsigned long len = cv.length();
        complex_vector fv(len);
        unsigned int log2n = std::log2(len);

        std::complex<double> i(0, 1);

        // unsigned int n = 1 << log2n;
                
        for (unsigned long k = 0; k < len; ++k) {
            fv[bit_reverse(k, log2n)] = cv[k];
        }

        for (unsigned int s = 1; s <= log2n; ++s) {
            unsigned long m = 1 << s;
            unsigned long m2 = m >> 1;

            std::complex<double> w(1, 0);
            std::complex<double> wm = std::exp(std::complex<double>(0, -pi / m2));

            for (unsigned long j = 0; j < m2; ++j) {
                for (unsigned long k = j; k < len; k += m) {
                    std::complex<double> t = w * fv[k + m2];
                    std::complex<double> u = fv[k];
                    fv[k] = u + t;
                    fv[k + m2] = u - t;

                }

                w *= wm;
            }

        }

        return fv;
 
    }   

}


/**
 * compute a discrete fourier transform of a complex sequence. at the 
 * moment requires that the length of the sequence is a power of 2. 
 */
complex_vector fft::fft(const complex_vector& cv) {
    unsigned long len = cv.length();
    unsigned long loglen = std::log2(len);

    if (std::pow(2, loglen) == len) {
        return fft_func(cv);
    }

    // dunno, return zeros
    complex_vector fv(len);
    
    return fv;
}

complex_vector fft::ifft(const complex_vector& cv) {
    unsigned long len = cv.length();
    complex_vector reversed(len);

    for (unsigned long k = 0; k < len - 1; ++k) {
        reversed[k + 1] = cv[len - k - 1];
    }
    reversed[0] = cv[0];

    double dlen = len;
    return fft_func(reversed) / dlen;
}