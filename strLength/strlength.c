#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int str_length(char str[]){
  
  int count;

  for(count=0;str[count]!='\0';count++);  

  return count;
}

int main(int argc, char *argv[]){

    if(argc > 2){
      fprintf(stderr, "Too many arguments\n");
      exit(1);
    } else if(argc<=1){
      fprintf(stderr,"You should use at least one argument!\n");
      exit(1);
    } else if(isdigit(*argv[1])){
      fprintf(stderr,"Argument must be a string.\n");
      exit(1);
    }
  
  int length;
  length = str_length(argv[1]);
  printf("Your string size is %d\n", length);

  return 0;
}
