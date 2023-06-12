#include <iostream>
#include <chrono>
#include <cblas.h>

int main()
{
    const int MAX_DIMENSION = 8192;
    const double alpha = 1.0;
    const double beta = 2.5;
    double A[MAX_DIMENSION * MAX_DIMENSION];
    double B[MAX_DIMENSION * MAX_DIMENSION];
    double C[MAX_DIMENSION * MAX_DIMENSION];

    double tot_time = 0.;
    const int ntrial = 3;
    long double elapsed_time = 0.L;
    std::cout << "Rank\tFLOPs\t\tTime(s)" << std::endl;

    for (int N = 16; N <= MAX_DIMENSION; N *= 2)
    {
        double fp_op = 0.;
        fp_op = 2. * N * N * N + 2 * N * N;
        // Initialize matrices A and B with random values
        for (int i = 0; i < N * N; ++i)
        {
            A[i] = static_cast<double>(rand()) / RAND_MAX;
            B[i] = static_cast<double>(rand()) / RAND_MAX;
            C[i] = static_cast<double>(rand()) / RAND_MAX;
        }

        // Perform matrix multiplication and measure the execution time

        for (int itrial=0;itrial<ntrial;itrial++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, alpha, A, N, B, N, beta, C, N);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            elapsed_time += duration.count() * 1.e-9; //convert to seconds
        }
        tot_time = elapsed_time / ntrial; //average time in seconds
        std::cout << N << "\t" << fp_op / tot_time << "\t" << tot_time << std::endl;
        tot_time = 0.;
        elapsed_time = 0.;
    }

    return 0;
}