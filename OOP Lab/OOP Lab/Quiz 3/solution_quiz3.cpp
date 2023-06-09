#include <iostream>
#include <string>
using namespace std;

// ********************************** PART 1 ****************************************
// Implement the default constructor for the following class

class HugeInt {
public:
	HugeInt()
	{
		data = nullptr;
		size = 0;
	}
private:
	int *data;
	int size;
};


// ********************************** PART 2 ****************************************
// In the class below write a pure virtual function called “Draw”.

class Shape {
public:
	Shape() {
		x = 0;
		y = 0;
	}
	virtual void draw() = 0;
private:
	int x;
	int y;
};


int main()
{
	// ********************************** PART 3 ****************************************
	// Write the code of creating the following dynamic 2D int array with 5 rows and 10 columns

	int **dynamic_2d_int_array;
	dynamic_2d_int_array = new int*[5];
	for (int i = 0; i < 5; i++)
		dynamic_2d_int_array[i] = new int[10];


	// ********************************** PART 4 ****************************************
	// Write code for deleting the above array dynamic_2d_int_array

	for (int i = 0; i < 5; ++i) {
		delete[] dynamic_2d_int_array[i];
	}
	//Free the array of pointers
	delete[] dynamic_2d_int_array;

	// ********************************** PART 5 ****************************************
	// Write c++ code that prints int_arr

	int size = 10;
	int *int_arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		int_arr[i] = i * 2;
	}

	for (int i = 0; i < size; i++)
		cout << int_arr[i];

	// Write code that prints char_arr

	char *char_arr = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		char_arr[i] = 'a';
	}
	char_arr[size - 1] = '\0';

	cout << char_arr;

	// ********************************** PART 6 ****************************************
	// Write code to deallocate int_arr and char_arr

	delete[]int_arr;
	delete[]char_arr;

	// ********************************** PART 7 ****************************************
	// Comapare the following string arrays

	string pens[4] = { "Blue", "Red", "Orange", "Yellow" };
	string markers[4] = { "Blue", "Red", "Orange", "White" };

	bool flag = true;
	for (int i = 0; i < 4; i++)
	{
		if (pens[i] != markers[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "Same colors";

	system("pause");
	return 0;
}
