#include <stdio.h>
#include <string.h>

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int main(){
	FILE* fp=fopen("Input_File.txt", "r");
	char buff[255];
	int len, i, check;
	FILE* fp2=fopen("data3.txt", "w");
	while (fscanf(fp, "%s", buff)!=EOF){
		len=strlen(buff);
		i=0;
		check=1;
		while (i<len){
			if (buff[i]=='a'||buff[i]=='e'||buff[i]=='i'||buff[i]=='o'||buff[i]=='u'||buff[i]=='A'||buff[i]=='E'||buff[i]=='I'||buff[i]=='O'||buff[i]=='U'){
				check=0;
			}
			i++;

		}
		if (!check){
			strrev(buff);
		}
		printf("%s ", buff);
		fputs(buff, fp2);
		fputc(' ', fp2);
	}
	return 0;
}
