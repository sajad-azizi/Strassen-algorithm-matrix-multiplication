
#include <iostream>
#include <complex>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
typedef std::complex<double> dcompx;
constexpr dcompx I{0.0, 1.0};

typedef std::vector<std::vector<double> > dMatrix;
typedef std::vector<std::vector<dcompx> > dcMatrix;


#include "Matrix/matrix.hpp"
#include "strassen_algorithm.hpp"


int main(){

    int M = 2; // matrix size NOTE: it must be even number
    if (M%2!=0)M=M+1;
    int seed = 11;// time(NULL);
    
    std::cout << "\nMatrix size :: M*M = " << M*M << std::endl;
    
    dcMatrix A, B, C, C2; //complex
    //dMatrix A, B, C, C2; //real
    
    std::cout << "\nMatrix :: A \n";
    A = Matrix::Make_matrix(A, M);
    Matrix::fill_in_random_complex(A, seed); //complex
    //Matrix::fill_in_random(A, seed); //real
    
    Matrix::print_matrix(A);

    std::cout << "\nMatrix :: B \n";
    B = Matrix::Make_matrix(B, M);
    Matrix::fill_in_random_complex(B, seed); //complex
    //Matrix::fill_in_random(B, seed); //real

    Matrix::print_matrix(B);
    
    std::cout << "\nStrassen Matrix Multiplication :: C = A*B \n";
    C = Matrix::Make_matrix(C, M);
    
    clock_t tStart1 = clock();
    C = Strassen::Multiplication(A,B); //Strassen Matrix Multiplication
    std::cout << "Strassen Matrix Multiplication :: Time taken: " <<  (double)(clock() - tStart1)/CLOCKS_PER_SEC << std::endl;
    
    Matrix::print_matrix(C);
    
    std::cout << "\nLinear Matrix Multiplication :: C2 = A*B \n";
    C2 = Matrix::Make_matrix(C2, M);
    
    clock_t tStart2 = clock();
    C2 = Matrix::Multiplication(A,B); //Linear Matrix Multiplication
    std::cout << "Linear Matrix Multiplication :: Time taken: " <<  (double)(clock() - tStart2)/CLOCKS_PER_SEC << std::endl;
    
    Matrix::print_matrix(C2);

    A.clear(); B.clear(); C.clear();C2.clear();
    
    std::cout << "\nrunning is done! :)"  << std::endl;
    
    /*
    // diff matrix size
    
    std::ofstream fout("data.dat");
    
    for(M = 2; M < 10000; M+=2){
        
        dcMatrix A, B, C, C2; //complex
        //dMatrix A, B, C, C2; //real
        
        A = Matrix::Make_matrix(A, M);
        Matrix::fill_in_random_complex(A, seed); //complex
        //Matrix::fill_in_random(A, seed); //real
        
        B = Matrix::Make_matrix(B, M);
        Matrix::fill_in_random_complex(B, seed); //complex
        //Matrix::fill_in_random(B, seed); //real
        
        C = Matrix::Make_matrix(C, M);
        clock_t tStart1 = clock();
        C = Strassen::Multiplication(A,B); //Strassen Matrix Multiplication
        double tend1 = (double)(clock() - tStart1)/CLOCKS_PER_SEC;
        
        C2 = Matrix::Make_matrix(C2, M);
        clock_t tStart2 = clock();
        C2 = Matrix::Multiplication(A,B); //Linear Matrix Multiplication
        double tend2 = (double)(clock() - tStart2)/CLOCKS_PER_SEC;
        
        std::cout << M << "\t" << M*M << "\t" << tend1 << "\t" << tend2 << std::endl;
        fout << M << "\t" << M*M << "\t" << tend1 << "\t" << tend2 << std::endl;
        
        A.clear(); B.clear(); C.clear();C2.clear();
        
    }
    fout.close();
    
    */
    
    

    return 0;
}
