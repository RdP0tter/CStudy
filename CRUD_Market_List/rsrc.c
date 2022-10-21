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
    
    //uint64_t siz = 0;
    FILE *fp;  
    uint64_t txt_siz = strlen(file->str);

    if(!file->filepath)
      fatal_error("The file don't exist. Please use \"create\" instead. Exiting...");
    else if((file_size(file->filepath)) == 0){
          printf("File is empty.. Writing at beginning.. ");
          fp = fopen(file->filepath, "w");
          
          if((fwrite(file->str, txt_siz, 1, fp)) != 1){
            fatal_error("Unable to write to file. Exiting...");
          } else {
            printf("String written to file succeeded.\n");
          }

          fclose(fp);  
     } else {
          fatal_error("File not empty.. Exiting..");
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
