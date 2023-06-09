#include <iostream>
#include <string>
#include<fstream>

using namespace std;

int main(){
	char array1[8][7] = {{"******"},{"******"},{"******"},{"******"},{"******"},{"******"},{"******"},{"******"}};
	char Class = '\0';
	char Type = '\0';
	while(Class!='1'||Type!='1'){
	
	char sig = 'g';
	char signal = 'n';
	cout<<"To exit the program press 1"<<endl;
	cout<<"Type (First class or Economy)(f/e): ";
	int floor = 0;;
	int room = 0;;
	
	cin>>Class;
	if(Class == '1')
	{
		
		break;

	}
	if(Class == 'e' || Class == 'E')
	{
		
		cout<<"Smoking or non-Smokig (s/n): ";
		cin>>Type;
		if(Type=='s' || Type=='S')
	{
		signal = 's';
	}
	
	}
	
	if(Class == 'e' || Class == 'E')
	{
		if(signal == 's'|| signal == 'S')
		{	
		for(int i = 5;i<8;i++)
		{
			for(int j = 0;j<6;j++)
			{
				if(array1[i][j] == '*')
				{
					floor = i+1;
					room = j+1;
					sig = 'r';
					array1[i][j] = 'X';
					break;
									
				}
				
			}
			if(sig == 'r')
					break;
		}
	}
		else
		{
			for(int i = 2;i<4;i++)
		{
			for(int j = 0;j<6;j++)
			{
				if(array1[i][j] == '*')
				{
					floor = i+1;
					room = j+1;
					sig = 'r';
					array1[i][j] = 'X';
					break;
									
				}
				
			}
			if(sig == 'r')
					break;
		}
		}
	}
	
	if(Class == 'f' || Class == 'F')
	{
		for(int i = 0;i<2;i++)
		{
			for(int j = 0;j<6;j++)
			{
				if(array1[i][j] == '*')
				{
					floor = i+1;
					room = j+1;
					sig = 'r';
					array1[i][j] = 'X';
					break;
									
				}
				
			}
			if(sig == 'r')
					break;
		}
	}
	else if(Class != 'f' && Class != 'F' && Class != 'E' && Class != 'e')
		{cout<<"Wrong choice"<<endl;
	break;
	}
	if(sig == 'g')
	{
		cout<<"There are no room available for this description"<<endl;
		break;
	}
	else{

	cout<<"Allocated: "<<endl;
	cout<<"floor: "<<floor<<endl;
	cout<<"room: "<<room<<endl;
	cout<<endl;
	for(int i = 0;i<8;i++)
		{
			cout<<"Floor"<<i+1<<"|\t";
			for(int j = 0;j<6;j++)
			{
				cout<<array1[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	}
	return 0;
}