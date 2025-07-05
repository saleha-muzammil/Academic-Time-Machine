#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int pid1;
	vector<int> arr;

	printf("Separate by ',' \n");
	string str;
	getline(cin, str);
	stringstream ss(str);
	string temp;
	int put_in_arr = 0;
	while (getline(ss, temp, ','))
	{
		put_in_arr = stoi(temp);
		arr.push_back(put_in_arr);
	}

	//create process.
	pid1 = fork();
	//if child process.
	if (pid1 == 0)
	{
		int sum = 0;
		int max = arr[0];
		for (int i = 0; i < arr.size(); i++)
		{
			sum += arr[i];
			if (arr[i] > max)
				max = arr[i];
		}
		printf("Sum is %d\n", sum);
		int pid2 = fork();
		if (pid2 == 0)
		{
			int avg = sum/arr.size();
			printf("avg is %d\n", avg);
			int pid3 = fork();
			if (pid3 == 0)
				printf("max is %d\n", max);
		}
	}

	return 0;
}
