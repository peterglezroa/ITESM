/*
   Pedro Luis González Roa
   A01651517
   Cuda lab 1
*/

// %%cu
#include <cuda_runtime.h>
#include <stdio.h>

const int N = 1000000000;
const int THREADS = 256;

__global__ void calc_pi(double* area){
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    double mid, height, width;
    if(index < N){
        width = 1.0 / (double) N;
        mid = (index + .5) * width;
        height = 4.0/ (1.0 + mid * mid);
        area[index]= width * height;
	index += blockDim.x * gridDim.x;
    }
}

int main(void){
    double res, *area, *d_area;
    // Allocate memory for area
    area = (double*) malloc(N * sizeof(double));
    // Allocate memory for device area
    cudaMalloc((void **)&d_area, N * sizeof(double));
    // Call GPU function
    calc_pi<<<(N/THREADS)+1, THREADS>>>(d_area);
    // Cpy device are to area
    cudaMemcpy(area, d_area, sizeof(double) * N, cudaMemcpyDeviceToHost);
    for(int i = 0; i < N; i++)
        res += area[i];

    printf("RECTANGLES: %d\n", N);
    printf("THREADS PER BLOCK: %d\n", THREADS);
    printf("RESULT: %f\n", res);

    free(area);
    cudaFree(d_area);
    return 0;
}
