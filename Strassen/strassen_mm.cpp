#include "strassen_mm.hpp"
#include "add_mat.hpp"
#include "sub_mat.hpp"
#include <iostream>
#include <vector>
using namespace std;

//strassen matrix multiply
template <typename T>
 vector<vector<T>> strassen_mm(const vector<vector<T>> &A,
const vector<vector<T>> &B)//vector<vector<double>>C=strassen_mm(A,B);
{
//create result
vector<vector<T>> C(A.size(), vector<T>(A.size()));

//if 1x1...escape!!
if(A.size()==1){
    C[0][0] = A[0][0] * B[0][0];
    return C;
}

//create quadrants
int j = A.size()/2;
vector<vector<T>> A11(j,vector<T>(j));
vector<vector<T>> A12(j,vector<T>(j));
vector<vector<T>> A21(j,vector<T>(j));
vector<vector<T>> A22(j,vector<T>(j));
vector<vector<T>> B11(j,vector<T>(j));
vector<vector<T>> B12(j,vector<T>(j));
vector<vector<T>> B21(j,vector<T>(j));
vector<vector<T>> B22(j,vector<T>(j));

//fill quadrants
for(int i=0; i<j; i++){
    for(int k=0; k<j; k++){
        A11[i][k] = A[i][k];
        A12[i][k] = A[i][j+k];
        A21[i][k] = A[i+j][k];
        A22[i][k] = A[i+j][k+j];
        B11[i][k] = B[i][k];
        B12[i][k] = B[i][j+k];
        B21[i][k] = B[i+j][k];
        B22[i][k] = B[i+j][k+j];
    }
}

//do the recursiveness thing
vector<vector<T>> P1 = strassen_mm(add_mat(A11,A22),add_mat(B11,B22));
vector<vector<T>> P2 = strassen_mm(add_mat(A21,A22),B11);
vector<vector<T>> P3 = strassen_mm(A11, sub_mat(B12,B22));
vector<vector<T>> P4 = strassen_mm(A22, sub_mat(B21,B11));
vector<vector<T>> P5 = strassen_mm(add_mat(A11,A12), B22);
vector<vector<T>> P6 = strassen_mm(sub_mat(A21, A11), add_mat(B11, B12));
vector<vector<T>> P7 = strassen_mm(sub_mat(A12,A22), add_mat(B21, B22));

//build the result quadrants
vector<vector<T>> C11 = sub_mat(add_mat(P1,P4),add_mat(P5,P7));
vector<vector<T>> C12 = add_mat(P3,P5);
vector<vector<T>> C21 = add_mat(P2,P4);
vector<vector<T>> C22 = sub_mat(add_mat(P1, P3), add_mat(P2,P6));

//make one big result matrix
for (int i=0; i<j; i++){
    for(int k=0; k<j; k++){
        C[i][j] = C11[i][j];
        C[i][j+k] = C12[i][j];
        C[i+k][j] = C21[i][j];
        C[i+k][j+k] = C22[i][j];
    }
}
return C; 
};

 template std::vector<std::vector<int>> strassen_mm(const std::vector<std::vector<int>> &A,
const std::vector<std::vector<int>> &B);
 template std::vector<std::vector<float>> strassen_mm(const std::vector<std::vector<float>> &A,
const std::vector<std::vector<float>> &B);
 template std::vector<std::vector<double>> strassen_mm(const std::vector<std::vector<double>> &A,
const std::vector<std::vector<double>> &B);

