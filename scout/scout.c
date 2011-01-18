
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void doPrint(int c);

char banner[] = "[ H A C K | F O R T R E S ]\n\n";

int main(int argc, char** argv)
{

  char key[] = {'l','u','l','z'};
  int ciphered[] = { 24, 7, 21, 90, 13, 18, 13, 19, 2, 74, 76, 36, 51, 43 };
  int i = 0;
 
  printf("%s", banner);

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
  if( argc < 16 || !( argv[1][0] == banner[2]+1 && argv[2][0] == banner[4]+1 ) )
  {
    main(argc, argv);
  }

  // Print "\t*Bonk!*\n\n"
  printf("%s", banner);

  unsigned int a = 0x8048690; // +0
  unsigned int b = 0x8048699; // +9
  unsigned int c = 0x804869A; // +10 / A
  unsigned int d = 0x80486BA; // +42 / 2A
  unsigned int e = 0x80486D2; // +66 / 42
  unsigned int f = 0x80486FB; // +107 / 6B
  unsigned int g = 0x80486FE; // +110 / 6E
  unsigned int h = 0x80486FF; // +111 / 6F
  unsigned int i = 0x80486B1; // +33 / 21

  printf("%c%c%c%c%c%c%c%c%c%c",b-a,d-a,e-a,h-a,g-a,f-a,i-a,d-a,c-a,c-a);
  exit(0);
}


void doPrint(int c)
{
  printf("%c", c);
}
