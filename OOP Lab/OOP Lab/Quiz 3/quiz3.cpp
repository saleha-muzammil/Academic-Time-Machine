#include <iostream>
#include <string>
using namespace std;

// ********************************** PART 1 ****************************************
// Implement the default constructor for the following class

class HugeInt {
public:
	HugeInt();
private:
	int *data;
	int size;
};


// ********************************** PART 2 ****************************************
// In the class below write a pure virtual function called �Draw�.

class Shape {
public:
	Shape() {
		x = 0;
		y = 0;
	}
private:
	int x;
	int y;
};


int main()
{
	// ********************************** PART 3 ****************************************
	// Write the code of creating the following dynamic 2D int array with 5 rows and 10 columns

	int **dynamic_2d_int_array;


	// ********************************** PART 4 ****************************************
	// Write code for deleting the above array dynamic_2d_int_array


	// ********************************** PART 5 ****************************************
	// Write c++ code that prints int_arr

	int size = 10;
	int *int_arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		int_arr[i] = i * 2;
	}

	// Write code that prints char_arr

	char *char_arr = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		char_arr[i] = 'a';
	}
	char_arr[size - 1] = '\0';

	// ********************************** PART 6 ****************************************
	// Write code to deallocate int_arr and char_arr

	// ********************************** PART 7 ****************************************
	// Comapare the following string arrays index wise

	string pens[4] = { "Blue", "Red", "Orange", "Yellow" };
	string markers[4] = { "Blue", "Red", "Orange", "White" };

	system("pause");
	return 0;
}
