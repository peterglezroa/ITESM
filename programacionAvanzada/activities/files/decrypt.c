/*----------------------------------------------------------------
*
* Programación avanzada: Manejo de archivos
* Fecha: 28/02/2020
* Autor: 1651517 Pedro González, 1209403 Diana Ortiz 
*
*--------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define SIZE 1

typedef unsigned char uchar;
typedef unsigned long int ulong;
int mvright(int num, int pos){
  return num>>pos;
}
int mvleft(int num, int pos){
  return num<<pos;
}
int main(int argc, char* argv[]){
  int source, dest;
  // Revisar argumentos
  if(argc != 3){
    printf("No hay suficientes argumentos");
    return -2;
  }
  // Abrir source
  if((source = open(argv[1], O_RDONLY)) < 0){
    perror(argv[0]);
    return -3;
  }
  // Abrir destination
  if((dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0){
		perror(argv[0]);
		return -3;
	}
  // Desencryptar
  int buffer, left, right, together;
  uchar aux;
  while((buffer = read(source, &aux, sizeof(uchar))) != 0){
    right = mvright(aux, 4);
    left = mvleft(aux&15, 4);
    together = left|right;
    write(dest, &together, buffer);
  }
  close(source);
  close(dest);
}
