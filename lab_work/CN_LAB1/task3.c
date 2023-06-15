#include <stdio.h>
#include <string.h>

int main(){
	FILE* fp=fopen("Input_File.txt", "r");
	char buff[255];
	int len, i, check;
	FILE* fp2=fopen("data2.txt", "w");
	while (fscanf(fp, "%s", buff)!=EOF){
		len=strlen(buff);
		i=0;
		check=1;
		while (i<len){
			if (buff[i]>='a'&&buff[i]<='z'||buff[i]>='A'&&buff[i]<='Z'){
				check=0;
			}
			i++;
			
		}
		if (check){
			printf("%s ", buff);
			fputs(buff, fp2);
			fputc(' ', fp2);
		}
		
	}
	return 0;
}
