#include "mm_kij.hpp"
#include <iostream>
#include <vector>

//level 3 BLAS_ijk
template <typename T>
 void mm_kij(T a , const std::vector<T> &A,
const std::vector<T> &B , T b , std::vector<T> &C, int m, int p, int n)
{
    if (m != n)//check to make sure result is square
        {
        std::cerr << "Matrix multiplication not possible" << std::endl;
    }

    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < p; j++)
            {
            sum += A[j*m+k]*B[i*p+j]; 
            
            }
            C[i*m+k] = a*sum + b*C[i*m+k];
            }
        }

};

 template void mm_kij(int a , const std::vector<int> &A,
const std::vector<int> &B , int b , std::vector<int> &C, int m, int p, int n);
 template void mm_kij(float a , const std::vector<float> &A,
const std::vector<float> &B , float b , std::vector<float> &C, int m, int p, int n);
 template void mm_kij(double a , const std::vector<double> &A,
const std::vector<double> &B , double b , std::vector<double> &C, int m, int p, int n);