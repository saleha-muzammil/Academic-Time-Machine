#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int choice;
	int degree1;
	int coefficient1;
	int degree2;
	int coefficient2;
	int coefficient3;

	ifstream degree_handler1;
	degree_handler1.open("Degree_File_1.txt");

	ifstream coefficient_handler1;
	coefficient_handler1.open("Coeff_File_1.txt");

	ifstream degree_handler2;
	degree_handler2.open("Degree_File_2.txt");

	ifstream coefficient_handler2;
	coefficient_handler2.open("Coeff_File_2.txt");

	ofstream coefficients_sum("add_coeff_file.txt");
	ofstream degree_sum("add_degree_file.txt");

	ofstream coefficients_subtract("subtract_coeff_file.txt");
	ofstream degree_subtract("subtract_degree_file.txt");



	if (degree_handler1.is_open() == true && coefficient_handler1.is_open() == true && degree_handler2.is_open() == true && coefficient_handler2.is_open() == true)
	{
		cout << endl << endl;
		cout << "            ***************************************" << endl;
		cout << "            **   ---------- Main Menue ----------" << "**" << endl;
		cout << "            ***************************************" << endl;
		cout << endl << endl;

		cout << "Press 0 to . Exit the Program \nPress 1 to . File Input & Print \nPress 2 to . Equivalency \nPress 3 to . Add \nPress 4 to . Subtract" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 0)
		{
			cout << endl;
			cout << "The Program Terminated ............... !!!" << endl << endl;
			system("pause");
			return 0;
		}
		else if (choice == 1)
		{
			cout << "The first polynomial is  :  ";
			while (degree_handler1.eof() == false && coefficient_handler1.eof() == false)
			{
				degree_handler1 >> degree1;
				coefficient_handler1 >> coefficient1;

				if (degree1 == 0)
				{
					if (coefficient1 > 0)
					{
						cout << "+" << coefficient1;
					}
					else
					{
						cout << coefficient1;
					}
				}
				if (degree1 == 1)
				{
					if (coefficient1 > 0)
					{
						cout << "+" << coefficient1 << "x";
					}
					else
					{
						cout << coefficient1 << "x";
					}
				}
				if (degree1 > 1)
				{
					if (coefficient1 > 0)
					{
						cout << "+" << coefficient1 << "x^" << degree1;
					}
					else
					{
						cout << coefficient1 << "x^" << degree1;
					}
				}
			}
			cout << endl;
			cout << "The second polynomial is  :  ";
			while (degree_handler2.eof() == false && coefficient_handler2.eof() == false)
			{
				degree_handler2 >> degree2;
				coefficient_handler2 >> coefficient2;

				if (degree2 == 0)
				{
					if (coefficient2 > 0)
					{
						cout << "+" << coefficient2;
					}
					else
					{
						cout << coefficient2;
					}
				}
				if (degree2 == 1)
				{
					if (coefficient2 > 0)
					{
						cout << "+" << coefficient2 << "x";
					}
					else
					{
						cout << coefficient2 << "x";
					}
				}
				if (degree2 > 1)
				{
					if (coefficient2 > 0)
					{
						cout << "+" << coefficient2 << "x^" << degree2;
					}
					else
					{
						cout << coefficient2 << "x^" << degree2;
					}
				}
			}
		}
		else if (choice == 2)
		{
			while (degree_handler1.eof() == false && coefficient_handler1.eof() == false && degree_handler2.eof() == false && coefficient_handler2.eof() == false)
			{
				degree_handler1 >> degree1;
				coefficient_handler1 >> coefficient1;

				degree_handler2 >> degree2;
				coefficient_handler2 >> coefficient2;

				if (coefficient1 == coefficient2 && degree1 == degree2)
				{
					cout << "";
				}
				else
				{
					cout << endl;
					cout << "The given two Polynomials are not Equal............!!!!!!!!!! " << endl;
					cout << endl;
					system("pause");
					return 0;
				}
			}
			cout << endl;
			cout << "The given two Polynomials are Equal...............! " << endl;
		}
		else if (choice == 3)
		{
			cout << "The degrees and coefficients after subtaction store in thier respective files.......:  ";
			while (degree_handler1.eof() == false && coefficient_handler1.eof() == false && degree_handler2.eof() == false && coefficient_handler2.eof() == false)
			{
				degree_handler1 >> degree1;
				coefficient_handler1 >> coefficient1;

				degree_handler2 >> degree2;
				coefficient_handler2 >> coefficient2;

				if (degree1 == degree2)
				{
					coefficient3 = coefficient1 + coefficient2;
					coefficients_sum << coefficient3 << endl;
					degree_sum << degree1 << endl;
				}
				else
				{
					coefficients_sum << coefficient1 << endl;
					degree_sum << degree1 << endl;
					coefficients_sum << coefficient2 << endl;
					degree_sum << degree2 << endl;
				}
			}
		}
		else
		{
			cout << "The degrees and coefficients after subtaction store in thier respective files.......:  ";  

			while (degree_handler1.eof() == false && coefficient_handler1.eof() == false && degree_handler2.eof() == false && coefficient_handler2.eof() == false)
			{
				degree_handler1 >> degree1;
				coefficient_handler1 >> coefficient1;

				degree_handler2 >> degree2;
				coefficient_handler2 >> coefficient2;

				if (degree1 == degree2)
				{
					coefficient3 = coefficient1 - coefficient2;
					coefficients_subtract << coefficient3 << endl;
					degree_subtract << degree1 << endl;
				}
				else
				{
					coefficients_subtract << coefficient1 << endl;
					degree_subtract << degree1 << endl;
					coefficient2 = -coefficient2;
					coefficients_subtract << coefficient2 << endl;
					degree_subtract << degree2 << endl;
				}
			}
		}
		cout << endl << endl;
		degree_handler1.close();
		coefficient_handler1.close();
	}
	else
	{
		cout << "ERROR...!!! File not opened...\n";
	}
	system("pause");
	return 0;
}