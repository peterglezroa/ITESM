/*====================================================================================================*
 Programación Avanzada
 ---------------------
 EXAMEN 1
 Pedro Luis González Roa A01651517
 10-03-2020
 *====================================================================================================*/
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
/*
 * Inputs:
 *  - Starting directory
 * Output:
 *  - Min number in files
 *  - Max number in files
 * Errors:
 *  - 
 * */
int dir_file(char * name);
int * min_max(int * array, char *file_name, char *program);
int * list(int * array, char *dir_name, char *program);

int main(int argc, char *argv[]){
  char dir_name[PATH_MAX+1];
  char *directory;

  int res[2];
  res[0] = 0;
  res[1] = 0;
  
  // Checar que sea sólo un argumento
  if(argc > 2){
    // 0 -> Nombre del programa
    // 1 -> Nombre del archivo
    fprintf(stderr, "usage: %s directory\n", argv[0]);
    return -1;
  }
  // Conseguir directorio actual
  getcwd(dir_name, PATH_MAX);
  directory = dir_name;
  if(argc == 2){
    directory = argv[1];
  }
  // Checar que sea un directorio
  if(dir_file(directory) == -1){ 
    fprintf(stderr, "%s: No such file or directory\n", argv[0]);
    return -2;
  }else if(dir_file(directory) != 0){
    fprintf(stderr, "%s: Not a directory\n", argv[0]);
    return -2;
  }
  list(res,directory,argv[0]);
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

int * list(int * array, char *dir_name, char *program){
  char path[PATH_MAX + NAME_MAX + 1];
  DIR *dir;
  struct dirent *direntry;
  struct stat info;
  
  dir = opendir(dir_name);

  printf("directory: %s\n", dir_name);
  // Min max de los archivos de este directorio
  while((direntry = readdir(dir)) != NULL){
// Luego quitar esto
    array[0] = 0; array[1] = 0;
    if(strcmp(direntry->d_name, "..") != 0 && strcmp(direntry->d_name, ".") != 0){ // Ignorar . y ..
      sprintf(path,"%s/%s",dir_name, direntry->d_name);
      lstat(path, &info);
      // Buscar en archivos
      if((info.st_mode & S_IFMT)!=S_IFDIR){ // Ignorar directorios
        array = min_max(array, path, program);
      }
    }
  }
  printf("\n");
  // Seguir de manera recursiva
//  if(recursive){
    rewinddir(dir);
    while((direntry = readdir(dir)) != NULL){
      if(strcmp(direntry->d_name, "..") != 0 && strcmp(direntry->d_name, ".") != 0){ // Ignorar . y ..
        sprintf(path,"%s/%s",dir_name, direntry->d_name);
        lstat(path, &info);
        // Buscar en archivos
        if((info.st_mode & S_IFMT)==S_IFDIR){ // Si es directorio, seguir buscando
          array = list(array, path, program);
        }
      }
    }
//  }
  return array;
}

int * min_max(int * array, char *file_name, char *program){
  int filedes, num;
  if((filedes = open(file_name, O_RDONLY)) < 0){
    fprintf(stderr, "%s: Could not open file\n", program);
    return array;
  }
  while(read(filedes, &num, sizeof(uint)) != 0){
    if(num > array[1]){ // Encontramos un número mayor
      array[1] = num; 
    }else if(num < array[0]){ // Encontramos un número menor
      array[0] = num;
    }
  }
  printf("%s - min = %i - max = %i\n", file_name, array[0], array[1]);
  close(filedes);
  return array;
}
