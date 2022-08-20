#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void error(char str[]){
  fprintf(stderr, "Error: %s\n",str);
  exit(3);
}

int str_length(char str[]){  
  int count;

  for(count=0;str[count]!='\0';count++);  

  return count;
}

int main(int argc, char *argv[]){

    if(argc > 2){
      error("Too many arguments");
    } else if(argc<=1){
      error("You should use at least one argument!");
    } else if(isdigit(*argv[1])){
      error("Argument must be a string.");
    }
  
  int length;
  length = str_length(argv[1]);
  printf("Your string size is %d\n", length);

  return 0;
}
