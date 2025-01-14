#include <iostream>
#include "wavfile.h"
using namespace std;


void playfile(char* str) {
	if (playWavFile(str) == 0)
		cout << "Error: File not found!" << endl;
}

//Sample function for reading and storing sound data
void read_data(char* str) {
	
		int sampleRate = 0, size = 100000;
		unsigned char* ptr = new unsigned char[size];
		readWavFile(str, ptr, size, sampleRate);
		delete[] ptr;
	
}


int main(){
	char str[50] = "";
	bool flag = true;
	while (flag) {
		//You can add more options in menue function
		cout << "Enter file name with (.wav) or exit: ";
		cin >> str;
		if (strcmp(str, "exit") != 0) {
			read_data(str);
			playfile(str);
		}
		else
			flag = 0;
	}

	return 0;
}