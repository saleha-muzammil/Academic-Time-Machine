#include <iostream>//system pause not added into code, when running please press SHIFT+F5
using namespace std;
int findPattern(char str[], char pattern[]);
int findSubstring(char arr[], char sub[], int index);

int main () {
	char arr[]= "Hello I am muslim I am going to Lahore";
	char pattern[]= "Hello*Lahore*to";
	int index = findPattern(arr,pattern);
	if (index==-1) {
		cout<<"Pattern Not Found";
	}
	else 
		cout<<"Pattern Found";

	return 0;
}
int findPattern(char str[], char pattern[]){
	char arr[100];
	int a=0,b=-1;
	bool m=1;
	int index=0;
	int count=0, counter=0;
	while (m){
		
		for (int i=0; i!='*' ; i++){
		if (pattern[i]=='\0') {
			m=0;
		}
		else {

		for (int j=0; j!='\0'; j++) {
			if (str[j]==pattern[i]) {
				index =j;
				arr[a]=pattern[i];
				a++;
				
			}
		}
		}

	}
	int x = findSubstring(pattern,arr, index);
	if (x!=0) {
		count++;
	} 


	counter++;


	}

	if (counter==count){
		return a;
	}

	return b;
}

int findSubstring(char arr[], char sub[], int index){
	int counter=0;

	for (int i=index; i>=0; i++) {
		if (arr[i]==sub[i]) { 
			counter++;
		}
	}
	if (counter==index) {
		return 0;
	}
	else return 1;



}
