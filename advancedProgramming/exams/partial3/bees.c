#include "header.h"

void bee(int id) {
	key_t key;
	int semid, shmid, i;
  struct shared *shared;
	
	if ((key = ftok("/dev/null", 65)) == (key_t) -1) {
		perror("ftok");
		exit(-1);
	}
	if ((semid = semget(key, 3, 0666)) < 0) {
		perror("semid");
		exit(-1);
	}
	if ((shmid = shmget(key, sizeof(struct shared), 0666)) < 0 ) {
		perror("shmid");
		exit(-1);
	} 
	
	shared = (struct shared *) shmat(shmid, (void *) 0, 0);
  shared->bees++;
	
	srand(getpid());
	while(1){
    printf("Bee %i: I'm going to put one portion\n", id);
    sem_wait(semid, EMPTY, 1);
    sem_wait(semid, MUTEX, 1);

    shared->portions[shared->next++] = 1;
    if(shared->next >= shared->pot){
        printf("Bee %i: Oops! The pot is full! I will notify the bear...\n", id);
        sem_signal(semid, FULL, 1);
    } 
    printf("Bee %i: I already put the portion. %i/%i\n", id, shared->next, shared->pot);
    sem_signal(semid, MUTEX, 1);
    sem_signal(semid, FULL, 1);
	}
	shmdt(shared);
	exit(0);
}

int main(int argc, char *argv[]) {
	int pid, bees;
	
	if (argc != 2) {
		fprintf(stderr, "usage: %s number_bees\n", argv[0]);
		return -1;
	}

  if( (bees = atoi(argv[1])) < 0){
	  fprintf(stderr, "Incorrect number of bees. It must be a positive number");
    return -2;
  }
	
	for (int i = 0; i < bees; i++) {
		if ((pid = fork()) < 0) {
		  fprintf(stderr, "Error at fork");
			exit(-3);
		} else if (pid == 0) {
			bee(i);
		}	
  }
	return 0;
}
