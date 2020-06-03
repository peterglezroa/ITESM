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
  int semid;
  int i;
  unsigned short values[6];
  key_t key;

  if ( (key = ftok("/dev/null", 65)) == (key_t) -1 ) {
		perror(argv[0]);
		return -1;
	}

  if ( (semid = semget(key,6,0666 | IPC_CREAT))  < 0 ) {
		perror(argv[0]);
		return -1;
	}

  semctl(semid,elfos,SETVAL,0);
  semctl(semid,mt,SETVAL,1);
  semctl(semid,renos,SETVAL,0);
  semctl(semid,santa,SETVAL,0);
  semctl(semid,reno,SETVAL,0);
  semctl(semid,elfo,SETVAL,1);
  semctl(semid, 0, GETALL, values);

  return 0;
}
