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

void crear_elfos(char * program){
  int semid;
  int i;
  key_t key;

  if((key = ftok("/dev/null",65)) == (key_t) -1){
    perror(program);
    exit(-1);
  }

  if((semid = semget(key, 6, 0666)) < 0){
    perror(program);
    exit(-1);
  }

  while(1){
    sleep(1);
    wait(semid,elfo);
    wait(semid,mt);

    ssignal(semid, elfos, 1);
    printf("el elfo %i pide ayuda...\n", getpid());
    int numElfos = semctl(semid,elfos,GETVAL,0);

    if(numElfos == 3){
      signal(semid,santa);
    }else{
      signal(semid,elfo);
    }
    signal(semid,mt);
    wait(semid,mt);

    swait(semid, elfos, 1);
    numElfos = semctl(semid, elfos, GETVAL, 0);

    if(numElfos == 0){
      signal(semid,elfo);
    }
    signal(semid,mt);
  }

  exit(0);
}

int main(int argc, char *argv[]) {
  int elf; 
  int i;
  int pid;

  elf = atoi(argv[1]);

  for(i = 0; i < elf; i++){
    if((pid = fork()) < 0){
      perror("fork");
      return -1;
    }else if(pid == 0){
      crear_elfos(argv[0]);
    }else{

    }
  }

  return 0;
}
