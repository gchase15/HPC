#include "mm_kji.hpp"
#include <iostream>
#include <vector>

//level 3 BLAS_ijk
template <typename T>
 void mm_kji(T a , const std::vector<T> &A,
const std::vector<T> &B , T b , std::vector<T> &C, int m, int p, int n)
{
    if (m != n)//check to make sure result is square
        {
        std::cerr << "Matrix multiplication not possible" << std::endl;
    }
    std::vector<T> result(m*n, 0.0);
    for (int k = 0; k < m; k++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int i = 0; i < n; i++)
            {
            result[k +i*m] += A[j*m+k]*B[i*p+j];    
            }
            }
        }
    for (int k = 0; k < m; k++)
        {
        for (int i = 0; i < n; i++)
        {
        C[i*m +k] = a*result[i*n+k] + b*C[i*m +k];           
        }
    }
};

 template void mm_kji(int a , const std::vector<int> &A,
const std::vector<int> &B , int b , std::vector<int> &C, int m, int p, int n);
 template void mm_kji(float a , const std::vector<float> &A,
const std::vector<float> &B , float b , std::vector<float> &C, int m, int p, int n);
 template void mm_kji(double a , const std::vector<double> &A,
const std::vector<double> &B , double b , std::vector<double> &C, int m, int p, int n);