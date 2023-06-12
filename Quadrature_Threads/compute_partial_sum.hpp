#ifndef compute_partial_sum_HPP
#define compute_partial_sum_HPP
#include <mutex>

    void compute_partial_sum(double &sum, std::mutex &sum_mutex, double a, double h, int n, int num_threads, int i);

    #endif //compute_partial_sum_HPP