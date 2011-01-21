
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Key: qRtu
int ciphered[] = { 52, 60, 0, 28, 3, 55, 84, 1, 20, 51, 25, 85, 24, 33, 84, 
                   23, 16, 48, 29, 16, 2, 115 };

int main(int argc, char** argv)
{
  printf( "[ H A C K | F O R T R E S S ]\n\n" );
  
  if( argc < 5 )
  {
    printf("Usage: %s <char 1> <char 2> <char 3> <char 4>\n\n", argv[0]);
    exit(1);
  }

  int i = 0;

  char key[4] = { argv[1][0], argv[2][0], argv[3][0], argv[4][0] };

  for( i; i < (sizeof(ciphered)/sizeof(int)); i++ )
  {
    ciphered[i] = ciphered[i] ^ key[i%4];
    printf("%c", ciphered[i]);
  }
  printf("\n\n");

  return 0;
}
