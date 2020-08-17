
#pragma once


#include "cvec.hpp"
#include "utils.hpp"

using consts::pi;

namespace fft {

    complex_vector fft(const complex_vector& cv);
    complex_vector ifft(const complex_vector& cv);

}