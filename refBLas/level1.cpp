#include "level1.hpp"
#include <iostream>
#include <vector>

//level 1 BLAS
template <typename T>
void axpy(T a, const std::vector<T> &x, std::vector<T> &y)
{ 
    if (x.size() != y.size())//check to make sure vectors are equal size
    {
        std::cerr << "Error: vectors have different sizes" << std::endl;
    }
    //perform level 1 BLAS
    for (int i = 0; i < x.size(); i++) { 
        y[i] = a*x[i]+y[i]; 
        }

 }

 template void axpy(int a, const std::vector<int> &x, std::vector<int> &y);
 template void axpy(float a, const std::vector<float> &x, std::vector<float> &y);
 template void axpy(double a, const std::vector<double> &x, std::vector<double> &y);