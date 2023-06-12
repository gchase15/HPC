#include <iostream>
#include <fstream>
#include <vector>

void writeMatrixToFile(const std::vector<double>& matrix, int numRows, int numCols, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    for (int col = 0; col < numCols; ++col) {
        for (int row = 0; row < numRows; ++row) {
            file.write(reinterpret_cast<const char*>(&matrix[row + col * numRows]), sizeof(double));
        }
    }

    file.close();
}

void swapRowsInFile(std::fstream&file, int nRows , int nCols , int i , int j ){
    std::vector<double> firstRow(nRows);
    int index = 0;
    for (int k = 0; k < nCols; k++){
        //point to a number in the ith row
        index = k*nCols+i;
        file.seekg(sizeof(double)*index);
        //read ith row element into temp space
        file.read(reinterpret_cast<char*>(&firstRow[k]), sizeof(double));
        //read jth row element into ith row spot
        file.seekg(sizeof(double)*(k*nCols+j));
        double quant = 0.0;
        file.read(reinterpret_cast<char*>(&quant), sizeof(double));
        file.seekp(sizeof(double)*index);
        file.write(reinterpret_cast<char*>(&quant), sizeof(double));
        file.seekp(sizeof(double)*(k*nCols+j));
        file.write(reinterpret_cast<char*>(&firstRow[k]), sizeof(double));
}
}

void swapColsInFile(std::fstream &file, int nRows, int nCols, int i, int j){
    std::vector<double> firstCol(nCols);
    int index = 0;
    for (int k = 0; k < nRows; k++){
        //point to a number in the ith col
        index = k+ nRows*i;
        file.seekg(sizeof(double)*index);
        //read ith col element into temp space
        file.read(reinterpret_cast<char*>(&firstCol[k]), sizeof(double));
        //read jth col element into ith col spot
        file.seekg(sizeof(double)*(k+nCols*j));
        double quant = 0.0;
        file.read(reinterpret_cast<char*>(&quant), sizeof(double));
        file.seekp(sizeof(double)*index);
        file.write(reinterpret_cast<char*>(&quant), sizeof(double));
        file.seekp(sizeof(double)*(k+nCols*j));
        file.write(reinterpret_cast<char*>(&firstCol[k]), sizeof(double));
}




}