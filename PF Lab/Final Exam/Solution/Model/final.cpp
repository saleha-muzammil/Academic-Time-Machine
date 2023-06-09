#include <iostream>
#include<cstdlib>
using namespace std;
int strlen(char arr[]) {				//length of char array
	int len = 0;
	while (arr[len++] != '\0');
	return len - 1;
}
int findSubString(char arr[], char sub[], int index)		//return index if substring found else -1
{
	for (index; arr[index] != '\0'; index++)	
		if (arr[index] == sub[0]) {
			int i = index, j = 0;
			for (; sub[j] != '\0' && arr[i] != '\0' && arr[i] == sub[j]; j++, i++);
			if (j == strlen(sub))
				return index;
		}
	return -1;
}

void removeDuplicateWords(char arr[]) {			//removes all duplicate words. 
	char buffer[40];
	int k = 0;
	for (int i = 0; i<strlen(arr)+1; i++)
	{
		buffer[k++] = arr[i];
		if (arr[i] == 32 || arr[i] == '\0')			//a word is formed
		{
			buffer[--k] = '\0';
			int index = findSubString(arr, buffer, i + k);	//find this word after the current index
			while (index > -1) {							//if found 
				for (index; index < strlen(arr) - k + 1; index++)
					arr[index] = arr[index + k];				//shift array to left
				index = findSubString(arr, buffer, i + k);
			}
			k = 0;
		}
	}
}
void subtract(int HugeInt1[], int HugeInt2[], int result[], const int s1, int s2)
{													//HugeInt1 - HugeInt2
	for (int i = s2 - 1, j=s1-1; i >= 0; i--, j--){
		if (HugeInt2[i] <= HugeInt1[j])				
			result[j] = HugeInt1[j] - HugeInt2[i];
		else {
			int k = j - 1;
			for (; HugeInt1[k] == 0 && k >= 0; k--)		//Take carry untill the preceeding elemnet is not 0
				HugeInt1[k] = 9;						//update previous
			HugeInt1[k] -= 1;
			result[j] = (10+HugeInt1[j]) - HugeInt2[i];
		}
	}
	for (int i = s1 - s2 - 1; i >= 0; i--)		//if elements are still left put in result	
		result[i] = HugeInt1[i]; 
}
void getHugeInt(int HugeInt[], int &size) {
	cout << "Enter the size of HugeInt: ";			//input hugeInt size
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Enter digit #" << i + 1 << " of Number:  ";	//input each digit
		cin >> HugeInt[i];	HugeInt[i] = HugeInt[i] % 10;		//if unfortunately user has input greater than 10
	}
}
void multiply(int HugeInt1[], int HugeInt2[], int result[], int s1, int s2) {
	for (int i = s1-1; i>=0; i--)
		for (int j = s2-1, k=i+j+1; j>=0; j--, k--)		//HugeInt1 * HugeInt2
		{
			int temp = HugeInt1[i] * HugeInt2[j];		//multiply digit
			for (int m = k; m >= 0; m--) {
				int carry = (result[m] + temp) / 10;	//update
				result[m] = (result[m] + temp) % 10;
				temp = carry;
			}
		}
}
void printHugeInt(int HugeInt[], int size) {
	int i = 0; 
	for (; HugeInt[i] == 0; i++);	//skip leading zeroes
	for (; i < size; i++)			//print rest of the elements
		cout << HugeInt[i];
	cout << endl;
}
void inputArray(float arr[], int size) {
	for (int i = 0; i < size; i++)
	{									//To save time from input i am taking input from random
		arr[i] = rand() % 100;
		/*float f = rand() % 10;
		arr[i] += f / 10;*/
	}
}
/*
void roundOff(float arr[], int size) {
	for (int i = 0; i < size; i++){
		float f = arr[i] - int(arr[i]);
		f >= 0.5 ? arr[i] = arr[i] + 1 - f : arr[i] = arr[i] - f;
	}
void sort(float arr[], int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if (arr[j] < arr[j + 1])
				swap(arr[j], arr[j + 1]);
	}
}*/

float getAverage(float arr[], int size) {
	float sum = 0;						//average 
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum / size;
}
float getStandardDeviation(float arr[], int size) {
	float average = getAverage(arr, size), sum = 0;
	for (int i = 0; i < size; i++)
		sum += (arr[i]-average)*(arr[i] - average);
	return pow(sum / size, 0.5);			//standard deviation
}
float percentage(float arr[], int size, float average, float std) {
	float count = 0;
	float min = average - std, max = average + std;
	for (int i = 0; i < size; i++) 
		if (arr[i] > min && arr[i] < max)
			count++;	
	float per = (count / size) * 100;			//percentage
	return per;
}
int findPattern(char str[], char arr[]) {
	char buffer[40];
	int k = 0, in=0;
	for (int i = 0; i<strlen(arr)+1; i++)
	{
		buffer[k++] = arr[i];
		if (arr[i] == '*' || arr[i] == '\0')		//a word is formed
		{
			buffer[k-1] = '\0';
			int index = findSubString(str, buffer, in);		//find if word exists
			if (index > -1)
				in = index+strlen(buffer);			//update the location 
			else
				return -1;		//not pattern not found
			k = 0;
		}
	}
	return 1;
}
void printData(float arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void main() {

									/* Remove Duplicate Words */
	/*char arr[] = "Hello I am muslim I am going to Lahore Hello am";
	removeDuplicateWords(arr);
	cout << arr << endl;*/
									/* Emperical Rule of Data */

	/*float data[10]; int size = 10;
	inputArray(data, size);
	printData(data, size);
	float average = getAverage(data, size);
	float std = getStandardDeviation(data, size);
	cout << average << endl << std << endl;
	float per = percentage(data, size, average, std);
	cout << per << endl;
	if (per > 65 && per < 75)
		cout << "Good Bell shape\n";
	else
		cout << "Bad Bell shape\n"; */
	
									/* Find the pattern */

	//char arr[] = "Hello I am muslim I am going to Lahore";
	//char pattern[] = "Hello*Lahore*to";
	//int index = findPattern(arr, pattern);
	//if (index == -1)
	//cout << "Pattern Not Found\n";
	//else
	//cout << "Pattern Found\n";
	
								/* HugeInt Arithmetic Operations */

	int HugeInt1[20], HugeInt2[20], result[40] = {0};
	int size1, size2, resultSize=0;
	getHugeInt(HugeInt1, size1);
	cout << "The HugeInt you entered is: ";
	printHugeInt(HugeInt1, size1);
	getHugeInt(HugeInt2, size2);
	cout << "The HugeInt you entered is: ";
	printHugeInt(HugeInt2, size2);
	multiply(HugeInt1, HugeInt2, result, size1, size2);
	cout << "Multiply Result is:  ";
	printHugeInt(result, size1 + size2);	
	subtract(HugeInt1, HugeInt2, result, size1, size2);
	cout << "Subtract Result is:  ";
	printHugeInt(result, size1); 
}