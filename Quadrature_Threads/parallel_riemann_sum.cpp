#include "parallel_riemann_sum.hpp"
#include "compute_partial_sum.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

double parallel_riemann_sum(double a, double b, int n, int num_threads){

    double h = (b-a)/n;
    double sum = 0.0;
    std::vector<std::thread> threads(num_threads);

    //Mutex for protecting the sum value
    std::mutex sum_mutex; 

    //spawn threads to compute the sums
    for (int i=0; i<num_threads; ++i){
        threads[i] = std::thread(compute_partial_sum, std::ref(sum), std::ref(sum_mutex), a, h, n, num_threads, i);
    }

    //wait for threads to finish
    for (int i=0; i<num_threads; ++i){
        threads[i].join();
    }

    return sum; 
}


