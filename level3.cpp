#include "level3.hpp"
#include <iostream>
#include <vector>

//level 3 BLAS
template <typename T>
 void gemm(T a , const std::vector<std::vector<T>> &A,
const std::vector<std::vector<T>> &B , T b , std::vector<std::vector<T>> &C )
{
    if (C.size() != C[0].size())//check to make sure result is square
        {
        std::cerr << "Matrix multiplication not possible" << std::endl;
    }

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B[0].size(); j++)
        {
            double sum = 0;
            for (int k = 0; k < B.size(); k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = a*sum + b*C[i][j]; 
        }
    }
};

 template void gemm(int a , const std::vector<std::vector<int>> &A,
const std::vector<std::vector<int>> &B , int b , std::vector<std::vector<int>> &C );
 template void gemm(float a , const std::vector<std::vector<float>> &A,
const std::vector<std::vector<float>> &B , float b , std::vector<std::vector<float>> &C );
 template void gemm(double a , const std::vector<std::vector<double>> &A,
const std::vector<std::vector<double>> &B , double b , std::vector<std::vector<double>> &C );