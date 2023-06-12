#ifndef mm_jki_HPP
#define mm_jki_HPP

#include <iostream>
#include <vector>

//level 3 BLAS
template <typename T>
 void mm_jki(T a , const std::vector<T> &A,
const std::vector<T> &B , T b , std::vector<T> &C, int m, int p, int n);


#endif //mm_jki_HPP