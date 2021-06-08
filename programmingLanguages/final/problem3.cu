#include <cuda_runtime>
#include <stdio.h>
#include <time>

#define TPB 10

__global__ void round_change(int size, int *map, int *change) {
    /* Function that updates the map. Each thread will sum the changes to the actual map */
    int index = threadIdx.x + blockIdx.x*blockDim.x; // linearize matrix
    if(index < size)
        map[index] += change[index];
}

__global__ void fill_random(int size, int *array) {
    /* Function to make random values on an array from 0 to 10 */
    int index = threadIdx.x + blockIdx.x*blockDim.x; // linearize matrix
    if(index < size)
        array[index] = rand()%11;
}

int main() {
    int *map, *change, size, dimx, dimy;
    int *d_map, *d_change;

    srand(time(NULL)); // Make random seed

    printf("Give me the x dimension of the map: ");
    scanf("%i", &dimx);

    printf("Give me the y dimension of the map: ");
    scanf("%i", &dimy);

    size = dimx*dimy; // Matrix will be linearized, no need to specify dimensions

    // Initialize HOST pointers
    map = (int *)malloc(sizeof(int)*size);
    change = (int *)malloc(sizeof(int)*size);

    // Initialize DEVICE pointers

    fill_random<<<(TPB+size)/TPB, TPB>>>(size, d_map);
