#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	//printf("%s", argv[1]);
	char c;
	int count=0;
	FILE *fp=fopen(argv[1], "r");
	while (1){
		c=fgetc(fp);
		if (c==EOF){
			break;
		}
		else 
		{
			if (c>='0' && c<='9'){
				count++;
			}
		}
	}	
	
	fclose(fp);
	printf("Number of digits is %d", count);

	return 0;
}
