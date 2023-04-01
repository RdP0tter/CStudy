#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]){

    FILE *fh = fopen(argv[1], "rb");
    
    if(!fh){
      puts("Error opening the file");
      exit(1);
    }

    char byte;

    while(fread(&byte,sizeof(byte),1,fh) != 0){
      if(byte==0x474e5089)
        puts("PNG");

    }
    
    printf("\n");

  return 0;
}

//fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
