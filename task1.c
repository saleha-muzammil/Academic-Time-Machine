#include <stdio.h>

int main(){
	FILE* fp=fopen("Input_File.txt", "r");
	char buff[255];
	while (fscanf(fp, "%s", buff)!=EOF){
		printf("%s ", buff);
	}
	return 0;
}
