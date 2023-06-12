#include "level2.hpp"
#include <iostream>
#include <vector>



//level 2 BLAS
 template <typename T>
void gemv(T a , const std::vector<std::vector<T>> &A,
const std::vector<T> &x , T b , std::vector<T> &y )
{
    if (x.size() != y.size())//check to make sure vectors are equal size
        {
        std::cerr << "Matrix is not square" << std::endl;
    }
    double c = 0.0;
    for (int i = 0; i < x.size(); i++) {
        c = 0.0;
        for(int j = 0; j < x.size(); j++){
            c += A[i][j]*x[j];
                }
        y[i] = a*c + b*y[i]; 
        }   
};

template void gemv(int a , const std::vector<std::vector<int>> &A,
const std::vector<int> &x , int b , std::vector<int> &y );
template void gemv(float a , const std::vector<std::vector<float>> &A,
const std::vector<float> &x , float b , std::vector<float> &y );
template void gemv(double a , const std::vector<std::vector<double>> &A,
const std::vector<double> &x , double b , std::vector<double> &y );