#include "compute_partial_sum.hpp"
#include "f.hpp"
#include <mutex>

void compute_partial_sum(double &sum, std::mutex &sum_mutex, double a, double h, int n, int num_threads, int i){
    double partial_sum = 0.0;
    int start = (n/num_threads)*i;
    int end = (i == num_threads -1) ? n : (n/num_threads)*(i+1);
    for(int j = start; j<end; ++j){
        double x = a+j*h;
        partial_sum += f(x);
    }
    partial_sum *= h;

    //lock the mutex and update the sum variable
    sum_mutex.lock();
    sum += partial_sum;
    sum_mutex.unlock();
}