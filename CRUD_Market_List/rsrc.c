#include "rsrc.h"

static uint64_t file_size(char *filepath){ 
    uint64_t res = 0;
    FILE *fp;

    fp = fopen(filepath, "r");
    fseek(fp, 0L, SEEK_END);
    res = ftell(fp);
    fclose(fp);

    return res;
}

void fatal_error(const char *str){
    fprintf(stderr, "Fatal Error: %s\n", str);
    exit(-1);
}

void error(const char *str){
    printf("Error: %s\n", str);
}

void create(struct file_opt *file){
  FILE *fp;

  if((fp = fopen(file->filepath, "r")) == NULL)
    fp = fopen(file->filepath, "w+"); 

  fclose(fp);
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

void update(struct file_opt *file){
    
    uint64_t siz = 0;
    FILE *fp;  

    if(!file->filepath)
      fatal_error("The file don't exist. Please use \"create\" instead. Exiting...");
    else {
      siz = file_size(file->filepath);
      printf("%ld\n", siz);
    }

}

void delete_file(struct file_opt *file){

    if(!file->filepath)
      fatal_error("The file don't exist. Please use \"create\" instead. Exiting...");
    else{
      if(remove(file->filepath) == 0){
        printf("File deleted...\n");
      } else {
        fatal_error("Failed to delete file");
      }
    }
}
