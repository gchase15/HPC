#include "sequential_riemann_sum.hpp"
#include "f.hpp"

double sequential_riemann_sum(double a, double b, int n){
    double h = (b-a) / n;
    double sum = 0.0;

    for (int i=0; i<n; ++i){
        double x = a + i * h; 
        sum+=f(x) * h; 
    }
    return sum; 
}