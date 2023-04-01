#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <netdb.h>

#define SERVER_PORT "5555"

void error(char *msg){
  perror(msg);
  exit(1);
}

void chat(int sockfd){

  char buf[256];
  int n;

  while(true){
    bzero(&buf, sizeof(buf));
    printf("Enviado: ");
    fgets(buf, sizeof(buf)-1, stdin);
    write(sockfd, &buf, sizeof(buf));


    n = read(sockfd, &buf, sizeof(buf));
    if(n < 0)
      error("Failed to read from socket.\n");
    fprintf(stdout, "Recebido: %s\n", buf);
    
  }
  
  close(sockfd);

}

int main(int argc, char *argv[]){

  int sockfd, status;
  struct sockaddr_in serv_addr;
  struct addrinfo hints;
  struct addrinfo *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
      error("Error creating socket for client.\n");


  bzero((char*)&hints, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if((status = getaddrinfo(argv[1], SERVER_PORT, &hints, &server)) != 0){
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(1);
  }

  memcpy(&serv_addr, server->ai_addr, sizeof(serv_addr));
  freeaddrinfo(server);

  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0)
    error("Error connecting to server.\n");

  chat(sockfd);

}
