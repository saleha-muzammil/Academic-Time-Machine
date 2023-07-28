#include <stdio.h>

int main()
{
	unsigned short dum = 0x3412;
	char *var = (char*) &dum;
	
	if (*var == 0x12)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
		
	return 0;
}
