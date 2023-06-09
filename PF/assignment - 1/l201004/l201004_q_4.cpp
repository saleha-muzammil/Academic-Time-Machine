//Age Calculator.
//Takes the variation of 30, 31 and 28 in a year into account.
//Takes leap years into consideration too.
#include <iostream>
using namespace std;

int main()
{
	int birth_date = 0;
	int birth_month = 0;
	int birth_year = 0;
	int current_date = 0;
	int current_month = 0;
	int current_year = 0;
	int final_date = 0;
	int final_month = 0;
	int final_year= 0;
	int month_factor;
	int req_month;
	cout << "Input Date of Birth: " << endl << "Day : ";
	cin >> birth_date;
	cout << "Month : ";
	cin >> birth_month;
	cout << "Year : ";
	cin >> birth_year;
	cout << "Input Current Date : " << endl << "Day : ";
	cin >> current_date;
	cout << "Month : ";
	cin >> current_month;
	cout << "Year : ";
	cin >> current_year;
//Check for Invalid Inputs.
	if (current_year < birth_year) 
	{
		cout << "Hey! Current Year should be Greater than the Birth Year!";
		return 1;
	}
	else if ((current_date < 1 || current_date > 31) || (birth_date < 1 || birth_date > 31))
	{
		cout << "Hey! That is an invalid date!";
		return 1;
	}
	else if ((current_month < 1 || current_month > 12) || (birth_month < 1 || birth_month > 12))
	{
		cout << "Hey! Such a month doesn't exist!";
		return 1;
	}
	else if (current_year == birth_year && current_month < birth_month)
	{
		cout << "Hey! This is practically impossible!";
		return 1;
	}
	else if ((current_year == birth_year) && (current_month == birth_month) && (birth_date > current_date))
	{
		cout << "Hey! This is practically impossible!";
		return 1;
	}
	else
	{
		req_month = current_month - 1;
		if (req_month == 0)
		{
			req_month = 12 + (current_month - 1);
		}
		else
		{
			req_month = req_month;
		}
		if ((req_month == 1 || req_month == 3 || req_month == 5 || req_month == 7 || req_month == 8 || req_month == 10 || req_month == 12))
			month_factor = 31;
		else if ((req_month == 4 || req_month == 6 || req_month == 9 || req_month == 11))
			month_factor = 30;
		else if (req_month == 2 && current_year % 4 == 0)
			month_factor = 29;
		else
			month_factor = 28;
	
		//Year Business
		if (current_month > birth_month)
			final_year = current_year - birth_year;
		else if (current_month == birth_month && current_date > birth_date)
			final_year = current_year - birth_year;
		else if (current_month == birth_month && current_date < birth_date)
			final_year = current_year - birth_year - 1;
		else if (current_month == birth_month && current_date == birth_date)
			final_year = current_year - birth_year;
		else
			final_year = current_year - birth_year - 1;


		//Month Business
		if (current_month > birth_month)
		{
			if (birth_date < current_date || birth_date == current_date)
			{
				final_month = current_month - birth_month;
			}
			else
				final_month = (current_month - birth_month) - 1;
		}
		else if (current_month == birth_month)
		{
			if (birth_date < current_date || birth_date == current_date)
			{
				final_month = 0;
			}
			else
				final_month = 11;
		}
		else
		{
			if (birth_date < current_date || birth_date == current_date)
			{
				final_month = 12 - (birth_month - current_month);
			}
			else
				final_month = (12 - birth_month) + (current_month - 1);
		}


		//Days Business
		if (birth_month < current_month && current_date < birth_date)
		{
			final_date = (month_factor - birth_date) + current_date;
		}
		else if (birth_month < current_month && current_date > birth_date)
			final_date = current_date - birth_date;
		else if (birth_month > current_month && current_date > birth_date)
			final_date = current_date - birth_date;
		else if (birth_month > current_month && current_date < birth_date)
		{
			final_date = (month_factor - birth_date) + current_date; 
		}
		else if (current_date == birth_date)
			final_date = 0;
		else if (birth_month == current_month && birth_date < current_date)
			final_date = current_date - birth_date;
		else
		{
			final_date = (month_factor - birth_date) + current_date;
		}
		
		if ((current_month == 3 && birth_month == 2) && (current_date < birth_date) &&
			 (current_year % 4 == 0))
		{
			final_date++;
		}
		else
			final_date = final_date;
	
	}
	cout << "You are " << final_year << " years " << final_month << " months and " << final_date << " days old." << endl;
	return 0;
}
	