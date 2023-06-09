#include <iostream>
using namespace std;
int main()
{
	int run_program;
	do
	{
	// initialize the variables used in the program
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
		cout << "Enter the number of students :      ";    // Ask from user this code is run for how many students
		cin >> N;
		for (int i = 1; i <= N; i++)                      // this loop is uesd to control the number of students
		{
			cout << endl;
			cout << "               ********************************  " << endl;
			cout << "               **  ------Student #  " << i << "------  " << "**" << endl;
			cout << "               ********************************  " << endl;
			cout << "Enter the number of courses of student " << i << " :     ";
			cin >> M;
			for (int j = 1; j <= M; j++)               // this loop holds the number of subjects of each students
			{
				cout << endl;
				cout << "          ------Course # " << j << "------" << endl;
				cout << endl;
				cout << "             *************************************  " << endl;
				cout << "Enter Quizz # 1 and Quizz # 2 marks from 0 to 10 (Otherwise terminates the program) : " << endl << endl;
				cout << "               - Quizz # 1 :          ";    // quizz # 1 marks
				cin >> quizz1;
				if (quizz1 <= 10 && quizz1 >= 0)                     // boundary check for quizz # 1 marks
				{
					quizz1_percentage = (quizz1 * 2.5) / 10;         // percentage of  quizz # 1 marks from whole result
				}
				else
				{
					cout << "Invalid Input (Run Program again and please enter Quizz # 1 marks from 0 to 10)" << endl;
					// message show if quizz # 1 marks is out of range because quizz # 1 marks range from 1 to 10
					system("pause");
					return 0;
				}
				cout << "               - Quizz # 2 :          ";    // quizz # 2 marks
				cin >> quizz2;
				if (quizz2 <= 10 && quizz2 >= 0)                     // boundary check for quizz # 2 marks
				{
					quizz2_percentage = (quizz2 * 2.5) / 10;         // percentage of  quizz # 2 marks from whole result
				}
				else
				{
					cout << "Invalid Input (Run Program again and please enter Quizz # 2 marks from 0 to 10)" << endl;
					// message show if quizz # 2 marks is out of range because quizz # 2 marks range from 1 to 10
					system("pause");
					return 0;
				}
				cout << endl;
				cout << "             *************************************  " << endl;
				cout << "Enter Assignment # 1 and Assignment # 2 marks from 0 to 25 (Otherwise terminates the program) : " << endl << endl;
				cout << "               - Assignment # 1 :     ";       // assignment # 1 marks
				cin >> assignment1;
				if (assignment1 <= 25 && assignment1 >= 0)              // boundary check for assignment # 1 marks
				{
					assignment1_percentage = (assignment1 * 5) / 25;    // percentage of  assignment # 1 marks from whole result
				}
				else
				{
					cout << "Invalid Input (Run Program again and please enter Assignment # 1 marks from 0 to 25)" << endl;
					// message show if assignment # 1 marks is out of range because assignment # 1 marks range from 1 to 25
					system("pause");
					return 0;
				}
				cout << "               - Assignment # 2 :     ";       // assignment # 2 marks
				cin >> assignment2;
				if (assignment2 <= 25 && assignment2 >= 0)              // boundary check for assignment # 2 marks
				{
					assignment2_percentage = (assignment2 * 5) / 25;    // percentage of assignment # 2 marks from whole result
				}
				else
				{
					cout << "Invalid Input (Run Program again and please enter Assignment # 2 marks from 0 to 25)" << endl;
					// message show if assignment # 2 marks is out of range because assignment # 2 marks range from 1 to 25
					system("pause");
					return 0;
				}
				cout << endl;
				cout << "             *************************************  " << endl;
				cout << "Enter Midterm marks from 0 to 50 : (Otherwise terminates the program) : " << endl << endl;
				cout << "               - Midterm :            ";        // midterm marks
				cin >> midterm;
				if (midterm <= 50 && midterm >= 0)                       // boundry check for midterm marks 
				{
					midterm_percentage = (midterm * 35) / 50;            // percentage of midterm marks from whole result 
				}
				else
				{
					cout << "Invalid Input (Run Program again and please enter Midterm marks from 0 to 25)" << endl;
					// message show if midterm marks is out of range because midterm marks range from 1 to 50
					system("pause");
					return 0;
				}
				cout << endl;
				cout << "             *************************************  " << endl;
				cout << "Enter Final marks from 0 to 100 (Otherwise terminates the program) : " << endl << endl;
				cout << "               - Final :              ";     // final exam marks
				cin >> final;
				if (final <= 100 && final >= 0)                       // boundry check for final exam marks
				{
					final_percentage = (final * 50) / 100;            // percentage of final marks from whole result
				}
				else
				{
					cout << "Invalid Input (Run Program again and Please enter Final marks from 0 to 100)" << endl;
					// message show if final marks is out of range because final marks range from 1 to 100
					system("pause");
					return 0;
				}
				// sum of quizzez , assignments , midterm and final percentage and store in different variable
				grand_total = quizz1_percentage + quizz2_percentage + assignment1_percentage + assignment2_percentage + midterm_percentage + final_percentage;
				cout << endl;
				cout << "             *************************************  " << endl;
				cout << "Final Result of the whole semester : " << endl << endl;
				cout << "               ----> Grand Total :    " << grand_total << endl;   // final result of the whole semester
				// use different checks to finds the grades
				if (grand_total <= 100 && grand_total > 75)
				{
					cout << "               ----> Grade :           A" << endl;
				}
				else if (grand_total <= 75 && grand_total > 65)
				{
					cout << "               ----> Grade :           B" << endl;
				}
				else if (grand_total <= 65 && grand_total > 55)
				{
					cout << "               ----> Grade :           C" << endl;
				}
				else if (grand_total <= 55 && grand_total >= 45)
				{
					cout << "               ----> Grade :           D" << endl;
				}
				else
				{
					cout << "               ----> Grade :           F" << endl;
				}
				cout << endl;
				cout << "             *************************************  " << endl;
				cout << "             *************************************  " << endl;
			}
			cout << endl << endl;
		}
		cout << "Do you want to run the program again ? (Press '1' to run program again and press '0' to terminates the program) : ";
		cin >> run_program;       // this loop is used to ask from user whether you run the pragram again or not (press '1' for run program again and '0' for terminates the pragram)
		cout << endl << endl;
	} while (run_program == 1);
	system("pause");
	return 0;
}
