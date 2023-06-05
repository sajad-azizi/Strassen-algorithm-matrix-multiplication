
#include <iostream>
#include <complex>
#include <vector>
#include <cstdlib>
#include <ctime>
typedef std::complex<double> dcompx;
constexpr dcompx I{0.0, 1.0};


#include "Matrix/matrix.hpp"


int main(){

    const int M = 2; // matrix size
    int seed = 11;// time(NULL);
    std::vector< std::vector<double> > A;
    A = Matrix::Make_matrix(A, M);
    Matrix::fill_in_random(A, seed);
    Matrix::print_matrix(A);

    std::vector< std::vector<double> > B;
    std::vector< std::vector<double> > C;
    
    B = Matrix::Make_matrix(B, M);
    Matrix::fill_in_random(B, seed);
    std::cout << "print: B \n";
    Matrix::print_matrix(B);
    
    C = Matrix::Make_matrix(C, M);

    C = Matrix::Multiplication(A,B); //Linear Matrix Multiplication

    std::cout << "print: C \n";
    Matrix::print_matrix(C);

    A.clear(); B.clear(); C.clear();

    return 0;
}
