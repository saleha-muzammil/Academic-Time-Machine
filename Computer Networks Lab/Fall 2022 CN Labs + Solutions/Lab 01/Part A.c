#include <stdio.h>

int main()
{
	FILE *read = fopen("Input File.txt", "r");
	
	while(1)
	{	
		int dum = fgetc(read);
		
		if (dum == EOF)
			break;
			
		char c = (char)dum;
		printf("%c", c);
	}
	
	fclose(read);
	return 0;
}
