/*--------------------------------------------------------------------------------*
*  Programación avanzada: Manejo de threads
*  Pedro Luis González Roa
*  Fecha: 22/05/2020
*--------------------------------------------------------------------------------*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <sys/stat.h>

float **matrixA, **matrix_B, **matrix_C;
int hileras_por_thread;

void *calcular_thread(void *arg){
  int thread_id, rowsPerThread, rowStart, rowEnd;
  float sum = 0;
  thread_id = *(int *)(arg);
  pthread_exit(0);
}

int main(int argc, char * argv[]){
  // Validación de cantidad de argumentos
  if(argc != 7){
    fprintf(stderr, "usage: -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n");
    return -1;
  }
  
  // Validación de argumentos
  int thread_amount = -1, fd_matrixA = -1, fd_matrixB = -1;
  for(int i = 1; i < 7; i+=2){
    if( strcmp(argv[i], "-a") == 0){ 
        fprintf(stdout, "Abriendo matriz A en %s...\n", argv[i+1]);
        if( (fd_matrixA = open(argv[i+1], O_RDONLY)) < 0 ){
          fprintf(stderr, "No se pudo abrir el archivo: %s\n", argv[i+1]);
          return -2;
        }
    }else if( strcmp(argv[i], "-b") == 0){
        fprintf(stdout, "Abriendo matriz B en %s...\n", argv[i+1]);
        if( (fd_matrixB = open(argv[i+1], O_RDONLY)) < 0 ){
          fprintf(stderr, "No se pudo abrir el archivo: %s\n", argv[i+1]);
          return -2;
        }
    }else if( strcmp(argv[i], "-t") == 0){
        fprintf(stdout, "Validando cantidad de threads (%s)...\n", argv[i+1]);
        if( thread_amount = atoi(argv[i+1]) <= 0){
          fprintf(stderr, "Cantidad de threads (%s) no valida\n", argv[i+1]);
          return -3;
        } 
    }
  }
  fprintf(stdout, "Revisando que todos los argumentos se hayan dado...\n");
  if(thread_amount == -1 || fd_matrixA == -1 || fd_matrixB == -1){
    fprintf(stderr, "usage: -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n");
    return -4;
  }

  // Validación de tamaño de matrices
  int size_matrixA = 0, size_matrixB = 0;
  fprintf(stdout, "Leyendo tamaño de matriz A en fd %i...\n", fd_matrixA);
  if( (read(fd_matrixA, &size_matrixA, sizeof(int))) < 0 ){
     fprintf(stderr, "Could not read matrix A size");
     return -22;
  }
  fprintf(stdout, "Tamaño matriz A = %i\n", size_matrixA);

  fprintf(stdout, "Leyendo y validando tamaño de matriz B en fd %i...\n", fd_matrixB);
  if( (read(fd_matrixB, &size_matrixB, sizeof(int))) < 0 ){
     fprintf(stderr, "Could not read matrix B size");
     return -22;
  }else if( size_matrixB != size_matrixA ){
    fprintf(stdout, "Tamaño de matriz A (%i) no coincide con el tamaño de matriz B (%i)", size_matrixA, size_matrixB);
    return -7;
  }

  // Asignar espacios en memoria para la matriz B
  fprintf(stdout, "Asignando espacio de memoria a la matriz A...\n");
  matrixA = malloc(size_matrixA*sizeof(float*));
  for( int i = 0; i < size_matrixA; i++ ){
    matrixA[i] = malloc(size_matrixA * sizeof(float));
  }

  fprintf(stdout, "Asignando espacio de memoria a la matriz B...\n");
  matrix_B = malloc(size_matrixB*sizeof(float*));
  for( int i = 0; i < size_matrixB; i++ ){
    matrix_B[i] = malloc(size_matrixB * sizeof(float));
  }

  fprintf(stdout, "Asignando espacio de memoria a la matriz C...\n");
  matrix_C = malloc(size_matrixA*sizeof(float*));
  for( int i = 0; i < size_matrixA; i++ ){
    matrix_C[i] = malloc(size_matrixA * sizeof(float));
  }

  // Leer matriz A
  fprintf(stdout, "Leyendo matriz A...\n");
  for( int i = 0; i < size_matrixA; i++ ){
    fprintf(stdout, "Hilera %i, ", i);
    if( read(fd_matrixA, &matrixA[i], size_matrixA*sizeof(float)) < 0){
      fprintf(stderr, "Error al leer matriz A\n");
      return -8;
    }
  }

  // Leer matriz B
  fprintf(stdout, "Leyendo matriz B...\n");
  for( int i = 0; i < size_matrixB; i++ ){
    fprintf(stdout, "Hilera %i, ", i);
    if( read(fd_matrixB, &matrix_B[i], size_matrixB*sizeof(float)) < 0){
      fprintf(stderr, "Error al leer matriz B\n");
      return -9;
    }
  }

  // Calcular
  hileras_por_thread = ceil(size_matrixA/thread_amount);

  pthread_t threads[thread_amount];

  clock_t t;
  t = clock();

  for( int i = 0; i < thread_amount; i++ ){
    fprintf(stdout, "Calculando con thread %i", i);
    int *thread_id = malloc(sizeof(int));
    *thread_id = i;
    pthread_create(&threads[i], NULL, calcular_thread, (void*)thread_id);
  }

  for( int i = 0; i < thread_amount; i++ ){
    pthread_join(threads[i],NULL);
  }
  for( int i = 0; i < size_matrixA; i++ ){
    for( int j = 0; j < size_matrixA; j++ ){
      fprintf(stdout, "%.3f\t", matrix_C[i][j]);
    }
    fprintf(stdout,"\n");
  }


  close(fd_matrixB);
  close(fd_matrixA);
  return 0;
}
