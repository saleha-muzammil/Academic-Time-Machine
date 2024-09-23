#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include<unistd.h>

using namespace std;

struct pro
{
	char msg[1000][1000];
};

pro *ps=new pro[1000];

int main(){

	int i=0;
	int j=0;
	int k=0;
	int c=0;
	int p=0;
	int u=0;
	int rows=0;
	int process=1;
	vector<string> processNames;

	ifstream infile;

	infile.open ("InputAssign-1.txt");

	char line[1000];
	char temp[1000];
	infile.getline(line,1000,'\n');

	while(line[i]!='\0')
	{
		while(line[i]!=',')
		{
			if(line[i]=='\0')
			{
				temp[u]='\0';
				u++;
				break;
			}
			temp[u]=line[i];
			u++;
			i++;
		}
		temp[u]='\0';
		strcat(temp,".txt");
		cout<<temp<<endl;
		ofstream fout;
		processNames.push_back(temp);
		fout.open(temp);
		if(line[i]==',')
		{
			process++;
			i++;
		}
		
		u=0;
	}

	while(!infile.eof())
	{
		infile.getline(line,1000,'\n');
		while(line[j]!='\0')
		{
			while(line[j]!=','&&c<=process)
			{
				if(line[j]=='\0')
				{
					break;
				}
				ps[c].msg[p][k]=line[j];
				k++;
				j++;
			}
			ps[c].msg[p][k]='\0';
			j++;
			c++;
			k=0;
		}
		rows++;
		p++;
		j=0;
		c=0;
	}


	/*for(int i=0;i<process;i++)
	{
		for(int k=0;k<rows;k++)
		{
			for(int j=0;ps[i].msg[k][j]!='\0';j++)
			{
				cout<<ps[i].msg[k][j];
			}
			cout<<"\n";
		}
		cout<<endl;
	}
*/
	for(int i=0;i<process;i++){
	
		int pdes[2] ;
            pipe(pdes) ;
		int pid=fork();
		if(pid>0){
			string ttt=processNames[i];
            close(pdes[0]) ;
            write(pdes[1],&processNames[i],sizeof(processNames[i])) ; // write to child
			
		}
		else if(pid==0){
			
			ofstream foutt;
			string ttt=processNames[i];
			close(pdes[1]) ;
                        read( pdes[0],&processNames[i],sizeof(processNames[i])) ; // read from parent
			foutt.open(ttt.c_str());
			
			for(int k=0;k<rows;k++)
			{
				for(int j=0;ps[i].msg[k][j]!='\0';j++)
				{
					foutt<<ps[i].msg[k][j];
				}
			foutt<<"\n";
			}
			return 0;
		}
	}

	return 0;
}
