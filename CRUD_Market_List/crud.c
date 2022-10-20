#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rsrc.h"

// ./main file argument string

int main(int argc, char *argv[]){

  if(argc != 4)
    fatal_error("Invalid number of arguments");
  
  struct file_opt file = {argv[1], argv[2], argv[3]};
   
  if(strcmp(file.crud_arg, "create") == 0) 
      create(&file);  
  
  if(strcmp(file.crud_arg, "read") == 0)
      read(&file);
  
  if(strcmp(file.crud_arg, "update") == 0)
      update(&file); 

  if(strcmp(file.crud_arg, "delete") == 0)
      delete_file(&file);
  
  return 0;
}
