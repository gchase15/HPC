#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include "refBlas.hpp"

int main() {
    //create the output file before calculating
    std::string filename = "output6a.csv";
    std::ofstream myfile(filename);
    //random number generator
    std::mt19937_64 rnd;
    std::uniform_real_distribution<float> doubleDist(0,1);
    float a = doubleDist(rnd); //create alpha
    float b = doubleDist(rnd);//create beta
        for (int n = 2; n<=1024; n++){
            long double durTot = 0.0;
            long double MFLOP = 0.0;
            for (int ntrial = 0; ntrial<50; ntrial++){
            std::vector<float> x(n);//vector creation
            std::vector<float> y(n);


            //fill vectors with random numbers
            for (int i = 0; i < x.size(); i++) {
                x[i] = doubleDist(rnd); 
                y[i] = doubleDist(rnd); 
                }

            auto start = std::chrono::high_resolution_clock::now(); //start clock
            

            axpy(a, x, y);  //run BLAS 

            auto stop = std::chrono::high_resolution_clock::now();//stop clock
            //calc the duration of the code segment
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
            durTot += duration.count();  
            //calculate performance 
            MFLOP = 2*(ntrial+1)*n/(durTot*1e-9)/1e6;        
    }
            myfile << std::to_string(MFLOP) << std::endl;//save the calculation in the output file
    }
    myfile.close();


    std::string filename1 = "output6b.csv";
    std::ofstream myfile1(filename1);
    for (int n = 2; n<=10; n++){
        int m = n;
        std::vector<float> x(n);//vector creation
        std::vector<float> y(m);
        long double durTot = 0.0;
        long double MFLOP = 0.0;
         for (int ntrial = 0; ntrial<2; ntrial++){
            //fill vectors with random numbers
            for (int i = 0; i < x.size(); i++) {
                x[i] = doubleDist(rnd); 
                y[i] = doubleDist(rnd); 
            }
            std::vector<std::vector<float>> A(n, std::vector<float>(m)); 
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    A[i][j] = doubleDist(rnd);
                }
            }       
            auto start = std::chrono::high_resolution_clock::now(); //start clock
            gemv(a, A, x, b, y);  //run BLAS 
            auto stop = std::chrono::high_resolution_clock::now();//stop clock
            //calc the duration of the code segment
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
            durTot += duration.count();  
            //calculate performance 
        }
        MFLOP = 2*(n*n+n)*3/(durTot*1e-9)/1e6; 
        myfile1 << std::to_string(MFLOP) << std::endl;//save the calculation in the output file 
    }
    myfile1.close();

    //create the output file before calculating
    std::string filename3 = "output6c.csv";
    std::ofstream myfile3(filename3);
 
    for (double n = 2; n<=10; n++){
        int m = n;
        int p = n;
        long double durTot = 0.0;
        long double MFLOP = 0.0;
        //fill matrices with random numbers
        std::vector<std::vector<float>> A(m, std::vector<float>(p)); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < p; j++){
                A[i][j] = doubleDist(rnd);
            }
        }  

        std::vector<std::vector<float>> B(p, std::vector<float>(n)); 
        for(int i = 0; i < p; i++){
            for(int j = 0; j < n; j++){
                B[i][j] = doubleDist(rnd);
            }
        }  

        std::vector<std::vector<float>> C(m, std::vector<float>(n)); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                C[i][j] = doubleDist(rnd);
            }
        } 
        
        for (int ntrial = 0; ntrial<2; ntrial++){  
            auto start = std::chrono::high_resolution_clock::now(); //start clock
            gemm(a, A, B, b, C);  //run BLAS 
            auto stop = std::chrono::high_resolution_clock::now();//stop clock
            //calc the duration of the code segment
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
            durTot += duration.count();  
            //calculate performance 
        }
        MFLOP = 6*(n*n*n+n*n)/(durTot*1e-9)/1e6; 
        myfile3 << std::to_string(MFLOP) << std::endl;//save the calculation in the output file 
    }
    myfile3.close();

    return 0;
}
