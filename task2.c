#include <stdio.h>

int main(){
	FILE* fp=fopen("Input_File.txt", "r");
	char buff=fgetc(fp);
	FILE* fp2=fopen("data.txt", "w");
	while (buff!=EOF){
		if (buff>='0'&&buff<='9'){
			printf("%c ", buff);
			fputc(buff, fp2);
		}
		buff=fgetc(fp);
	}
	return 0;
}
