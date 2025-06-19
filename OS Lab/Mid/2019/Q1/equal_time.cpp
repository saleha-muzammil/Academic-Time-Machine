#include<time.h>
#include<iostream>
using namespace std;
short is_time_equal_to_current_time(unsigned short hour, unsigned short minutes)
{
	time_t my_time;
	struct tm * timeinfo; 
	time (&my_time);
	timeinfo = localtime (&my_time);
	if (hour > 23 || minutes > 60)
	{
		cout<<("Hour or minutes out of range.Returning -1!!!\n");
		return -1; 
	}
	if( hour == timeinfo->tm_hour && minutes == timeinfo->tm_min)
		return 1;
	else return 0;
}
int main()
{

cout<<"Are the times equal: "<< is_time_equal_to_current_time(19,34)<<endl;
return 0;
}
