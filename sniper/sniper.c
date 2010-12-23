#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void deleteMe(char* name);
void saveMe();

int main( int argc, char** argv )
{
	// Decoy 
	char* victory="[Victory:] One shot, one kill";

	if( argc > 0 )
	{
		deleteMe(argv[0]);
	}

	return 0;

}

void saveMe()
{
	char str[] = "Ticqox&mwr!uwesjpvg!uwmqr3(wbpniw\'";
	int i = strlen(str);
	for( i; i > 0; i-- )
	{
		str[i]=str[i]-i%9;	
	}

	printf("\n[ H A C K | F O R T R E S S ]\n\n");
	printf("%s\n\n", str);
	exit(0);
}

void deleteMe( char* name )
{
	remove( name );
	printf("\n[ H A C K | F O R T R E S S ]\n\n");
	printf("A spy stabs you in the back, your team fights unaided :(\n\n");
	return;
}

