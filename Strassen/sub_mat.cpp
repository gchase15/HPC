#include "sub_mat.hpp"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
 vector<vector<T>> sub_mat(const vector<vector<T>> &A,
const vector<vector<T>> &B)//vector<vector<double>>C=strassen_mm(A,B);
{
vector<vector<T>> C(A.size(), vector<T>(A[0].size()));
for (int i=0; i<A.size(); i++)
    {
        for (int j=0; j<A[0].size(); j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
return C;
}

 template vector<vector<int>> sub_mat(const vector<vector<int>> &A,
const vector<vector<int>> &B);
 template vector<vector<float>> sub_mat(const vector<vector<float>> &A,
const vector<vector<float>> &B);
 template vector<vector<double>> sub_mat(const vector<vector<double>> &A,
const vector<vector<double>> &B);