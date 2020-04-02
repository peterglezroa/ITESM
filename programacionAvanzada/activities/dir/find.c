/*
 * Programación avanzada
 * Manejo de directorios
 * Pedro Luis González Roa A01651517
 * Diana Estefanía Ortiz A1209403
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>

int dir_file(char * name);
int list(char *string, char *dir_name, int recursive, char *program);
int find(char *string, char *file_name, char *program);

int main(int argc, char *argv[]){
  char dir_name[PATH_MAX+1];
  char *directory;
  int recursive = 0;

  if(argc > 4 || argc < 2){
    fprintf(stderr, "usage: %s string initial_directory [-r]\n", argv[0]);
    return -1;
  }

  // Dir actual
  getcwd(dir_name, PATH_MAX);
  directory = dir_name;
  if(argc == 3){
    if(strcmp("-r", argv[2]) == 0){
      recursive = 1;
    }else{
      directory = argv[2];
    }
  }else if(argc == 4){
    directory = argv[2];
    if(strcmp("-r", argv[3]) == 0){
      recursive = 1; 
    }else{
      fprintf(stderr, "%s: Not a valid flag\n", argv[0]);
      return -2;
    }
  }

  // Checar Dir
  if(dir_file(directory) == -1){
    fprintf(stderr, "%s: No such file or directory\n", argv[0]);
    return -3;
  }else if(dir_file(directory) != 0){
    fprintf(stderr, "%s: Not a directory\n", argv[0]);
    return -4;
  }
  if(!list(argv[1],directory,recursive,argv[0]))
    printf("Could not find the string \"%s\" in the directory %s\n", argv[1], directory);
  return 0;
}

int list(char *string, char *dir_name, int recursive, char *program){
  char path[PATH_MAX + NAME_MAX + 1];
  DIR *dir;
  struct dirent *direntry;
  struct stat info;
  struct tm *time;
  int found = 0;
  char date[50];
  
  dir = opendir(dir_name);

//  printf("directory: %s\n", dir_name);

  while((direntry = readdir(dir)) != NULL){
    if(strcmp(direntry->d_name, "..") != 0 && strcmp(direntry->d_name, ".") != 0){ // Ignorar . y ..
      sprintf(path,"%s/%s",dir_name, direntry->d_name);
      lstat(path, &info);
      if((info.st_mode & S_IFMT)!=S_IFDIR){ // buscar en archivo
        if( find(string, path, program) )
          found = 1;

          printf("Name: %s\n", direntry->d_name);
          printf("Path: %s\n", dir_name);

          time = localtime(&info.st_mtime);
          strftime(date, 50, "%a %b %d %R:%S %Y", time); // fecha time access
          printf("Last access: %s\n", date);

          time = localtime(&info.st_atime);
          strftime(date, 50, "%a %b %d %R:%S %Y", time); // fecha time mod
          printf("Last modification: %s\n\n", date);
      }else if(recursive){ // buscar en directorio
        if( list(string, path, recursive, program) )
          found = 1;
      }
    }
  }
  printf("\n");
  return found;
}

int find(char *string, char *file_name, char *program){
//  printf("%s:\n", file_name);
  int filedes, pointer = 0, string_len = strlen(string)-1;
  char chr;
  if((filedes = open(file_name, O_RDONLY)) < 0){
    fprintf(stderr, "%s: Could not open file\n", program);
    return 0;
  }
  while(read(filedes, &chr, sizeof(char)) != 0){
    if( chr == string[pointer] ){
      if(pointer == string_len){
        return 1;
      }else
        pointer++;
    }else
      pointer = 0; 
  }
  close(filedes);
  return 0;
}

int dir_file(char *name){
  struct stat info;
  // Checar si existe
  if(lstat(name, &info) < 0){
    return -1;
  }
  // Checar si es directorio
  if(S_ISDIR(info.st_mode)){
    return 0;
  }else{
    return -2;
  }
}
