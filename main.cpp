
#include <iostream>
#include <complex>
#include <vector>
#include <cstdlib>
#include <ctime>
typedef std::complex<double> dcompx;
constexpr dcompx I{0.0, 1.0};


#include "Matrix/matrix.hpp"


int main(){

    //std::cout << Matrix::msqrt(2.0*I+1.0) << std::endl;
    
    const int M = 2; // matrix size
    int seed = time(NULL);
    std::vector< std::vector<dcompx> > A;
    Matrix::Make_matrix(A, M);
    Matrix::fill_in_random_complex(A, seed);
    Matrix::print_matrix(A);
    
    std::vector< std::vector<dcompx> > B;Matrix::Make_matrix(B, M);
    std::vector< std::vector<dcompx> > C;Matrix::Make_matrix(C, M);
    
    C = Matrix::Add(A,B);
    
    Matrix::print_matrix(C);
    
    A.clear();

    return 0;
}
