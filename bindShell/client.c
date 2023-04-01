#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 5555

#define herror(msg)\
   do{perror(msg);exit(EXIT_FAILURE);}while(0)

int main(){

  int sockfd;
  struct sockaddr_in servaddr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0){
    herror("Failed to create socket\n");
  }

  memset(&servaddr, 0, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(PORT);

  if(( sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr) )!=0){
    herror("Connection with server failed.\n");
  } else {
    printf("Connection successfull");
  }


}
