#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

bool IsFileExists(string filename){
    ifstream f(filename.c_str());
    return f.good();
}

int NoOfRows(string filename){
	ifstream fin(filename);
	string OneLine;
	int counter=0;
	while(!fin.eof()){
		getline(fin,OneLine);
		counter++;
	}
	fin.close();
	return counter;
}

int NoOfCols(string filename){
	ifstream fin(filename);
	string FirstLine;
	int counter = 0;
	getline(fin,FirstLine);
	for(int i=0; i<FirstLine.length();i++){
		if(FirstLine[i]==','){
			counter++;
		}
	}
		fin.close();
	return ++counter;
}

void PopulateData(string **FileData, int rows, int cols, string filename){
	ifstream fin(filename);
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols-1; j++){
			getline(fin,FileData[i][j],',');
			fin.ignore(1);
		}
		getline(fin,FileData[i][j]);
	}
	fin.close();
}

void PrintFileData(string **FileData, int rows, int cols){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout<<FileData[i][j]<<" ";
		}
		cout<<endl;
	}
}

void CreateProcesses(string **FileData, int rows, int cols){
	for(int u=0; u<cols;u++){
		char buf=' ';
		int fd[2];
		pipe(fd);
		pid_t pid=0;
		pid=fork();
		if(pid>0){
			close(fd[0]);
			string tempstr="";
			for(int i=0; i<rows;i++){
				tempstr+=FileData[i][u];
				tempstr+='\n';
			}
			char *tempch=new char [tempstr.length()+1];
			strcpy(tempch, tempstr.c_str());
			write(fd[1],tempch, strlen(tempch));
			delete [] tempch;
			close(fd[1]);
			wait(NULL);
		}
		else if(pid==0){
			close(fd[1]);
			string temp="";
			while(read(fd[0], &buf,1)>0){
				temp+=buf;
			}
			size_t pos = temp.find("\n");
			string filename = temp.substr (0,pos);
			filename+=".txt";
			string data=temp.substr(pos+1,temp.length());
			ofstream fout(filename);
			fout<<data;
			fout.close();
			close(fd[0]);
			exit(0);
		}
		else{
			cout<<"Process Creation Error!"<<endl;
		}
	}
	cout<<"Output Files are created successfully."<<endl;
}

int main(){
	string filename="InputAssign-1.txt";
	if(!IsFileExists(filename)){
		cout<<"File " << filename <<" does not exist."<<endl;
		return 0;
	}
	int rows=NoOfRows(filename);
	int cols=NoOfCols(filename);
	
	string **FileData=new string *[rows];
	for(int i=0; i<rows; i++){
		FileData[i]=new string [cols];
	}
	PopulateData(FileData, rows, cols, filename);
	//PrintFileData(FileData, rows, cols);
	
	CreateProcesses(FileData, rows, cols);
	
	return 0;
}