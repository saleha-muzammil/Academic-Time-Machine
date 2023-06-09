#include <iostream>
#include <fstream>
using namespace std;

void printplan(char rooms[][6]);

void initializetable(char rooms[][6])
{
	for (int x = 0 ; x < 8; x++)
	{
		for (int y = 0 ; y < 6 ; y++)
		{
			rooms[x][y] = '*';
		}
	}
}



void allocateroom(char rooms[][6], int row , int col)
{
	rooms[row][col] = 'X';
	printplan(rooms);
	cout << "You have been allocated Room No. " << col +1 << " on Floor No. " << row + 1 << endl;
}


void reception(char rooms[][6])
{
	int clas = 30 , smoking = 20;
	bool available = false;
	while (clas != -1 && smoking != -1)
	{
		cout << "\t\tWelcome Customer!" << "\n\n";
		cout << "Do you want a room in first class or economy class?\nPress 1 for first class.\nPress 2 for economy class.\nPress -1 to exit.\n";
		cin >> clas;
		if (clas == 1)
		{
			available = false;
			for (int row = 0 ; row < 2 && available == false; row++)
			{
				for (int col = 0 ; col < 6 && available == false; col++)
				{
					if (rooms[row][col] == '*')
					{
						available = true;
						allocateroom(rooms,row , col);
					}
				}
			}
			if (available == false)
				cout << "We are sorry but no more rooms are available which meet your criteria\n"<<endl;
		}
		else if (clas == 2)
		{
			cout << "Do you want a room in the smoking zone or the non- smoking zone?\nPress 1 for smoking zone.\nPress 2 for non - smoking zone.\nPress -1 to exit.\n";
			cin >> smoking;
			if (smoking == 1)
			{
				available = false;
				for (int row = 5 ; row < 8 && available == false ; row++)
				{
					for (int col = 0 ; col < 6 && available == false; col++)
					{
						if (rooms[row][col] == '*')
						{
							available = true;
							allocateroom(rooms ,row , col);
						}
					}
				}
				if (available == false)
					cout << "We are sorry but no more rooms are available which meet your criteria\n"<<endl;
			}
			else if (smoking == 2)
			{
				available = false;
				for (int row = 2 ; row < 5 && available == false; row++)
				{
					for (int col = 0 ; col < 6 && available == false ; col++)
					{
						if (rooms[row][col] == '*')
						{
							available = true;
							allocateroom(rooms,row , col);
						}
					}
				}
				if (available == false)
					cout << "We are sorry but no more rooms are available which meets your criteria\n"<<endl;
			}
			else if (smoking != -1)
				cout << "Wrong Input. Please restart\n";
		}
		else if (clas != -1)
			cout << "Wrong Input. Pkease Input again\n";
	}
}


void printplan(char rooms[][6])
{
	for (int rows = 0 ; rows < 8 ; rows++)
	{
		cout << "|Floor" << rows + 1<< "\t|";
		for (int cols = 0 ; cols < 6; cols++)
		{
			cout <<rooms[rows][cols] << '\t' << "|";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	char rooms[8][6];
	initializetable(rooms);
	printplan(rooms);
	reception(rooms);
	return 0;

}
