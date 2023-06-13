#include <stdio.h>
#include <string.h>

void swap(char *x, char *y){
	char temp = *x;
	*x=*y;
	*y=temp;
}

void reverse(char str[]){
	int len=strlen(str) - 1;

	for (int i=0;i<len/2;i++){
		swap(&str[i], &str[len-i]);
	}
}

int main(int argc, char **argv){
	char* temp="temp.txt";
	FILE* fp1=fopen(argv[1], "r");
	FILE* fp2=fopen(temp, "w");

	char fileStr[65536];

	while (fscanf(fp1, fileStr) != 0){
		reverse(fileStr);
		fprintf(fp2, "%s", fileStr);
	}
	fclose(fp1);
	fclose(fp2);
	remove(argv[1]);
	rename(temp, argv[1]);

	return 0;

}


