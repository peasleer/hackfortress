
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void doPrint(int c);
void banner();

int main(int argc, char** argv)
{

  char key[] = {'l','u','l','z'};
  int ciphered[] = { 24, 7, 21, 90, 13, 18, 13, 19, 2, 74, 76, 36, 51, 43 };
  int i = 0;
 
  banner();
  for ( i; i < (sizeof(ciphered)/sizeof(int)); i++ )
  {
    ciphered[i] = ciphered[i] ^ key[i%4];
    doPrint(ciphered[i]);
  }
  printf("\n\n");

  exit(0);
}

int lol(int argc, char** argv)
{
  if( argc < 16 )
  {
    main(argc, argv);
  }
  banner(); 
  // Print "\t*Bonk!*\n\n"
  doPrint(9);
  doPrint(42);
  doPrint(66);
  doPrint(111);
  doPrint(110);
  doPrint(107);
  doPrint(33);
  doPrint(42);
  doPrint(10);
  doPrint(10);
  exit(0);
}

void banner()
{
  printf("[ H A C K | F O R T R E S ]\n\n");
}

void doPrint(int c)
{
  printf("%c", c);
}
