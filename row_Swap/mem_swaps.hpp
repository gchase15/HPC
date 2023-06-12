#include <iostream>
#include <vector>

void swapRows(std::vector<double> &matrix, int nRows, int nCols, int i, int j){
    std::vector<double> firstRow(matrix.size());
    for (int k = 0; k < nCols; k++){
        firstRow[k] = matrix[k*nCols+i];
        matrix[k*nCols+i] = matrix[k*nCols +j];
        matrix[k*nCols+j]=firstRow[k];
}
}

void swapCols(std::vector<double> &matrix, int nRows, int nCols, int i, int j){
    std::vector<double> firstCol(matrix.size());
    for (int k = 0; k < nRows; k++){
        firstCol[k] = matrix[k+nRows*i];
        matrix[k+nRows*i] = matrix[k+nRows*j];
        matrix[k+nRows*j]=firstCol[k];
}
}