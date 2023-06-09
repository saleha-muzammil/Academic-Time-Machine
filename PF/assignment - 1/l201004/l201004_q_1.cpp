//Prints Roll Number, Name, Assignment No., Course, and Due Date of submission.
#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	cout << "***********************************\n";
	cout << "*\t\bRoll Number: 20L-0000" << setw(8) << "*\n";
	cout << "*" << setw(24) << "Solution" << setw(10) << "*";
	cout << "\n*\t\bAssingnment # 1" << setw(14) << "*\n";
	cout << "*\t\bCourse: Programming F." << setw(7) << "*\n";
	cout << "*\t\bDue Date: 11 Oct, 2020" << setw(7) << "*\n";
	cout << "***********************************\n";
	return 0;
}