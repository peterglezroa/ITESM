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
      }
//      fprintf(stdout, "\n");
  }
//	pthread_exit(0);
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
  if (argc != 7) {
      printf("%s -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n", argv[0]);
      return -2;
  }
  if (strcmp(argv[1], "-a") != 0) {
      printf("%s -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n", argv[0]);
      return -3;
  }
  if (strcmp(argv[3], "-b") != 0) {
      printf("%s -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n", argv[0]);
      return -4;
  }
  if (strcmp(argv[5], "-t") != 0) {
      printf("%s -a matrix_file_a.txt -b matrix_file_b.txt -t thread_amount\n", argv[0]);
      return -5;
  }
  if ((matA = fopen(argv[2], "r")) == NULL) {
      printf("No se encontro el archivo: %s\n", argv[2]);
      return -6;
  }
  if ((matB = fopen(argv[4], "r")) == NULL) {
      printf("No se encontro el archivo: %s\n", argv[4]);
      return -7;
  }

  thread_amount = atoi(argv[6]);
  if(thread_amount <= 0){
      printf("El número de threads debe ser un entero positivo %i\n", thread_amount);
      return -8;
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
    return -9;
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
  printf("%i\n", size_matrixA);
  for( int i = 0; i < size_matrixA; i++ ){
   for( int j = 0; j < size_matrixA; j++ ){
      printf("%.3f\t", matrix_C[i][j]);
    }
    printf("\n");
  }

  fclose(matA);
  fclose(matB);
  return 0;
}
