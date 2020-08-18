
#pragma once

#include "cvec.h"
#include "utils.h"

namespace fft {

// Compute a discrete fourier transform of a complex sequence. At the moment 
// the implementation requires that the length of the sequence is a power of 
// 2. 
complex_vector fft(const complex_vector& cv);

// Compute the inverse DFT using the forward FFT. In other words, this also 
// requires that the length of the input is a power of 2.
complex_vector ifft(const complex_vector& cv);

} // namespace fft