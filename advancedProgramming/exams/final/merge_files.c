/*
 * Programación Avanzada
 * ---------------------
 *  EXAMEN FINAL
 *  Pedro Luis González Roa A01651517
 *  09 / 06 / 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUFFER_SIZE 512

int dir_file(char * name);
void files(char * dir_name, int current_level);
void append(char *input_file);

// Globals
int max_level;
FILE *file_output;

int main(int argc, char * argv[]){
  char *directory, *file;
  
  // Checar argumentos ----------------------------
  // Cant args
  if( argc != 4 ){
    fprintf(stderr, "usage: %s <directory> <output_file> <max_level>\n", argv[0]);
    return -1;
  }

  // Checar directorio
  if( dir_file(argv[1]) != 0 ){
    fprintf(stderr, "%s: Not a directory\n", argv[0]);
    return -2;
  }
  
  // Checar max level
  if( (max_level = atoi(argv[3])) < 1 ){
    fprintf(stderr, "%s: Max level not valid %s\n", argv[0], argv[3]);
    return -4;
  }

  if( (file_output = fopen(argv[2], "a")) == NULL ){
    fprintf(stderr,  "Could not open output file\n");
    return -5;
  }

  files(argv[1], 0);
  fclose(file_output);
  return 0;
}

int dir_file(char *name){
  struct stat info;
  if( lstat(name, &info) < 0 )
    return -1;
  
  if( S_ISDIR(info.st_mode) )
    return 0;

  return -2;
}

void files(char *dir_name, int current_level){
  char path[PATH_MAX + NAME_MAX + 1];
  DIR *directory;
  struct dirent *direntry;
  struct stat info;

  if(current_level > max_level){
    fprintf(stderr, "Reached max allowed level\n");
    return; 
  }
  
  fprintf(stdout, "Working in %s\n", dir_name);
  directory = opendir(dir_name);

  while( (direntry = readdir(directory)) != NULL ){
    // Ignore . and ..
    if( strcmp(direntry->d_name, "..") != 0 && strcmp(direntry->d_name, ".") != 0 ){

      // Do path
      sprintf(path, "%s/%s", dir_name, direntry->d_name);
      lstat(path, &info);
      if( (info.st_mode & S_IFMT) != S_IFDIR ){ // Is file
        append(path);
      }else{ //Is dir
        files(path, current_level+1);
      }
    }
  }
}

void append(char * input_file){
  FILE *file_input;
  char buffer[MAX_BUFFER_SIZE];

  fprintf(stdout, "Openning %s ...\n", input_file);
  if( (file_input = fopen(input_file, "r")) == NULL ){
    fprintf(stderr,  "Could not open %s file\n", input_file);
    return;
  }
  fprintf(stdout, "Merging %s ...\n", input_file);
  while( fgets(buffer, MAX_BUFFER_SIZE, file_input) != NULL ){
    fputs(buffer, file_output);
  }
  fclose(file_input);
}
