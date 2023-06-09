#include<iostream>
#include<fstream>        // libraray used for file input and output
using namespace std;
int main()
{
	ofstream file_output("students.txt");   // file where we stored data of students

	// initialization of variables used in this program
	int N;
	int M;
	float quizz1;
	float quizz2;
	float quizz1_percentage;
	float quizz2_percentage;
	float assignment1;
	float assignment2;
	float assignment1_percentage;
	float assignment2_percentage;
	float midterm;
	float midterm_percentage;
	float final;
	float final_percentage;
	float grand_total;
	cout << "Enter the number students : ";            // Ask from user this code is run for how many students
	file_output << "Enter the number students : ";     // store the quantity of students in the given file
	cin >> N;
	file_output << N << endl;
	for (int i = 1; i <= N; i++)                       // use this loop which holds the number of students
	{
		cout << endl;
		file_output << endl;
		cout << "             **********************************" << endl;
		file_output << "          **********************************" << endl;
		cout << "             **   ------Student #  " << i << "------   " << "**" << endl;
		file_output << "          **   ------Student #  " << i << "------   " << "**" << endl;
		cout << "             **********************************" << endl;
		file_output << "          **********************************" << endl;
		cout << "Enter the number of courses of student " << i << " :     ";
		if (i == 1)
			file_output << "Enter the number of courses of student " << i << " :     ";
		cin >> M;
		file_output << M << endl;
		for (int j = 1; j <= M; j++)                 // this loop to hold the number of subjects of each students
		{
			cout << endl;
			file_output << endl;
			cout << "             ------Course # " << j << "------" << endl;
			file_output << "             ------Course # " << j << "------" << endl;
			cout << endl;
			file_output << endl;
			cout << "             *************************************  " << endl;
			file_output << "          **********************************" << endl;

			cout << "Enter Quizz # 1 and Quizz # 2 marks from 0 to 10 (Otherwise terminates the program) : " << endl << endl;
			file_output << "Enter Quizz # 1 and Quizz # 2 marks from 0 to 10 (Otherwise terminates the program) : " << endl << endl;
			cout << "               - Quizz # 1 :          ";          // quizz # 1 marks
			file_output << "               - Quizz # 1 :          ";
			cin >> quizz1;
			file_output << quizz1 << endl;                             // store quizz # 1 marks in give file
			if (quizz1 <= 10 && quizz1 >= 0)    // boundary check for quizz # 1 marks
			{
				quizz1_percentage = (quizz1 * 2.5) / 10;  // percentage of quizz # 1 marks in whole result
			}
			else
			{
				cout << "Invalid Input (Run Program again and please enter Quizz # 1 marks from 0 to 10)" << endl;
				file_output << "Invalid Input (Run Program again and please enter Quizz # 1 marks from 0 to 10)" << endl;
				// message show if quizz # 1 marks is out of range i.e quizz # 1 marks from 1 to 10
				system("pause");
				return 0;
			}
			cout << "               - Quizz # 2 :          ";          // quizz # 2 marks
			file_output << "               - Quizz # 2 :          ";
			cin >> quizz2;
			file_output << quizz2 << endl;                            // store quizz # 2 marks in give file
			if (quizz2 <= 10 && quizz2 >= 0)               // boundary check for quizz # 2 marks
			{
				quizz2_percentage = (quizz2 * 2.5) / 10;   // percentage of quizz # 2 marks in whole result
			}
			else
			{
				cout << "Invalid Input (Run Program again and please enter Quizz # 2 marks from 0 to 10)" << endl;
				file_output << "Invalid Input (Run Program again and please enter Quizz # 2 marks from 0 to 10)" << endl;
				// message show if quizz # 1 marks is out of range i.e quizz # 2 marks from 1 to 10
				system("pause");
				return 0;
			}
			cout << endl;
			file_output << endl;
			cout << "             *************************************  " << endl;
			file_output << "          **********************************" << endl;
			cout << "Enter Assignment # 1 and Assignment # 2 marks from 0 to 25 (Otherwise terminates the program) : " << endl << endl;
			file_output << "Enter Assignment # 1 and Assignment # 2 marks from 0 to 25 (Otherwise terminates the program) : " << endl << endl;
			cout << "               - Assignment # 1 :     ";          // assignment # 1 marks
			file_output << "               - Assignment # 1 :     ";
			cin >> assignment1;
			file_output << assignment1 << endl;                        // store assignment # 1 marks in given file
			if (assignment1 <= 25 && assignment1 >= 0)                 // boundary check for assignment # 1 marks
			{
				assignment1_percentage = (assignment1 * 5) / 25;       // percentage assignment # 1 marks in whole result		
			}
			else
			{
				cout << "Invalid Input (Run Program again and please enter Assignment # 1 marks from 0 to 25)" << endl;
				file_output << "Invalid Input (Run Program again and please enter Assignment # 1 marks from 0 to 25)" << endl;
				// message show if quizz # 1 marks is out of range i.e assignment # 1 marks from 1 to 25
				system("pause");
				return 0;
			}
			cout << "               - Assignment # 2 :     ";          // assignment # 2 marks
			file_output << "               - Assignment # 2 :     ";
			cin >> assignment2;
			file_output << assignment2 << endl;                        // store assignment # 2 marks in given file
			if (assignment2 <= 25 && assignment2 >= 0)                 // boundary check for assignment # 2 marks
			{
				assignment2_percentage = (assignment2 * 5) / 25;      // percentage assignment # 2 marks in whole result	 
			}
			else
			{
				cout << "Invalid Input (Run Program again and please enter Assignment # 2 marks from 0 to 25)" << endl;
				file_output << "Invalid Input (Run Program again and please enter Assignment # 2 marks from 0 to 25)" << endl;
				// message show if quizz # 1 marks is out of range i.e assignment # 1 marks from 1 to 25
				system("pause");
				return 0;
			}
			cout << endl;
			file_output << endl;
			cout << "             *************************************  " << endl;
			file_output << "          **********************************" << endl;
			cout << "Enter Midterm marks from 0 to 50 : (Otherwise terminates the program) : " << endl << endl;
			file_output << "Enter Midterm marks from 0 to 50 : (Otherwise terminates the program) : " << endl << endl;
			cout << "               - Midterm :            ";       // midterm marks
			file_output << "               - Midterm :            ";
			cin >> midterm;
			file_output << midterm << endl;                        // store midterm marks in the given file
			if (midterm <= 50 && midterm >= 0)                     // boundary check for midterm marks
			{
				midterm_percentage = (midterm * 35) / 50;          // percentage of midterm marks in whole result
			}
			else
			{
				cout << "Invalid Input (Run Program again and please enter Midterm marks from 0 to 50)" << endl;
				file_output << "Invalid Input (Run Program again and please enter Midterm marks from 0 to 50)" << endl;
				// message show if midterm marks is out of range i.e midterm marks from 1 to 50
				system("pause");
				return 0;
			}
			cout << endl;
			file_output << endl;
			cout << "             *************************************  " << endl;
			file_output << "          **********************************" << endl;
			cout << "Enter Final marks from 0 to 100 (Otherwise terminates the program) : " << endl << endl;
			file_output << "Enter Final marks from 0 to 100 (Otherwise terminates the program) : " << endl << endl;
			cout << "               - Final :              ";   // final marks
			file_output << "               - Final :              ";
			cin >> final;
			file_output << final << endl;                        // store final marks in the given file
			if (final <= 100 && final >= 0)                      // boundary check for final exam marks
			{
				final_percentage = (final * 50) / 100;           // percentage of final exam marks in whole result
			}
			else
			{
				cout << "Invalid Input (Run Program again and Please enter Final marks from 0 to 100)" << endl;
				file_output << "Invalid Input (Run Program again and please enter Final marks from 0 to 100)" << endl;
				// message show if final marks is out of range i.e final marks from 1 to 100
				system("pause");
				return 0;
			}
			// sum of quizzez percentage , assignment percentage , midterm percentage and final exam percentage and store in a variable
			grand_total = quizz1_percentage + quizz2_percentage + assignment1_percentage + assignment2_percentage + midterm_percentage + final_percentage;
			cout << endl;
			file_output << endl;
			cout << "             *************************************  " << endl;
			file_output << "          **********************************" << endl;
			cout << "Final Result of the whole semester : " << endl << endl;       // result of whole semester
			file_output << "Final Result of the whole semester : " << endl << endl;
			cout << "               ----> Grand Total :    " << grand_total << endl;
			file_output << "               ----> Grand Total :    " << grand_total << endl;  // store result of whole semester in the givn file
			// boundary checks for grand total to find grades according to the numbers obtained
			if (grand_total <= 100 && grand_total > 75)
			{
				cout << "               ----> Grade :           A" << endl;
				file_output << "               ----> Grade :           A" << endl;
			}
			else if (grand_total <= 75 && grand_total > 65)
			{
				cout << "               ----> Grade :           B" << endl;
				file_output << "               ----> Grade :           B" << endl;
			}
			else if (grand_total <= 65 && grand_total > 55)
			{
				cout << "               ----> Grade :           C" << endl;
				file_output << "               ----> Grade :           C" << endl;
			}
			else if (grand_total <= 55 && grand_total >= 45)
			{
				cout << "               ----> Grade :           D" << endl;
				file_output << "               ----> Grade :           D" << endl;
			}
			else
			{
				cout << "               ----> Grade :           F" << endl;
				file_output << "               ----> Grade :           F" << endl;
			}
			cout << endl;
			file_output << endl;
			cout << "             *************************************  " << endl;
			file_output << "          **********************************" << endl;
			cout << "             *************************************  " << endl;
			file_output << "          **********************************" << endl;
		}
	}
	file_output.close();      // file close
	system("pause");
	return 0;
}