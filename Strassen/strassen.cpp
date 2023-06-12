#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include "strassen_header.hpp"
using namespace std;

int main() {
    //create the output file before calculating
    std::string filename = "strassen.csv"; //change file name for each test run
    std::ofstream myfile(filename);
    //random number generator
    std::mt19937_64 rnd;
    std::uniform_real_distribution<float> doubleDist(0,2);
        for (int n = 2; n < 512; n+=2){
        double len = n;
        long double durTot = 0.0;
        long double MFLOP = 0.0;
        //fill matrices with random numbers
            std::vector<std::vector<double>> A(n, std::vector<double>(n)); 
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    A[i][j] = doubleDist(rnd);
                }
            }
            std::vector<std::vector<double>> B(n, std::vector<double>(n)); 
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    B[i][j] = doubleDist(rnd);
                }
            }

        for (int ntrial = 0; ntrial<3; ntrial++){  
            auto start = std::chrono::high_resolution_clock::now(); //start clock
            strassen_mm(A,B);  //run BLAS 
            auto stop = std::chrono::high_resolution_clock::now();//stop clock
            //calc the duration of the code segment
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
            durTot += duration.count();  
            //calculate performance 
            }
        MFLOP = ((7/4)*len*len*len +(9/2)*len*len)/(durTot*1e-9)/1e6; 
        myfile << std::to_string(MFLOP) << std::endl;//save the calculation in the output file 
        }
        myfile.close();

        return 0;
}