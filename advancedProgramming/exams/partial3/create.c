#include "header.h"

int main(int argc, char *argv[]) {
	key_t key;
	int semid, shmid, pot;

	if (argc != 2) {
		printf("usage: %s pot_size\n", argv[0]);
		return -1;
	}
	if ((key = ftok("/dev/null", 65)) == (key_t) -1) {
		perror(argv[0]);
		return -1;
	}
	if ((semid = semget(key, 3, 0666 | IPC_CREAT)) < 0) {
		perror(argv[0]);
		return -1;
	}

  if( (pot = atoi(argv[1])) < 0){
    fprintf(stderr, "Not a valid pot size");
    return -2;
  }

	semctl(semid, FULL, SETVAL, 0);
	semctl(semid, EMPTY, SETVAL, pot);
	semctl(semid, MUTEX, SETVAL, 1);

	if ((shmid = shmget(key, sizeof(struct shared), 0666 | IPC_CREAT)) < 0 ) {
		semctl(semid, 0, IPC_RMID, 0);
		fprintf(stderr, "shmid");
		return -3;
	} 
		
	struct shared *shared;
	shared = (struct shared*) shmat(shmid, (void*) 0, 0);
	shared->next = 0;
  shared->pot = pot;
	memset(shared->portions, 0, pot * sizeof(int));
	shmdt(shared);

	fprintf(stdout, "Semaphore created with a pot size of %i...\n", pot);
	return 0;
}
