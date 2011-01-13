#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int r[3652];

void readFile(char *inName, char *outName);

int main(int argc, char** argv)
{

  readFile("embedded", "out.bin"); 

}

void readFile(char *inName, char *outName)
{
  FILE *in, *out;
  unsigned long fileLen;

  //Open file
  in = fopen(inName, "rb");
  if (!in)
  {
    fprintf(stderr, "Unable to open file %s", inName);
    return;
  }
  
  out = fopen( outName, "ab" );
  if (!out)
  {
    fprintf(stderr, "Unable to open file %s", outName);
  }
  
  //Get file length
  fseek(in, 0, SEEK_END);
  fileLen=ftell(in);
  fseek(in, 0, SEEK_SET);

  //Read file contents into buffer
  fread(r, fileLen, 1, in);
  
  fclose(in);

  int i = 0;
  printf("%i\n", (sizeof(r)/sizeof(int)));
  for( i; i < (sizeof(r)/sizeof(int)); i++ )
  {
    r[i]=(r[i]+31337);
  }

  fwrite(r, fileLen, 1, out);

  fclose(out);

}

void writeFile(char *outName)
{

}

