#include <cuda_runtime.h>
#include <stdio.h>
#include <time.h>

#define TPB 10

__global__ void matrix_sub(int size, int *map, int *change) {
    /* Function that updates the map. Each thread will substract the changes to the actual map */
    int index = threadIdx.x + blockIdx.x*blockDim.x; // linearize matrix
    if(index < size) {
        map[index] -= change[index];
        if(map[index] < 0)
            map[index] = 0;
    }
}

void fill_random(int size, int *array) {
    /* Function to make random values on an array from 0 to 10 */
    for(int index = 0; index < size; index++)
        array[index] = rand()%11;
}

__global__ void print_m(int dimx, int dimy, int *m) {
    for(int i = 0; i < dimy; i++) {
        for(int j = 0; j < dimx; j++){
            printf("%i ", m[j + i*dimx]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_m_host(int dimx, int dimy, int *m) {
    for(int i = 0; i < dimy; i++) {
        for(int j = 0; j < dimx; j++){
            printf("%i ", m[j + i*dimx]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int *map, *change, size, dimx, dimy, rounds;
    int *d_map, *d_change;

    srand(time(NULL)); // Make random seed

    printf("Give me the x dimension of the map: ");
    scanf("%i", &dimx);

    printf("Give me the y dimension of the map: ");
    scanf("%i", &dimy);

    size = dimx*dimy; // Matrix will be linearized, no need to specify dimensions

    // Initialize HOST pointers
    map = (int *)malloc(sizeof(int)*size);
    fill_random(size, map);
    print_m_host(dimx, dimy, map);
    change = (int *)malloc(sizeof(int)*size);

    // Initialize DEVICE pointers
    cudaMalloc((void**)&d_map, sizeof(float)*size);
    cudaMemcpy(d_map, map, sizeof(int)*size, cudaMemcpyHostToDevice);
    cudaMalloc((void**)&d_change, sizeof(float)*size);

    // Will not scan and the damage will be random to save time with scans
    printf("How many rounds will be played? ");
    scanf("%i", &rounds);

    printf("Starting map:\n");
    print_m<<<1,1>>>(dimx, dimy, d_map);

    for(int i = 0; i < rounds; i++) {
        // Init map damages for the round and copy to device
        fill_random(size, change);
        cudaMemcpy(d_change, change, sizeof(int)*size, cudaMemcpyHostToDevice);
        printf("Damage to map at round %i:\n", i);
        print_m_host(dimx, dimy, change);

        // Damage map in device
        matrix_sub<<<(TPB+size)/TPB, TPB>>>(size, d_map, d_change);

        // Copy and print map after round damage
        printf("Map after round %i:\n", i);
        cudaMemcpy(map, d_map, sizeof(int)*size, cudaMemcpyDeviceToHost);
        print_m_host(dimx, dimy, map);
    }

    free(map); free(change);
    cudaFree(d_map); cudaFree(d_change);
    return 0;
}
