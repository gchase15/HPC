#ifndef riemann_sum_header_HPP
#define riemann_sum_header_HPP

#include "f.hpp" //the function being integrated. 
#include "compute_partial_sum.hpp" //computation of sums inside a thread
#include "parallel_riemann_sum.hpp" //set up the threads
#include "sequential_riemann_sum.hpp" //sequential summation used for MPI experiment

#endif 