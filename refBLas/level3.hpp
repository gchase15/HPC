#ifndef level3_HPP
#define level3_HPP

#include <iostream>
#include <vector>

//level 3 BLAS
template <typename T>
 void gemm(T a , const std::vector<std::vector<T>> &A,
const std::vector<std::vector<T>> &B , T b , std::vector<std::vector<T>> &C );


#endif //level3_HPP