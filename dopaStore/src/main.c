#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <stdint.h>

#define INITIAL_MONEY 100
#define VERSION 1.0f
#define PROJECT_NAME "Dopamine Store"

void printProject();
void initialPage();

typedef struct Wallet{
  
  int walletSize;

}Wallet;

int main(){

  Wallet p1;
  p1.walletSize = INITIAL_MONEY;

  if(!(p1.walletSize == INITIAL_MONEY)){
    printf("Tamanho inicial da carteira incorreto.");
    return 0;
  }

printProject();
initialPage();

return 0;

}

void printProject(){

  printf("Welcome to %s version %.1f\n\n", PROJECT_NAME, VERSION);

}

void initialPage(){

  char products[3][20] = { "Dopamine",
                        "Serotonine",
                        "Noradrenaline" };

 printf("%s\n%s\n%s", products, products+1, products+2);

}


