/*
   Pedro Luis González Roa
   A01651517
   Cuda Lab 2
*/
// %%cu
#include <cuda_runtime.h>
#include <stdio.h>

#define THREADS_PER_BLOCK 10

__device__ void matrix_dot(int col, int row, int m, int n, int k, float *d_ma, float *d_mb, float *d_mc) {
    int index = col + row*n;
    d_mc[index] = 0;
    for(int i = 0; i < n; i++) {
        d_mc[index] += d_ma[i + row*n]*d_mb[col+i*n];
    }
}

__global__ void valid_matrix_dot(int m, int n, int k, float *d_ma, float *d_mb, float *d_mc) {
    int col = threadIdx.x + blockIdx.x*blockDim.x;
    int row = threadIdx.y + blockIdx.y*blockDim.y;
    if(m > col && n > row) {
        matrix_dot(col, row, m, n, k, d_ma, d_mb, d_mc);
    }
}

int main() {
    float *ma, *mb, *mc;
    float *d_ma, *d_mb, *d_mc;
    int m, n, n2, k, blocks;

    /* input first matrix */
    fprintf(stdout, "Give me the dimensions of the first matrix: ");
    fscanf(stdin, "%i %i", &m, &n);
    ma = (float *)malloc(sizeof(float)*m*n);

    fprintf(stdout, "Give me the first matrix, separating columns with space and rows with endline.\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            fscanf(stdin, "%f", &ma[j+i*n]);
        }
    }

    /* Input second matrix */
    fprintf(stdout, "Give me the dimensions of the second matrix: ");
    fscanf(stdin, "%i %i", &n2, &k);
    if(n != n2) {
        fprintf(stdout, "Incorrect Dimensions!\n");
        return -1;
    }
    mb = (float *)malloc(sizeof(float)*n*k);

    fprintf(stdout, "Give me the second matrix, separating columns with space and rows with endline.\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            fscanf(stdin, "%f", &mb[k+i*n]);
        }
    }

    /* Make space for third matrix */
    mc = (float *)malloc(sizeof(float)*m*k);

    HANDLE_ERROR(cudaMalloc((void**)&d_ma, sizeof(float)*m*n));
    HANDLE_ERROR(cudaMalloc((void**)&d_mb, sizeof(float)*n*k));
    HANDLE_ERROR(cudaMalloc((void**)&d_mc, sizeof(float)*m*k));
    HANDLE_ERROR(cudaMemcpy(d_ma, ma, sizeof(float)*m*n, cudaMemcpyHostToDevice));
    HANDLE_ERROR(cudaMemcpy(d_mb, mb, sizeof(float)*n*k, cudaMemcpyHostToDevice));
    HANDLE_ERROR(cudaMemcpy(d_mc, mc, sizeof(float)*m*k, cudaMemcpyHostToDevice));

    /* call function */
    blocks = ceil((THREADS_PER_BLOCK+m*k)/THREADS_PER_BLOCK)
    dim3 Blocks(blocks, blocks);
    dim3 Threads(THREADS_PER_BLOCK, THREADS_PER_BLOCK);
    valid_matrix_dot<<<Blocks, Threads>>>(m, n, k, d_ma, d_mb, d_mc);

    /* cpy result */
    cudaMemcpy(mc, d_mc, sizeof(float)*m*k, cudaMemcpyDeviceToHost);

    /* print result */
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            fprintf(stdout, "%f ", mc[i][j]);
        }
        fprintf(stdout, "\n");
    }

    free(ma);free(mb);free(mc);
    cudaFree(d_ma);cudaFree(d_mb);cudaFree(d_mc);
    return 0;
}
