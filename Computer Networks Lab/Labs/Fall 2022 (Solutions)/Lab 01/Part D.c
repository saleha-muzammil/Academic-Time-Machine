#include <stdio.h>
#include <string.h>

void invert(int s, int e, char* str);

int main()
{
	FILE *read3 = fopen("Input File.txt", "r");
	FILE *write3 = fopen("Part D.txt", "w"); 
	
	while(1)
	{
		char buff[200];
		int dum = fscanf(read3, "%s", buff);
		
		if (dum == EOF)
			break;
		
		int i = 0;
		int check = 0;
		for(i = 0; buff[i] != '\0'; i++)
		{
			if ((buff[i] == 'a') || (buff[i] == 'e') ||
			 (buff[i] == 'i') || (buff[i] == 'o') || (buff[i] == 'u') || 
			 (buff[i] == 'A') || (buff[i] == 'E') ||
			 (buff[i] == 'I') || (buff[i] == 'O') || (buff[i] == 'U'))
				check = 1;
		}
		
		if (check)
		{
			int length_of_string = strlen(buff) - 1;
			invert(0, length_of_string, buff);
		}
		fputs(buff, write3);
		fputc(' ', write3);
	}
	
	fclose(read3);
	fclose(write3);
	return 0;
}

void invert(int s, int e, char* str)
{
	if (s >= e)
		return;
	else
	{
		invert(s+1, e-1, str);
		char dum = str[s];
		str[s] = str[e];
		str[e] = dum;
	}
}

