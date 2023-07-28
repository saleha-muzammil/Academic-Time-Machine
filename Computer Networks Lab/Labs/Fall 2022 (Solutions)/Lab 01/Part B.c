#include <stdio.h>

int main()
{
	FILE *read = fopen("Input File.txt", "r");
	FILE *write = fopen("Part B.txt", "w"); 
	
	while(1)
	{	
		int dum = fgetc(read);
		
		if (dum == EOF)
			break;
			
		char c = (char)dum;
		
		if (dum >= 48 && dum <= 57)
		{
			fputc(c, write);
			fputc(' ', write);
		}
	}
	
	fclose(read);
	fclose(write);
	return 0;
}
