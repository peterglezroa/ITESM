/*
 * Programación Avanzada 
 *
 * Actividad : 
 * Manejo de semaforos
 * 
 * 12 de Mayo de 2020
 *
 * Diana Estefanía Ortiz Ledesma
 * A01209403
 *
 * Pedro Gonzalez Roa
 * A01651517
 */


#include "header.h"

void crear_renos(char * program){
  int semid;
  int i;
  key_t key;

  if((key = ftok("/dev/null",65)) == (key_t) -1){
    perror(program);
    exit(-1);
  }

  if((semid = semget(key,6,0666)) < 0){
    perror(program);
    exit(-1);
  }

  while(1){
    sleep(1);
    wait(semid,mt);
    ssignal(semid,renos,1);
    printf("reno %d ha llegado\n", getpid());
    int numRen = semctl(semid, renos, GETVAL, 0);

    if(numRen == 9){
      printf("reno %d ya esta listo para salir\n", getpid());
      signal(semid,santa);
    }
    signal(semid, mt);
    wait(semid,reno);
  }
  exit(0);
}

int main(int argc, char *argv[]) {
  int i, pid;

  for(i = 0; i < 9; i++){
    if((pid = fork()) < 0){
      perror("fork");
      return -1;
    }else if(pid == 0){
      crear_renos(argv[0]);
    }else{
    }
  }
  return 0;
}
