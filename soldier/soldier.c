
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

int main(int argc, char** argv)
{
 
  printf("[ H A C K | F O R T R E S S ]\n\n");

  FILE *fpipe;
  char command[64];
  char out[256];
 
  char cmd[] = "PuppySnuggy\n";

  int pid = getpid();
 
  snprintf(command, sizeof(out), "basename `cat /proc/%d/cmdline`", pid);

  fpipe = (FILE*) popen(command, "r");

  fgets( out, sizeof out, fpipe );

  if( strcmp( out, cmd ) == 0 )
  {
    int ciphered[] = { 50, 94, 7, 73, 7, 30, 28, 93, 67, 29, 9, 13, 7, 16, 7, 
      8, 24, 76, 21, 95, 17, 30, 0, 30, 23, 16, 2, 7, 24, 76, 
      7, 89, 14, 12, 65, 13, 83, 82, 22, 7, 2, 4, 83, 95, 5, 
      73, 0, 2, 26, 93, 2, 5, 18, 76, 18, 66, 6, 73, 6, 13, 
      7, 88, 6, 27, 4, 8, 83, 89, 13, 73, 14, 2, 22, 16, 19, 
      5, 0, 15, 22, 16, 10, 29, 70, 31, 83, 83, 2, 5, 13, 9, 
      23, 16, 2, 73, 27, 3, 28, 30 };

    char key[] = "s0cial";

    int i = 0;
    for ( i; i < (sizeof(ciphered)/sizeof(int)); i++ )
    {
      ciphered[i] = ciphered[i] ^ key[i%strlen(key)];
      printf("%c", ciphered[i], ciphered[i]);
    }
    printf("\n\n");
  }
  else
  {
    printf("Sun Tzu knows more about war than you.\n\n");
  }

  pclose(fpipe);

  return 0;
  
}


