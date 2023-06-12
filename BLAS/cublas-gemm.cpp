#include <iostream>
#include <cuda_runtime.h>
#include <cublas_v2.h>

/*#define N 1024
#define M 1024
#define K 1024*/

int main()
{
    //matrix sizes
    for (int N = 16; N <=8192; N*=2){
        int M = N;
        int K = N;

        // Allocate host memory for matrices
        double *h_A = new double[N * K];
        double *h_B = new double[K * M];
        double *h_C = new double[N * M];

        // Initialize input matrices
        for (int i = 0; i < N * K; ++i)
            h_A[i] = static_cast<double>(i % 100) / 100.0f;

        for (int i = 0; i < K * M; ++i)
            h_B[i] = static_cast<double>((i + 1) % 100) / 100.0f;

        // Allocate device memory for matrices
        double *d_A, *d_B, *d_C;
        cudaMalloc((void **)&d_A, N * K * sizeof(double));
        cudaMalloc((void **)&d_B, K * M * sizeof(double));
        cudaMalloc((void **)&d_C, N * M * sizeof(double));

        // Copy input matrices from host to device
        cudaMemcpy(d_A, h_A, N * K * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(d_B, h_B, K * M * sizeof(double), cudaMemcpyHostToDevice);

        // Create cuBLAS handle
        cublasHandle_t handle;
        cublasCreate(&handle);

        // Perform matrix multiplication
        const double alpha = 1.0;
        const double beta = 1.0;
        cudaEvent_t start, stop;
        cudaEventCreate(&start);
        cudaEventCreate(&stop);
        cudaEventRecord(start, 0);
        cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, N, M, K, &alpha, d_A, N, d_B, K, &beta, d_C, N);
        cudaEventRecord(stop, 0);
        cudaEventSynchronize(stop);

        // Calculate elapsed time
        float milliseconds = 0;
        cudaEventElapsedTime(&milliseconds, start, stop);

        // Print performance information
        //std::cout << "Matrix multiplication performance:" << std::endl;
        std::cout << "Matrix size: " << N << "x" << M << "; Elapsed time: " << milliseconds << std::endl;

        // Destroy cuBLAS handle
        cublasDestroy(handle);

        // Free device memory
        cudaFree(d_A);
        cudaFree(d_B);
        cudaFree(d_C);

        // Free host memory
        delete[] h_A;
        delete[] h_B;
        delete[] h_C;
    }

    return 0;
}

