#include <cmath>

namespace Strassen{
    
    
    template<typename T>
    std::vector<std::vector<T> > Multiplication(std::vector<std::vector<T> > &A, std::vector<std::vector<T> > &B){
        
        std::vector<std::vector<T> > C;
        C = Matrix::Make_matrix(C, A.size());
        
        const int N = A.size()/2;
        
        std::vector< std::vector<T> > A11; A11 = Matrix::Make_matrix(A11, N);
        std::vector< std::vector<T> > A12; A12 = Matrix::Make_matrix(A12, N);
        std::vector< std::vector<T> > A21; A21 = Matrix::Make_matrix(A21, N);
        std::vector< std::vector<T> > A22; A22 = Matrix::Make_matrix(A22, N);
        
        std::vector< std::vector<T> > B11; B11 = Matrix::Make_matrix(B11, N);
        std::vector< std::vector<T> > B12; B12 = Matrix::Make_matrix(B12, N);
        std::vector< std::vector<T> > B21; B21 = Matrix::Make_matrix(B21, N);
        std::vector< std::vector<T> > B22; B22 = Matrix::Make_matrix(B22, N);
        
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][N+j];
                A21[i][j] = A[N+i][j];
                A22[i][j] = A[N+i][N+j];
                
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][N+j];
                B21[i][j] = B[N+i][j];
                B22[i][j] = B[N+i][N+j];
                
            }
        }
        
        std::vector< std::vector<T> > S1; S1 = Matrix::Make_matrix(S1, N);
        std::vector< std::vector<T> > S2; S2 = Matrix::Make_matrix(S2, N);
        std::vector< std::vector<T> > S3; S3 = Matrix::Make_matrix(S3, N);
        std::vector< std::vector<T> > S4; S4 = Matrix::Make_matrix(S4, N);
        std::vector< std::vector<T> > S5; S5 = Matrix::Make_matrix(S5, N);
        std::vector< std::vector<T> > S6; S6 = Matrix::Make_matrix(S6, N);
        std::vector< std::vector<T> > S7; S7 = Matrix::Make_matrix(S7, N);
        std::vector< std::vector<T> > S8; S8 = Matrix::Make_matrix(S8, N);
        std::vector< std::vector<T> > S9; S9 = Matrix::Make_matrix(S9, N);
        std::vector< std::vector<T> > S10; S10 = Matrix::Make_matrix(S10, N);
        
        S1 = Matrix::Add(A11,A22);
        S2 = Matrix::Add(B11,B22);
        S3 = Matrix::Add(A21,A22);
        S4 = Matrix::Subtract(B12,B22);
        S5 = Matrix::Subtract(B21,B11);
        S6 = Matrix::Add(A11,A12);
        S7 = Matrix::Subtract(A21,A11);
        S8 = Matrix::Add(B11,B12);
        S9 = Matrix::Subtract(A12,A22);
        S10 = Matrix::Add(B21,B22);
        
        std::vector< std::vector<T> > M1; M1 = Matrix::Make_matrix(M1, N);
        std::vector< std::vector<T> > M2; M2 = Matrix::Make_matrix(M2, N);
        std::vector< std::vector<T> > M3; M3 = Matrix::Make_matrix(M3, N);
        std::vector< std::vector<T> > M4; M4 = Matrix::Make_matrix(M4, N);
        std::vector< std::vector<T> > M5; M5 = Matrix::Make_matrix(M5, N);
        std::vector< std::vector<T> > M6; M6 = Matrix::Make_matrix(M6, N);
        std::vector< std::vector<T> > M7; M7 = Matrix::Make_matrix(M7, N);
        
        M1 = Matrix::Multiplication(S1,S2);
        M2 = Matrix::Multiplication(S3,B11);
        M3 = Matrix::Multiplication(A11,S4);
        M4 = Matrix::Multiplication(A22,S5);
        M5 = Matrix::Multiplication(S6,B22);
        M6 = Matrix::Multiplication(S7,S8);
        M7 = Matrix::Multiplication(S9,S10);
        
        A11.clear();A12.clear();A21.clear();A22.clear();
        B11.clear();B12.clear();B21.clear();B22.clear();
        
        S1.clear();S2.clear();S3.clear();S4.clear();S5.clear();S6.clear();S7.clear();S8.clear();S9.clear();S10.clear();

       
        std::vector< std::vector<T> > P1; P1 = Matrix::Make_matrix(P1, N);
        std::vector< std::vector<T> > P2; P2 = Matrix::Make_matrix(P2, N);
        std::vector< std::vector<T> > P5; P5 = Matrix::Make_matrix(P5, N);
        std::vector< std::vector<T> > P6; P6 = Matrix::Make_matrix(P6, N);
        
        P1 = Matrix::Add(M1,M4);
        P2 = Matrix::Subtract(M7,M5);
        P5 = Matrix::Subtract(M1,M2);
        P6 = Matrix::Add(M3,M6);
        
        std::vector< std::vector<T> > C11; C11 = Matrix::Make_matrix(C11, N);
        std::vector< std::vector<T> > C12; C12 = Matrix::Make_matrix(C12, N);
        std::vector< std::vector<T> > C21; C21 = Matrix::Make_matrix(C21, N);
        std::vector< std::vector<T> > C22; C22 = Matrix::Make_matrix(C22, N);
        
        C11 = Matrix::Add(P1,P2);
        C12 = Matrix::Add(M3,M5);
        C21 = Matrix::Add(M2,M4);
        C22 = Matrix::Add(P5,P6);
        M1.clear();M2.clear();M3.clear();M4.clear();M5.clear();M6.clear();M7.clear();
        P1.clear();P2.clear();P5.clear();P6.clear();
        
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                C[i][j] = C11[i][j];
                C[i][N+j] = C12[i][j];
                C[N+i][j] = C21[i][j];
                C[N+i][N+j] = C22[i][j];
            }
        }
        
        
//         std::cout << "print: C11 \n";
//         Matrix::print_matrix(C11);
//         std::cout << "print: C12 \n";
//         Matrix::print_matrix(C12);
//         std::cout << "print: C21 \n";
//         Matrix::print_matrix(C21);
//         std::cout << "print: C22 \n";
//         Matrix::print_matrix(C22);
        
        //std::cout << "print: C \n";
        //Matrix::print_matrix(C);
        
        return C;
    }
    
    
    

    
}
