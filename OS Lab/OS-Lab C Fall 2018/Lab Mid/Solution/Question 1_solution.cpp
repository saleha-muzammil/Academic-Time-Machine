#include<iostream>
#include<fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <string>
#include <stdio.h>
#include <cstring>


using namespace std;

int KEY1 = 45678;
float getCgpa(char*rollNo,char ** SrollNo , float*arry,int s_c)
{
	for(int i = 0 ; i < s_c ;i++)
	{
		if(strcmp(SrollNo[i],rollNo) == 0)
			return arry[i];
	}
	return 0.0;
}

void readStudentFile(char * filename,float * &cgpa, char ** &rollNo,int &c)
{
	ifstream fin;
	fin.open(filename);
	
	fin >> c;
	rollNo = new char*[c];
	cgpa = new float[c];
	for(int i = 0 ; i < c ;i++)
	{
		rollNo[i] = new char[100];
		fin >> rollNo[i] ;
		fin >> cgpa[i];
	}
}
char * readTeacherFile(char * filename,char ** &review, char ** &rollNo,int &c)
{
	char * name = new char[100];
	
	ifstream fin;
	fin.open(filename);
	fin.getline(name,100);

	fin >> c;
	rollNo = new char*[c];
	review = new char*[c];
	for(int i = 0 ; i < c ; i++)
	{
		rollNo[i] = new char[100];
		review[i] = new char[100];
		fin >> rollNo[i] ;
		fin >> review[i];
	}

	return name;
}
float getAverage(char ** SrollNo,float * cgpa,int s_c , char ** TrollNo,char ** review,int r_c, char *reviewName)
{
	float count = 0;
	float av = 0;
	for(int i = 0 ; i < r_c ; i++)
	{
		if(strcmp(reviewName,review[i]) == 0)
		{
			count++;
			av += getCgpa(TrollNo[i],SrollNo,cgpa,s_c);
		
		}
	}
	if(count > 0)
		av = av /count;
	return av;
	
}

char * convertFloatToChar(float value)
{
	char * ans = new char[100];
	sprintf(ans,"%f", value);
	return ans;
}

int main(int count , char** list)
{
	if(count < 3)
	{
		cout << "Invalid arguments\n";
		return 1;
	}
	ofstream fout("output.txt");
	for(int i = 0 ; i < count -2 ; i++)
	{

		int key=shmget(KEY1, 1024, IPC_CREAT | IPC_EXCL | 0666); 
 		char* ptr= (char*) shmat(key, NULL, 0); 

		
		pid_t  pid = fork();
		if(pid ==0) // child
		{
			float * cgpa;
			char ** SrollNo;
			int studentCount;

			readStudentFile(list[1],cgpa,SrollNo,studentCount);
			
			char ** review;
			char ** TrollNo;
			int reviewCount;
			
			char * teacherName ;
			teacherName = readTeacherFile(list[i+2],review , TrollNo,reviewCount);

			float good_average = 0;
			float bad_average = 0;
			float excellent_average = 0;

			good_average = getAverage(SrollNo,cgpa,studentCount,TrollNo,review,reviewCount,"good");
			bad_average =  getAverage(SrollNo,cgpa,studentCount,TrollNo,review,reviewCount,"bad");
			excellent_average  =  getAverage(SrollNo,cgpa,studentCount,TrollNo,review,reviewCount,"excelent");

			
			char * good_array = convertFloatToChar(good_average);
			char * bad_array = convertFloatToChar(bad_average);
			char * ex_array = convertFloatToChar(excellent_average);
	
			
			strcpy(ptr,teacherName);
			strcat(ptr,"\naverage cgpa for good:");
			strcat(ptr,good_array);
			strcat(ptr,"\naverage cgpa for bad:");
			strcat(ptr,bad_array);
			strcat(ptr,"\naverage cgpa for excellnt:");
			strcat(ptr,ex_array);
			strcat(ptr,"\n");

			shmdt(ptr);
			return 0;
		}
		wait(NULL);

		int key2=shmget(KEY1, 1024, 0 ); //We have not passed IPC_CREAT, this means that it will always use existing shared region. 
		char* ptr1= (char*) shmat(key2, NULL, 0); 

		for(int i = 0 ; ptr1[i] != '\0' ; i++)
			fout << ptr1[i];

		shmdt(ptr1);

		shmctl(key2, IPC_RMID, NULL); //mark the shared region for deletion
		
	}
	fout.close();	

}

