/*
 * Programación avanzada
 * Manejo de procesos
 * Pedro Luis González Roa A01651517
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void printProcess(int ppid, int pid, int level){
  for(int i; i<level; i++){
    printf("\t");
  }
  printf("PPID = %i PID = %i NIVEL = %i\n", ppid, pid, level);
}

void levels(int actual, int levels_required){
	int nextLevel, pid, ppid;
	if(actual < levels_required){
		for(int i = 0; i < actual; i++){
			if( (pid=fork()) < 0 ){
        fprintf(stderr, "fork");
      }
      pid = getpid(); ppid = getppid();
      printProcess(pid, ppid, actual);
			levels(actual+1, levels_required);
		}
		wait(NULL);
	} else {
		for(int i = 0; i < levels_required; i++){
			fork();
			sleep(1);
      pid = getpid(); ppid = getppid();
      printProcess(pid, ppid, actual);
      exit(0);
		}
	}
}

int main(char argc, char *argv[]){
	int pid, ppid, levels_required, result, rid, i;
	if(argc != 2){
		fprintf(stderr, "usage: descending number\n");
		return -2;
	}

	levels_required = atoi(argv[1]); // Cambiar arg a levels
	if(levels_required <= 0){
		fprintf(stderr, "descending: the parameter must be a positive integer\n");
		return -3;
	}
  pid = getpid(); ppid = getppid();
  printProcess(ppid, pid, 1);
	levels(1, levels_required);
	return 0;
}
