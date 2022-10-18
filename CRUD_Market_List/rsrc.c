#include "rsrc.h"

void fatal_error(const char *str){
    fprintf(stderr, "Fatal Error: %s\n", str);
    exit(-1);
}

void error(const char *str){
    printf("Error: %s\n", str);
}

void create(struct file_opt *file){
  FILE *f;

  if((f = fopen(file->filepath, "r")) == NULL)
    f = fopen(file->filepath, "w+"); 

}

void read(struct file_opt *file){ 
  if(!file->filepath)
    fatal_error("The file don't exist. Please use \"create\" instead. Exiting...");
  else {
    char *str = NULL;
    uint64_t siz = 0;
    FILE *fp;
    
    fp = fopen(file->filepath, "r");
    
    fseek(fp, 0L, SEEK_END);
    siz = ftell(fp);
    rewind(fp);
    
    str = (char*) malloc(siz); 
    fread(str, siz, 1, fp);
    
    printf("%s", str);
    fclose(fp);
  }
}

void delete_file(struct file_opt *file){

  if(!file->filepath)
    fatal_error("File don't exist. Exiting...");
  else{
    if(remove(file->filepath) == 0){
      printf("File deleted...\n");
    } else {
      fatal_error("Failed to delete file");
    }
  }
}
