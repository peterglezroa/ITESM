#include "header.h"

int main(int argc, char *argv[]){
	key_t key;
	int semid, i, shmid;
  struct shared *shared;

	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);
		return -1;
	}

	if ((key = ftok("/dev/null", 65)) == (key_t) -1) {
		fprintf(stderr, "Error at ftok");
		return -2;
	}

	if ((semid = semget(key, 3, 0666)) < 0) {
		fprintf(stderr, "Error at semget");
		return -3;
	}
	
	if ( (shmid = shmget(key, sizeof(struct shared), 0666)) < 0 ) {
		fprintf(stderr, "Error at shmid");
		exit(-4);
	} 	

	shared = (struct shared *) shmat(shmid, (void *) 0, 0);
	printf("Bear: The jar is empty. I will wait for the honey while sleeping...\n");
	while (1){
		sem_wait(semid, FULL, 1);
		sem_wait(semid, MUTEX, 1);
		if (shared->next == shared->pot) {
			printf("Bear: The jar is full! Im going to eat it!\n");
			sem_signal(semid, EMPTY, shared->pot);
			shared->next = 0;
      printf("Bear: The jar is empty. I will wait for the honey while sleeping...\n");
		} 
		sem_signal(semid, MUTEX, 1);
	}
	
	shmdt(shared);
	semctl(semid, 0, IPC_RMID, 0);
	shmctl(shmid, IPC_RMID, 0);
	return 0;
}
