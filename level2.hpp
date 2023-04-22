#ifndef level2_HPP
#define level2_HPP

#include <iostream>
#include <vector>

//level 2 BLAS
 template <typename T>
 void gemv(T a , const std::vector<std::vector<T>> &A,
const std::vector<T> &x , T b , std::vector<T> &y );

#endif //level2_HPP