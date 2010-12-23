#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getKey(int* key);
void xor(char* buf, const char* text, const int* key, int keylen);


int main(int argc, char** argv)
{

	if( argc < 2 )
	{
		printf("\n[ H A C K | F O R T R E S S ]\n\n");
		printf("We've intercepted a secret message, but can't decrypt it.\n");
		printf("If you provide us with the right key, we'll help your team!\n\n");
		return;
	}

	char cipherText[] = "*dfqcykjp``dn #icmznkeo`p%#-plbi+)ndlbjinlq+";
	
	int* key = malloc( strlen(argv[1]) * sizeof(int) );

	if( key == NULL )
	{
		perror("malloc fail :(");
		return 1;
	}

	
	int i = 0;
	for( i; i < strlen(argv[1]); i++ )
	{
		key[i] = argv[1][i]-48;		
	}	

	printf("%s\n", key);

	__asm__("NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP");	
//	getKey(key);

	char buf[64];
	
	xor(buf, cipherText, key, strlen(argv[1])); 
	printf("If the result looks right, MD5 your result and submit it:\n");
	printf("%s\n", buf);

	free(key);
	key = NULL;
}

void getKey(int* key)
{
	char buf[64];
	double approx = (double)22/7;
	snprintf(buf, 64, "%1.64f", approx);
	
	int i = 37;
	for( i; i < 41; i++ )
	{
		key[i-37] = buf[i]-48;
	} 

	return;
}


void xor(char* buf, const char* text, const int* key, const int keylen)
{
	int i = 0;
	for( i; i < strlen(text); i++ )
	{
		buf[i] = text[i] ^ key[i%keylen];
	}
	return;	
}
