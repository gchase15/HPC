#ifndef mm_ikj_HPP
#define mm_ikj_HPP

#include <iostream>
#include <vector>

//level 3 BLAS
template <typename T>
 void mm_ikj(T a , const std::vector<T> &A,
const std::vector<T> &B , T b , std::vector<T> &C, int m, int p, int n);


#endif //mm_ikj_HPP