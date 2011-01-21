
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
  printf( "[ H A C K | F O R T R E S S ]\n\n" );
  
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) 
    exit(2);

  int a = 0x08048444;
  int b = 0x08045168;

  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(a-b);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
  {
    close(sockfd);
    exit(3);
  }

  listen(sockfd,5);
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

  if (newsockfd < 0) 
  {
    close(sockfd);
    exit(4);
  }

  bzero(buffer,256);

  int n = read(newsockfd,buffer,255);

  if (n < 0)
  {
    close(newsockfd);
    close(sockfd);

    exit(5);
  }

  if( strcmp("eyelander\n", buffer) !=0 )
  {
    char ret[]="So close, yet not close at all. [not a victory string]\n";
    write(newsockfd,ret,strlen(ret));
  }
  else
  {
    int ciphered[] = { 36, 21, 9, 76, 14, 78, 29, 4, 82, 4, 11, 0, 76, 5, 15, 
      10, 1, 27, 0, 10, 73, 76, 17, 28, 5, 11, 17, 12, 23, 69, 
      13, 3, 1, 17, 17, 82, 18, 16, 17, 4, 65, 23, 11, 16, 0, 
      69, 17, 0, 13, 5, 29, 68, 3, 7, 9, 21, 69, 3, 7, 78, 
      1, 28, 23, 7, 24, 9, 0, 18, 79 };

    int i = 0;
    for( i; i < (sizeof(ciphered)/sizeof(int)); i++ )
    {
      ciphered[i] = ciphered[i] ^ buffer[i%9];
      printf("%c", ciphered[i]);
    }
    printf("\n");
    write(newsockfd,"\n", 1);
    n = write(newsockfd,ciphered,(sizeof(ciphered)/sizeof(int)) );
    write(newsockfd,"\n\n", 2);
    printf("sent: %i, size:%i\n", n, (sizeof(ciphered)/sizeof(int)));
  }

  close(newsockfd);
  close(sockfd);

  return 0;
}
