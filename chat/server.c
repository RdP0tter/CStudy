#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

void error(char *msg){
  perror(msg);
  exit(1);
}

void chat(int sockfd){
  char buf[256];
  int n;

  while(true){
    bzero(&buf, sizeof(buf));
    n = read(sockfd, &buf, sizeof(buf));
    if(n < 0)
      error("Failed to read from socket.\n");
    fprintf(stdout, "Recebido: %s\n", buf);

    bzero(&buf, sizeof(buf));
    printf("Enviado: ");
    fgets(buf, sizeof(buf)-1, stdin);
    write(sockfd, &buf, sizeof(buf));
  }
  
  close(sockfd);
}

int main(int argc, char *argv[]){

  if(argc != 2){
    fprintf(stderr, "you should only give a port.\n");
    exit(1);
  }

  int newsockfd, sockfd, clilen, n;
  struct sockaddr_in serv_addr, cli_addr;
  int portno = atoi(argv[1]);

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    error("Error creating the server socket.\n");
  
  bzero((char*)&serv_addr, sizeof(serv_addr));
  bzero((char*)&cli_addr, sizeof(cli_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("Error binding.\n");

  listen(sockfd, 5);

  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
  if(newsockfd < 0)
    error("Error on accept.\n");
  
  chat(newsockfd);

  close(sockfd);
  
return 0;
}

