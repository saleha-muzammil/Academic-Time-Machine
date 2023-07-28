#include <stdio.h>

int main()
{
	float result1 = 0;
	float result2 = 0;
	float avg = 0;
	int count = 0;
	int output = 0;
	
	while(1)
	{
		FILE *read = fopen("/proc/stat", "r");
		char buff[2000];
		fgets(buff, 2000, read);
		printf("%s\n", buff);
		fclose(read);
		
		int i = 0;
		while(buff[i] != ' ')
			i++;
		i += 2;
		
		float sum = 0;
		float wsum = 0;
		float sum3 = 0;
		
		int loopCounter = 3;
		while(loopCounter > 0)
		{
			float fdum = 0;
			while(buff[i] != ' ')
			{
				char cdum = buff[i];
				fdum = fdum * 10;
				fdum = (float)cdum + fdum;
				i++;
			}
			
			sum = sum + fdum;
			loopCounter = loopCounter - 1;
			i++;
		}
		
		loopCounter = 2;
		while(loopCounter > 0)
		{
			float fdum = 0;
			while(buff[i] != ' ')
			{
				char cdum = buff[i];
				fdum = fdum * 10;
				fdum = (float)cdum + fdum;
				i++;
			}
			
			wsum = wsum + fdum;
			loopCounter = loopCounter - 1;
			i++;
		}
		
		loopCounter = 2;
		while(loopCounter > 0)
		{
			float fdum = 0;
			while(buff[i] != ' ')
			{
				char cdum = buff[i];
				fdum = fdum * 10;
				fdum = (float)cdum + fdum;
				i++;
			}
			
			sum3 = sum3 + fdum;
			loopCounter = loopCounter - 1;
			i++;
		}
		
		if (count == 0) 
		{
			result1 = sum/(wsum + sum3 + sum);
			count++;
		}
		else
		{
			result2 = sum/(wsum + sum3 + sum);
			count = 0;
			output = 1;
		}
		
		if (output)
		{
			avg = ((result1 + result2)/2) * 100;
			printf("%f\n", avg);
			avg = 0;
			result1 = 0;
			result2 = 0;
			output = 0;
		}

		
		
		sleep(1);
	}

	return 0;
}

