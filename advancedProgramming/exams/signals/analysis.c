/*
 * Pedro Luis González Roa
 * A01651517
 * 21/04/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/utsname.h>
#include <time.h>

#define MAXNAME 256
#define SEED 12345

int pid_main = 0, pid_one = 0, pid_two = 0, iteration = 1, timeout;
char *prefix_input, *prefix_output;

void signal_handler_end(int sig){
  fprintf(stdout, "Main => Received signal.\n");
  if(iteration == 3){
    fprintf(stdout, "Main => Ending...\n");
    kill(pid_one, SIGINT);
    kill(pid_two, SIGINT);
    exit(0);
  }
  iteration++;
  fprintf(stdout, "\n\nStarting iteration %i...\n", iteration);
  sleep(timeout);
  fprintf(stdout, "Main => Sending signal to ONE: %i\n", pid_one);
  kill(pid_one, SIGUSR1);
}
/* Main process -----------------------------------------------------------*/
void signal_handler_main(int sig){
  fprintf(stdout, "Main => Received signal.\nMain => Sending signal to TWO: %i\n", pid_two);
  kill(pid_two, SIGUSR2);
}

void main_process(){
  pid_main = getpid();

  fprintf(stdout, "Main at %i\n", pid_main);
  fprintf(stdout, "Main => Defining signal handlers...\n");

  signal(SIGUSR1, signal_handler_main);
  signal(SIGUSR2, signal_handler_end);
  
  fprintf(stdout, "\n\nStarting iteration %i...\n", iteration);
  sleep(timeout);

  fprintf(stdout, "Main => Sending signal to ONE: %i\n", pid_one);
  kill(pid_one, SIGUSR1);
  wait(NULL);
}
/* Process one ------------------------------------------------------------*/
void signal_handler_one(int sig){
  fprintf(stdout, "ONE => Received signal\n");
  int filedir, *buffer;
  char filename[MAXNAME];
  sprintf(filename, "%s%d.dat", prefix_input, iteration);

  srand(SEED);

  fprintf(stdout, "ONE => Creating file \"%s\"...\n", filename);
  
  if( (filedir = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0){
    fprintf(stderr, "ONE => Error at creating file %i. Ending...\n", filedir);
    exit(-10);
  }

  fprintf(stdout, "ONE => Making buffer...\n");
  buffer = malloc(100*sizeof(int));
  for(int i = 0; i < 100; i++){
    buffer[i] = (rand()%100) + 1;
    fprintf(stdout, "%i " , buffer[i]);
  }

  fprintf(stdout, "\nONE => Writing file \"%s\"...\n", filename);
  write(filedir, buffer, 100*sizeof(int));
  close(filedir);
  
  fprintf(stdout, "ONE => Sending signal to Main %i\n", pid_main);
  iteration++;
  kill(pid_main, SIGUSR1);
}

void process_one(){
  pid_one = getpid();

  fprintf(stdout, "ONE at %i\n", pid_one);
  fprintf(stdout, "ONE => Defining signal handlers...\n");

  signal(SIGUSR1, signal_handler_one);
  while(1)
    pause();
}

/* Process two ------------------------------------------------------------*/
float average(int *array){
  float sum = 0;
  int i = 0, count = 0;
  while(array[i] != 0){
    sum += array[i];
    count++;
    i++;
  }
  return sum/count;
}

float variance(float average, int *array){
  float sum = 0;
  int i = 0, count = 0;
  while(array[i] != 0){
    sum += abs(average - array[i]);
    count++;
    i++;
  }
  return sum/count;

}

void signal_handler_two(int sig){
  fprintf(stdout, "TWO => Received signal.\n");
  int filedirInput, filedirOutput, *buffer;
  float *buffer2;
  char filenameInput[MAXNAME], filenameOutput[MAXNAME];
  sprintf(filenameInput, "%s%d.dat", prefix_input, iteration);
  sprintf(filenameOutput, "%s%d.dat", prefix_output, iteration);
  
  fprintf(stdout, "TWO => Opening input file \"%s\"...\n", filenameInput);
  if( (filedirInput = open(filenameInput, O_RDONLY)) < 0){
    fprintf(stderr, "TWO => Could not open file. Ending....");
    exit(-20);
  }
  buffer = malloc(100*sizeof(int));
  read(filedirInput, buffer, 100*sizeof(int));

  
  fprintf(stdout, "TWO => Creating output file \"%s\"...\n", filenameOutput);
  if( (filedirOutput = open(filenameOutput, O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0){
    fprintf(stderr, "ONE => Error at creating file %i. Ending...\n", filedirOutput);
    exit(-21);
  }
  buffer2 = malloc(2*sizeof(float));

  fprintf(stdout, "TWO => calculating average...\n");
  buffer2[0] = average(buffer);
  fprintf(stdout, "TWO => calculating variance...\n");
  buffer2[1] = variance(buffer2[0], buffer);
  
  fprintf(stdout, "TWO => Writing on output file \"%s\"...\n", filenameOutput);
  write(filedirOutput, buffer2, 2*sizeof(float));

  fprintf(stdout, "TWO => average is: %f, variance is %f.\n", buffer2[0], buffer2[1]); 

  close(filedirInput);
  close(filedirOutput);
  
  free(buffer);
  free(buffer2);

  iteration++;
  fprintf(stdout, "TWO => Sending signal to Main: %i.\n", pid_main);
  kill(pid_main, SIGUSR2);
}

void process_two(){
  pid_two = getpid();

  fprintf(stdout, "TWO at %i\n", pid_two);
  fprintf(stdout, "TWO => Defining signal handlers...\n");
  
  signal(SIGUSR2, signal_handler_two);
  while(1)
    pause();
}

int main(int argc, char *argv[]){
  if(argc != 4){
    fprintf(stderr, "usage %s: timeout prefix_input prefix_output\n", argv[0]);
    return -1;
  }

  timeout = atoi(argv[1]);
  if(timeout < 0){
    fprintf(stderr, "usage %s: timeout must be positive!\n", argv[0]);
    return -2;
  }
  
  prefix_input = argv[2];
  prefix_output = argv[3];

  pid_main = getpid();
  fprintf(stdout, "Doing first fork..\n");
  if( (pid_one = fork()) < 0){
    fprintf(stderr, "First fork error\n");
    return -1;
  }else if(pid_one == 0){
    process_one();
  }else{
    fprintf(stderr, "Doing second fork\n");
    if( (pid_two = fork()) < 0){
      fprintf(stderr, "Second fork error\n");
      return -2;
    }else if(pid_two == 0){
      process_two();
    }else{
      main_process();
    }
  }
  while(1){
    pause();
  }
}
