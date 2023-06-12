#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <math.h>
#include <mpi.h>

double f(double x) {
    return ((x*x)+4)/(4*x); //function to integrate
}

double sequential_riemann_sum(double a, double b, int n){
    double h = (b-a) / n;
    double sum = 0.0;
    for (int i=0; i<n; ++i){
        double x = a + i * h; 
        sum+=f(x) * h; 
    }
    return sum; 
}

int main(int argc, char* argv[]){

    if (argc != 2){
    std::cerr << "Not enough arguments. Needs number of partition points." << std::endl;
    return 1; 
}

    const double ans = 6.16675946923;
    MPI_Init(&argc, &argv);
    int ip, np; 
    MPI_Comm_rank(MPI_COMM_WORLD, &ip);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    int n = std::atoi(argv[1]); //partition points
    double a = 1.0, b = 6.0; //bounds of integration

    double local_a = a + ip * (b - a) / np;
    double local_b = a + (ip + 1) * (b - a) / np;
    int local_n = n / np;

    double local_sum = sequential_riemann_sum(local_a, local_b, local_n);
    std::cout << "Process: " << ip << "  Local Sum: " << local_sum << std::endl;
    double global_sum;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (ip == 0){
        std::cout << "ANS: " << global_sum << std::endl;
    }
    MPI_Finalize();

    return 0; 
}
