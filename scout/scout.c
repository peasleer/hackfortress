
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Macro taken from Chapter 12 of C/C++ Secure Programming
#define DISASM_FALSERET asm volatile (               \
            "  pushl %ecx        /* save registers    */\n" \
            "  pushl %ebx                               \n" \
            "  pushl %edx                               \n" \
            "  movl  %esp, %ebx  /* save ebp, esp     */\n" \
            "  movl  %ebp, %esp                         \n" \
            "  popl  %ebp        /* save old %ebp     */\n" \
            "  popl  %ecx        /* save return addr  */\n" \
            "  lea   0f, %edx    /* edx = addr of 0:  */\n" \
            "  pushl %edx        /* return addr = edx */\n" \
            "  ret                                      \n" \
            "  .byte 0x0F        /* off-by-one byte   */\n" \
            "0:                                         \n" \
            "  pushl %ecx        /* restore ret addr  */\n" \
            "  pushl %ebp        /* restore old &ebp  */\n" \
            "  movl  %esp, %ebp  /* restore ebp, esp  */\n" \
            "  movl  %ebx, %esp                         \n" \
            "  popl  %ebx                               \n" \
            "  popl  %ecx                               \n")

void doPrint(int c);

char banner[] = "[ H A C K | F O R T R E S S ]\n\n";

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

int newMain(int argc, char** argv)
{
 
  DISASM_FALSERET;
  if( argc < 16 || !( argv[1][0] == banner[2]+1 && argv[2][0] == banner[4]+1 ) )
  {
    //printf("argc: %i, argv[1][0]: %c, argv[2][0]: %c\n", argc, argv[1][0], argv[2][0]);
    main(argc, argv);
  }

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

  // Print "\t*Bonk!*\n\n"
  printf("%c%c%c%c%c%c%c%c%c%c",b-a,d-a,e-a,h-a,g-a,f-a,i-a,d-a,c-a,c-a);
  exit(0);
}


void doPrint(int c)
{
  printf("%c", c);
}
