
#include <iostream>
#include <complex>
#include <vector>
#include <cstdlib>
#include <ctime>
typedef std::complex<double> dcompx;
constexpr dcompx I{0.0, 1.0};

typedef std::vector<std::vector<double> > dMatrix;
typedef std::vector<std::vector<dcompx> > dcMatrix;


#include "Matrix/matrix.hpp"
#include "strassen_algorithm.hpp"


int main(){

    int M = 70; // matrix size NOTE: it must be even number
    if (M%2!=0)M=M+1;
    int seed = 11;// time(NULL);
    dMatrix A;
    A = Matrix::Make_matrix(A, M);
    Matrix::fill_in_random(A, seed);
    std::cout << "\n print: A \n";
    Matrix::print_matrix(A);

    dMatrix B;
    dMatrix C;
    dMatrix C2;
    
    B = Matrix::Make_matrix(B, M);
    Matrix::fill_in_random(B, seed);
    std::cout << "\n print: B \n";
    Matrix::print_matrix(B);
    
    C = Matrix::Make_matrix(C, M);
    C2 = Matrix::Make_matrix(C2, M);

    C = Strassen::Multiplication(A,B); //Linear Matrix Multiplication

    std::cout << "\n print: C = A*B \n";
    Matrix::print_matrix(C);
    
    C2 = Matrix::Multiplication(A,B); //Linear Matrix Multiplication
    std::cout << "\n print: C2=A*B \n";
    Matrix::print_matrix(C2);

    A.clear(); B.clear(); C.clear();
    

    
    
    
    
    
    
    
    
    
    

    return 0;
}
