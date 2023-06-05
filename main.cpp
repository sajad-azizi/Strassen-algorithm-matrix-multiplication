
#include <iostream>
#include <complex>

#include "Matrix/matrix.hpp"
typedef std::complex<double> dcompx;
constexpr dcompx I{0.0, 1.0};

int main(){

    std::cout << Matrix::msqrt(2.0*I+1.0) << std::endl;

    return 0;
}
