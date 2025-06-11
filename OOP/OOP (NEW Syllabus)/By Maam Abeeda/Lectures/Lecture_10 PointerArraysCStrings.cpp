#include <iostream>
using namespace std;


int main() {
	
	//char ch = 'A';
	//char * cptr = &ch;
	//cout << "ch " << ch << " &ch " << &ch << endl;
	//cout << "*cptr " << *cptr << " cptr " << cptr << " &cptr " << &cptr << endl;
	//cptr++;
	//cout << "*cptr " << *cptr << " cptr " << cptr << " &cptr " << &cptr << endl;
	//cptr = NULL;

	//char ch2 = 'B';
	//char * cptr2 = &ch2;
	//cout << "ch2 " << ch2 << " &ch2 " << &ch2 << endl;
	//cout << "*cptr2 " << *cptr2 << " cptr2 " << &cptr2[0] << " &cptr2 " << &cptr2 << endl;
	//

	//cout << "cptr - cptr2 " << cptr - cptr2 << endl;
	////cout << "ptr - cptr2 " << ptr - cptr2 << endl;
	////cptr = ptr;

	//// Relational operators
	//cout << "cptr == cptr2 " << (cptr == cptr2) << endl;
	//cout << "cptr != cptr2 " << (cptr != cptr2) << endl;
	//cout << "cptr < cptr2 " << (cptr < cptr2) << endl;
	//cout << "cptr > cptr2 " << (cptr > cptr2) << endl;
	//
	
	//chracter Arrays Mutable
	char* chp = new char('*');
	int size = 27;
	char* carr = new char[size];

	for (int i = 0; i < size; i++)
		carr[i] = 'A' + i;
	carr[26] = '\0';

	for (int i = 0; i < size; i++)
		cout << *(carr + i) << " ";
	cout << endl;
	carr[2] = '5';
	strcpy(carr, "Hello How are You All ?!");
	cout << carr << endl;
	cout << *(carr + 1) << endl; //carr[1]
	cout << (carr + 1) << endl; //Aggregate 
	cout << *(carr + 2) << endl;//carr[2]
	cout << *(carr + 10) << endl;//carr[10]

	//Aggregate Operations are allowed
	//cout << carr <<endl;
	////cin >> carr;
	//cin.get(carr,13); //13 read + 1 for null charcter
	//cout << carr << endl;
	//cout << strlen(carr) << endl;

	//CSTRING
	char* CStr = "ABEEDA"; //immutable objects
	cout << CStr << endl;

	carr = CStr;
	//	CStr[2] = '%';
		//cout << CStr << endl;
		/*cout << "abdee";
		cout << 100;*/
		//charcter arrays
	char c[10] = "abcdefnbj";
	cout << c << endl;
	CStr = "dfvdfgv";
	strcpy_s(c, "dfvdfdf");

	/*int i = 0;
	for (; CStr[i] != '\0' && i < 10; i++)
		c[i] = CStr[i];
	c[i] = '\0';*/
	cout << c << endl;



	//delete[] CStr;
	//Valid base address of dynamic allocated memory on heap
	delete[] carr;
	delete chp;

	//2D chracter Arrays
	char** dparr = new char* [3];
	for (int i = 0; i < 3; i++)
		dparr[i] = new char[size];


	for (int j = 0; j < size; j++)
		dparr[0][j] = 'Z' - j;
	dparr[0][26] = '\0';

	for (int j = 0; j < size; j++)
		dparr[1][j] = '0' + j;
	*(*(dparr + 1) + 26) = '\0';

	for (int j = 0; j < size; j++)
		dparr[2][j] = 'a' + j;
	*(*(dparr + 2) + 26) = '\0';

	for (int i = 0; i < 3; i++)
		cout << dparr[i] << endl;

	for (int i = 0; i < 3; i++)
		delete[] dparr[i];

	delete[] dparr;
	dparr = nullptr;

	

	return 0;
}

