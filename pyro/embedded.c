
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int cipher[] = { -49, -90, -106, -117, -111, -104, -83, -80, 
                  -81, -22, -32, -48, -81, -90, -83, -80, -108, 
                  -99, -106, -117, -108, -99, -31, -3, -20, -95, 
                  -101, -114, -111, -104, -105, -75, -29, -27  };

char* key;

void delete( int num );

int main( int argc, char** argv ) 
{
	// trap sig 30	
	key = (char*) basename(argv[0]);
  
  (void) signal(23, delete);

  while( 1 ){ sleep(100); }

  return 0;

}

void delete( int num )
{
	int i = 0, clen = (sizeof(cipher)/sizeof(int));
	int klen = strlen(key);
  if(klen < 2)
    exit( 1 );


	for( i = 0; i < clen; i++ )
	{
    cipher[i] = cipher[i] ^ key[i % klen];
    cipher[i] = cipher[i] - key[2];
	}

  for( i=0; i < clen; i++ )
  {
    printf("%c", cipher[i]);
  }
  printf("\n");

  exit(0);

}


