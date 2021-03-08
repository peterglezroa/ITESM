/*
 * Programación avanzada
 * Proyecto final - Mini shell
 * 
 * Autor: Pedro Luis González Roa - A01651517
 * Fecha: 02/06/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>

#define MAX_BUFFER 512

void exec_command(char *string){
  int argc = 1, i = 0, str_size, quotes = 0;
  char **argv, *pointer1, *pointer2;
  // Contar cantidad de argumentos
  for(pointer1 = string; *pointer1 != '\0'; pointer1++){
    if( *pointer1 == ' ' ){
      argc++;
    }
  }
  argv = malloc(sizeof(char *)*argc);
  // Obtener commando y argumento
  pointer2 = string;
  for(pointer1 = string; *pointer1 != '\0'; pointer1++){
    if( (*pointer1 == ' ' || *pointer1 == '\n') && !quotes){
      str_size = pointer1-pointer2;
      if(str_size > 0){
        argv[i] = malloc(sizeof(char)*str_size+1);
        strncpy(argv[i], pointer2, str_size);
        argv[i][str_size] = '\0';
//        fprintf(stdout, "argumento %i: %s\n", i, argv[i]);
        i++;
      }
      pointer2=pointer1+1;
    }else if( *pointer1 == '"' ){
//      fprintf(stdout, "%i", quotes);
      quotes = (quotes+1)%2;
      // Closing quotes
      if( quotes == 0 ){
        pointer2++;
        *pointer1 = ' ';
        pointer1--;
      }
    }
  }
  // Correr commando
  if( execvp(argv[0], argv) != 0){
    fprintf(stdout, "Command %s execute error\n", argv[0]);
  }
  
  // Liberar memoria
  for( int i = 0; i < argc; i++){
    free(argv[i]);
  }
}

void parse_run_commands(char *input){
  char *command, *pointer1, *pointer2;
  int pid, fork_count = 0, str_size;
  pointer2 = input;
  for(pointer1=input; *pointer1 != '\0'; pointer1++){
    if( *pointer1 == ';' || *pointer1 == '\n' ){
      str_size = pointer1-pointer2;
      command = malloc(sizeof(char)*str_size+2);
      strncpy(command, pointer2, str_size);
      command[str_size] = '\n';
      command[str_size+1] = '\0';
      
      // Make fork for command
      if( (pid=fork()) == 0){
        exec_command(command);
        free(command);
        exit(0);
      }
      fork_count++;
      pointer2=pointer1+1;
    }
  }
  while(fork_count > 0){
    wait(NULL);
    fork_count--;
  }
}

void interactive_mode(){
  int running = 1;
  char buffer[MAX_BUFFER];
  while(running){
    // Prompt
    fprintf(stdout, "mini-shell> ");
    // Leer commando
    if( fgets(buffer, MAX_BUFFER, stdin) == NULL ){
      fprintf(stderr, "Error al leer commando.\n");
      exit(-2);
    }
//    fprintf(stdout, "%s", buffer);

    if( strcmp(buffer, "quit\n") == 0 ){ // Quit command
      fprintf(stdout,"Quitting shell...\n");
      running = 0;
    }else if( buffer[0] != '\n' ){
      parse_run_commands(buffer);
    }
  }
}

void run_file(char *file_name){
  char buffer[MAX_BUFFER];
  FILE *file;
  if( (file = fopen(file_name, "r")) == NULL ){
    fprintf(stdout, "No se pudo abrir el archivo");
    exit(-2);
  }
  while( fgets(buffer, sizeof(buffer), file) != NULL ){
    if( strcmp(buffer, "quit\n") == 0 || strcmp(buffer, "quit") == 0 ){
      fprintf(stdout, "Quitting...\n");
      break;
    }else{
      fprintf(stdout, "\n mini-shell> %s", buffer);
      parse_run_commands(buffer);
    }
  }
  fclose(file);
}

int main(int argc, char *argv[]){
  // Validar que máximo sólo se pase el archivo del script
  if (argc > 2){
    fprintf(stderr, "usage %s: <script file>", argv[0]);
    return -1;
  }

  if(argc == 1){ // Modo iteractivo
    fprintf(stdout, "Entering interactive mode...\n");
    interactive_mode();
  }else{ // Modo lote
    fprintf(stdout, "Executing script file...\n");
    run_file(argv[1]);
  }

  return 0;
}
