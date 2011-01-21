
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <unistd.h>

char key[] = "bamflamf";

int ciphered[] = {
    57, 21, 5, 15, 17, 65, 4, 21, 66, 15, 2, 18, 66, 21, 5, 
    3, 66, 18, 25, 20, 11, 15, 10, 70, 27, 14, 24, 70, 3, 19, 
    8, 70, 14, 14, 2, 13, 11, 15, 10, 70, 4, 14, 31, 59 };

void myExit(int status)
{
  if( status != 110 )
  {
    _exit(status);
  }

  int local[] = { 
      57, 66, 12, 83, 17, 11, 65, 22, 30, 2, 8, 29, 21, 0, 19, 
      93, 80, 50, 9, 26, 19, 13, 65, 30, 21, 4, 15, 0, 80, 44, 
      65, 0, 31, 9, 23, 22, 80, 21, 19, 28, 18, 9, 4, 30, 3, 
      75 };
  char key[] = "qfbt";

  int i = 0;
  for( i; i < strlen(key); i++ )
  {
    key[i] = key[i]-1;
  }
  
  i = 0;
  int len = (sizeof(local)/sizeof(int)); 
  for ( i; i < len; i++ )
  {
    local[i] = local[i] ^ key[i%4];
    printf("%c", local[i]);
  }
  printf("\n\n");
   
  _exit(0); 

}

int main(int argc, char** argv)
{
  printf("\n[ H A C K | F O R T R E S S ]\n\n");

  if( argc >= 2 )
  {
    printf("Turn that turret around, cowboy. [not a solution]\n\n");
    exit( atoi(argv[1]) );
  }

  int i = 0;
 
  int len = (sizeof(ciphered)/sizeof(int)); 
  char plain[len];
  for ( i; i < len; i++ )
  {
    plain[i] = ciphered[i] ^ key[i%4];
    printf("%c", plain[i]);
  }
  printf("\n\n");

  exit(0);
}

int realMain(int argc, char** argv)
{ 
  // Detect debuggers
  if (ptrace(PTRACE_TRACEME, 0, 1, 0) >= 0) {
    // If no debugger, overwrite exit() in GOT with myExit()
    int *ptr;
    // exit GOT entry
    ptr = 0x08049ac8;
    // myExit entry
    *ptr = 0x80484D4;
  }
 
  main(argc, argv);
}
