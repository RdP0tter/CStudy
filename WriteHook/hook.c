#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

  if(argc == 2){
    if(strcmp(argv[1], "Testing") == 0){
      write(1, "Testing", 7);
    }
  }

}
