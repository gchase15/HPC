#ifndef strassen_HPP
#define strassen_HPP

#include <iostream>
#include <vector>

//level 3 BLAS
template <typename T>
 std::vector<std::vector<T>> strassen_mm(const std::vector<std::vector<T>> &A,
const std::vector<std::vector<T>> &B);//vector<vector<double>>C=strassen_mm(A,B);


#endif //strassen_HPP