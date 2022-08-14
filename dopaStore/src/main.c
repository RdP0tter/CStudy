#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define INITIAL_MONEY 100
#define VERSION 1.0f
#define PROJECT_NAME "Dopamine Store"

typedef struct User{
  
  int walletSize;
  char userName[50];

}User;

void printProject();
void initialPage(char products[3][20]);
void userInfo(User player);
void store(User player);

int main(){

  User player;
  player.walletSize = INITIAL_MONEY; 

  if(!(player.walletSize == INITIAL_MONEY)){
    printf("Tamanho inicial da carteira incorreto.");
    return 0;
  }

  printProject();

  printf("Enter your name to start the store: ");
  scanf("%s", player.userName); 

  system("clear");

  store(player);
  
return 0;

}

void store(User player){

  int userInput = 1;
  char products[3][20] = { "Dopamine",
                        "Serotonine",
                        "Noradrenaline" };
  
  initialPage(products);
  userInfo(player);
  
  do{
    printf("Which product would you like to buy?: (press 4 to quit)\n");
    scanf("%d", &userInput);
    if(!(isdigit(userInput))){
      printf("Invalid input");
      break;
    }

    switch(userInput){

      case 1:
        player.walletSize -= 50;
        printf("\nYou bought the product %s and your balance now is: %d\n\n", products, player.walletSize);
      break;

      case 2: 
        player.walletSize -= 15;
        printf("\nYou bought the product %s and your balance now is: %d\n\n", products+1, player.walletSize);
      break;

      case 3:
        player.walletSize -= 10;
        printf("\nYou bought the product %s and your balance now is: %d\n\n", products+2, player.walletSize);
      break;

      case 4:
        printf("\nGoodbye!\n");
        exit(1);
      break;

      default:
      printf("\nYou bought nothing\n\n");
    }
    
    if(player.walletSize > 0){
      initialPage(products);
    } else {
      printf("You're broke! Get out of here!");
      exit(1);
    }

  } while (player.walletSize);
}
void printProject(){

  printf("Welcome to %s version %.1f\n\n", PROJECT_NAME, VERSION);

}

void initialPage(char products[3][20]){

  printf("Products:\n1 - %s R$50\n2 - %s R$15\n3 - %s R$10\n\n", products, products+1, products+2);
}

void userInfo(User player){
  
  printf("%s Your Balance is: %d\n\n", player.userName,player.walletSize);

}
