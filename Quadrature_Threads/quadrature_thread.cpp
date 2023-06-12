#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <chrono>
#include <thread>
#include <math.h>
#include "riemann_sum_header.hpp"

//the derivative of f(x) = ln(x) -x^2/8 is [1/x - x/4]
//analytic answer is 6.41675946923 on the interval [1,6] for L. 


int main(int argc, char *argv[]){

const double a = 1.0;
const double b = 6.0;
const double ans = 6.16675946923; 

if (argc != 3){
    std::cerr << "Not enough arguments. Needs number of partition points and the number of threads, respectively. " << std::endl;
    return 1; 
}

const int n = std::atoi(argv[1]); //partition points
const int num_threads = std::atoi(argv[2]);//thread count

auto start = std::chrono::high_resolution_clock::now(); //start clock
double par_sum = parallel_riemann_sum(a,b,n,num_threads);
auto stop = std::chrono::high_resolution_clock::now();//stop clock
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
long double elapsed_time = (duration.count()*1.e-9);

//std::cout << "the answer is:  " << par_sum << std::endl;
std::cout << "strong scaling efficiency:  " << elapsed_time/num_threads << std::endl;
std::cout << "numerical error of the sum is:  " << abs(ans - par_sum) << std::endl;

    return 0;
}