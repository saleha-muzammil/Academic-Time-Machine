#include <stdio.h>

int main()
{
	FILE *read2 = fopen("Input File.txt", "r");
	FILE *write2 = fopen("Part C.txt", "w"); 
	
	while(1)
	{
		char buff[200];
		int dum = fscanf(read2, "%s", buff);
		
		if (dum == EOF)
			break;
		
		int i = 0;
		int check = 1;
		for(i = 0; buff[i] != '\0'; i++)
		{
			if ((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))
				check = 0;
		}
		
		if (check)
		{
			fputs(buff, write2);
			fputc(' ', write2);
		}
	}	
	
	fclose(read2);
	fclose(write2);
	return 0;
}
