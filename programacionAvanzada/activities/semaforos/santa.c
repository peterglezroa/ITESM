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

int main(int argc, char *argv[]) {

  if(argc != 1){
    printf("usage: %s\n",argv[0]);
    return -1;
  }

  int semid;
  int i;
  key_t key;

  if((key = ftok("/dev/null",65)) == (key_t) -1){
    perror(argv[0]);
    return -1;
  }

  if((semid = semget(key, 6, 0666)) < 0){
    perror(argv[0]);
    return -1;
  }

  while(1){
    wait(semid,santa);
    wait(semid,mt);

    int numRen = semctl(semid, renos, GETVAL, 0);
    int numElf = semctl(semid, elfos, GETVAL, 0);

    printf("Cuantos renos hay? %d\n", numRen);
    printf("Cuantos elfos hay? %d\n", numElf);

    if(numRen >= 9){
      ssignal(semid, reno, 9);
      swait(semid, reno, 9);
    }else if(numElf == 3){
      printf("Bueno... hay que ayudar a estos elfos\n");
    }
    signal(semid, mt);
    sleep(1);
  }
  return 0;
}
