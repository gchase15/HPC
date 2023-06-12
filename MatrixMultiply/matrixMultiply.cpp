#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include "mm_header.hpp"

int main() {
    //create the output file before calculating
    std::string filename = "outputjkiO3.csv"; //change file name for each test run
    std::ofstream myfile(filename);
    //random number generator
    std::mt19937_64 rnd;
    std::uniform_real_distribution<float> doubleDist(0,1);
    float a = doubleDist(rnd); //create alpha
    float b = doubleDist(rnd);//create beta
    int m = 0;
    int p = 0;
        for (int n = 2; n < 512; n++){
        double len = n;
        m = n;
        p = n;
        long double durTot = 0.0;
        long double MFLOP = 0.0;
        //fill matrices with random numbers
        std::vector<float> A(m*p); 
        for(int i = 0; i <= A.size(); i++){
            A[i] = doubleDist(rnd);
            }
        std::vector<float> B(p*n); 
        for(int i = 0; i <= B.size(); i++){
            B[i] = doubleDist(rnd);
            }
        std::vector<float> C(m*n); 
        for(int i = 0; i <= C.size(); i++){
            C[i] = doubleDist(rnd);
            }
        for (int ntrial = 0; ntrial<3; ntrial++){  
            auto start = std::chrono::high_resolution_clock::now(); //start clock
            mm_jki(a, A, B, b, C, m, p, n);  //run BLAS 
            auto stop = std::chrono::high_resolution_clock::now();//stop clock
            //calc the duration of the code segment
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
            durTot += duration.count();  
            //calculate performance 
            }
        MFLOP = 6*(len*len*len+len*len)/(durTot*1e-9)/1e6; 
        myfile << std::to_string(MFLOP) << std::endl;//save the calculation in the output file 
        }
        myfile.close();

        return 0;
}