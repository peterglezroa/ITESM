/*--------------------------------------------------------------------------------
*  Programación avanzada: Manejo de threads
*  Pedro Luis González Roa
*  Fecha: 22/05/2020
--------------------------------------------------------------------------------*/

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

float **matrix_A, **matrix_B, **matrix_C;
int hileras_por_thread, size_matrixA, size_matrixB, thread_amount = -1;

void *calcular_thread(void *arg){
  int thread_id, hileras_por_thread, rowStart, rowEnd;
  float sum = 0;
  thread_id = *(int *)(arg);

  rowStart = thread_id * hileras_por_thread;
  rowEnd = (thread_id + 1) * hileras_por_thread;

//  fprintf(stdout, "Revisando restantes...\n");
  if(thread_id == thread_amount - 1){
    rowEnd = rowEnd + size_matrixA % thread_amount;
  }

//  fprintf(stdout, "Haciendo calculo...\n");
  for (int i = rowStart; i < rowEnd; i++) {
      for (int j = 0; j < size_matrixA; j++) {
          sum = 0;
          for (int k = 0; k < size_matrixA; k++) {
              sum = sum + matrix_A[i][k] * matrix_B[k][j];
          }
          matrix_C[i][j] = sum;
          fprintf(stdout, "%.3f\t", matrix_C[i][j]);
      }
      fprintf(stdout, "\n\n");
  }
	pthread_exit(0);
}

int main(int argc, char * argv[]){
  // Validación de cantidad de argumentos
  if(argc != 7){
    fprintf(stderr, "usage: -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n");
    return -2;
  }

  // Validación de argumentos
  int fd_matrixA = -1, fd_matrixB = -1;
  FILE *matA, *matB;
  for(int i = 1; i < 7; i+=2){
    if( strcmp(argv[i], "-a") == 0){
//        fprintf(stdout, "Abriendo matriz A en %s...\n", argv[i+1]);
        if( (matA = fopen(argv[i+1], "r")) == NULL ){
          fprintf(stderr, "No se pudo abrir el archivo: %s\n", argv[i+1]);
          return -2;
        }
    }else if( strcmp(argv[i], "-b") == 0){
//        fprintf(stdout, "Abriendo matriz B en %s...\n", argv[i+1]);
        if( (matB = fopen(argv[i+1], "r")) == NULL ){
          fprintf(stderr, "No se pudo abrir el archivo: %s\n", argv[i+1]);
          return -2;
        }
    }else if( strcmp(argv[i], "-t") == 0){
//        fprintf(stdout, "Validando cantidad de threads...\n");
        if( (thread_amount = atoi(argv[i+1])) <= 0){
          fprintf(stderr, "Cantidad de threads (%s) no valida\n", argv[i+1]);
          return -3;
        }
    }else{
      fprintf(stderr, "usage: -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n");
      return -1;
    }
  }
//  fprintf(stdout, "Revisando que todos los argumentos se hayan dado...\n");
  if(thread_amount == -1 || matA == NULL || matB == NULL){
    fprintf(stderr, "usage: -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n");
    return -4;
  }

  // Validación de tamaño de matrices
  size_matrixA = 0, size_matrixB = 0;
//  fprintf(stdout, "Leyendo tamaño de matriz A...\n");
  fscanf(matA, "%i", &size_matrixA);
//  fprintf(stdout, "Tamaño matriz A = %i\n", size_matrixA);

//  fprintf(stdout, "Leyendo y validando tamaño de matriz B...\n");
  fscanf(matB, "%i", &size_matrixB);
  if( size_matrixB != size_matrixA ){
//    fprintf(stdout, "Tamaño de matriz A (%i) no coincide con el tamaño de matriz B (%i)", size_matrixA, size_matrixB);
    return -7;
  }

  // Asignar espacios en memoria para la matriz B
//  fprintf(stdout, "Asignando espacio de memoria a la matriz A...\n");
  matrix_A = malloc(size_matrixA*sizeof(float*));
  for( int i = 0; i < size_matrixA; i++ ){
    matrix_A[i] = malloc(size_matrixA * sizeof(float));
  }

//  fprintf(stdout, "Asignando espacio de memoria a la matriz B...\n");
  matrix_B = malloc(size_matrixB*sizeof(float*));
  for( int i = 0; i < size_matrixB; i++ ){
    matrix_B[i] = malloc(size_matrixB * sizeof(float));
  }

//  fprintf(stdout, "Asignando espacio de memoria a la matriz C...\n");
  matrix_C = malloc(size_matrixA*sizeof(float*));
  for( int i = 0; i < size_matrixA; i++ ){
    matrix_C[i] = malloc(size_matrixA * sizeof(float));
  }

  // Leer matriz A
//  fprintf(stdout, "Leyendo matriz A...\n");
  for( int i = 0; i < size_matrixA; i++ ){
    for(int j = 0; j < size_matrixA; j++){
      fscanf(matA, "%f", &matrix_A[i][j]);
    }
  }

  // Leer matriz B
//  fprintf(stdout, "Leyendo matriz B...\n");
  for( int i = 0; i < size_matrixB; i++ ){
    for(int j = 0; j < size_matrixB; j++){
      fscanf(matB, "%f", &matrix_B[i][j]);
    }
  }

  // Calcular
  hileras_por_thread = ceil(size_matrixA/thread_amount);

  pthread_t threads[thread_amount];

  clock_t t;
  t = clock();

  for( int i = 0; i < thread_amount; i++ ){
//    fprintf(stdout, "Calculando con thread %i\n", i);
    int *thread_id = malloc(sizeof(int));
    *thread_id = i;
    pthread_create(&threads[i], NULL, calcular_thread, (void*)thread_id);
  }

  for( int i = 0; i < thread_amount; i++ ){
    pthread_join(threads[i],NULL);
  }
//  for( int i = 0; i < size_matrixA; i++ ){
//    for( int j = 0; j < size_matrixA; j++ ){
//      fprintf(stdout, "%.3f\t", matrix_C[i][j]);
//    }
//    fprintf(stdout,"\n");
//  }

  fclose(matA);
  fclose(matB);
  return 0;
}
