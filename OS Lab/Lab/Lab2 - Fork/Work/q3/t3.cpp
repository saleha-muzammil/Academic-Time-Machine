#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int args, char const** arg0)
{
	system(*arg0);
	return 0;
}
