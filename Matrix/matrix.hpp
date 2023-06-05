#include <cmath>

namespace Matrix{
    
    template<typename T> 
    T msqrt(T arg){
        return std::sqrt(arg);
    }
    
    template<typename T> 
    std::vector<std::vector<T> > Make_matrix(std::vector<std::vector<T> > &matrix, const int size_){
        matrix.resize(size_);
        for(int i = 0; i < size_; i++){
            matrix[i].resize(size_);
        }
        return matrix;
    }
    
    template<typename T> 
     void fill_in_random(std::vector<std::vector<T> > &matrix, int seed_value){
         
         srand (static_cast <unsigned> (seed_value) );
         
         for(int i = 0; i < matrix.size(); i++){
             for(int j = 0; j < matrix.size(); j++){
                 
                 // between [0,1]
                 double r1 = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
                 matrix[i][j] = r1;
            }
        }
     }
     
     template<typename T> 
     void fill_in_random_complex(std::vector<std::vector<T> > &matrix, int seed_value){
         
         srand (static_cast <unsigned> (seed_value) );
         
         for(int i = 0; i < matrix.size(); i++){
             for(int j = 0; j < matrix.size(); j++){
                 
                 // between [0,1]
                 double r1 = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
                 double r2 = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
                 
                 matrix[i][j] = r1 + I*double(r2);
            }
        }
    }
    
    template<typename T> 
    void print_matrix(std::vector<std::vector<T> > &matrix){
        // Prints ' ' if j != n-1 else prints '\n' where n = matrix.size()
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){        
                std::cout << matrix[i][j] << " \n"[j == matrix.size()-1];
            }
        }
    }
    
    template<typename T> 
     std::vector<std::vector<T> > Add(std::vector<std::vector<T> > &A, std::vector<std::vector<T> > &B){
         
         std::vector<std::vector<T> > C;
         for(int i = 0; i < A.size(); i++){
             for(int j = 0; j < A.size(); j++){
                 
                 C[i][j] = A[i][j] + B[i][j];
            }
        }
        return C;
        
     }
     
    template<typename T> 
     std::vector<std::vector<T> > Subtract(std::vector<std::vector<T> > &A, std::vector<std::vector<T> > &B){
         
         std::vector<std::vector<T> > C;
         for(int i = 0; i < A.size(); i++){
             for(int j = 0; j < A.size(); j++){
                 
                 C[i][j] = A[i][j] - B[i][j];
            }
        }
        return C;
        
     }
    
    
    
    
    
}
