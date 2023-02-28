#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	char str[100];
	const char d[2] = " ";
	char* token;
	int i = 0,times,lag;
	long int sum = 0, idle, lastSum = 0,lastIdle = 0;
	long double idleFraction;
	
	
    lag = 1;
    while(1){
        FILE* fp = fopen("/proc/stat","r");
        i = 0;
        fgets(str,100,fp);
        printf("%s", str);
        fclose(fp);
        token = strtok(str,d);
        sum = 0;
        while(token!=NULL){
            token = strtok(NULL,d);
            if(token!=NULL){
                sum += atoi(token);
        
            if(i==3)
                idle = atoi(token);
    
            i++;
            }
        }
        idleFraction = 100 - (idle-lastIdle)*100.0/(sum-lastSum);
        printf("Average CPU utilization was %Lf %% after last interval.\n", idleFraction);

        lastIdle = idle;
        lastSum = sum;
        times--;
        sleep(lag);
    }	
	
	return 0;
}