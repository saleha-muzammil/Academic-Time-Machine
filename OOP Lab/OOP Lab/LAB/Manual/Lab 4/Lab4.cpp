#include<iostream>
#include<fstream>
using namespace std;

class Helper
{
public:
	static int StringLenght( char* str )
	{
		// This function should return lenght of str
		
	}
	static char* GetStringFromBuffer(char* str)
	{
		//This function should allocate required memory on heap, 
		//copy string in this memory and return newly created cstring.
		
	}
};

class Car
{
private:
	static int totalCars;	// initialize it yourself
	int model;	
	char* make;
	char* name;
	char* color;
public:
	Car()
	{
		model = 0;
		color = make = name = 0;
		totalCars++;
	}
	//Write Getter of totalCars yourself
	
	void SetValues(int _model, char* _make, char* _name, char* _color)
	{
		//This is how we call static functions without object		
		make = Helper::GetStringFromBuffer(_make);
		
		//Set rest of the values yourself.
	}
	void PrintListView()
	{
		//Write yourself
	}
	void PrintDetailView()
	{	
		//Write yourself
	}
	~Car()
	{		
		cout << "Destroying ";
		PrintListView();
		//Deallocate memory yourself
	}
	void Input()
	{		
		//Do not consume one extra byte on heap
		
	}

};

Car* ReadDataFromFile()
{
	ifstream fin;
	int totalCars = 0;
	char buffer[80];
	int model;
	char make[20];
	char name[20];
	char color[20];


	fin.open("CarsData.txt");
	if (fin.is_open())
	{
		fin >> totalCars;
		//cout << totalCars;
		fin.getline(buffer, 80, '\n');	//We are not saving it
		//cout << buffer << endl;

		Car* carsList = new Car[totalCars];
		int i = 0;
		while (!fin.eof())
		{
			fin >> model;
			fin >> make;
			fin >> name;
			fin >> color;
			//Uncomment this line to check what fin has read
			//cout << model << " " << make << " " << name << " " << color << endl;
			carsList[i].SetValues(model, make, name, color);
			i++;
		}
		return carsList;
	}
	else
	{
		return 0;
	}
}

void main()
{
	Car* carsList = ReadDataFromFile();
	int count = 0;
	if (carsList != 0)
	{
		
		count = Car::GetTotalCars();	//Calling static function
		cout << "Total Number of Cars in System:\t" << count << endl;
		cout << "\nCars List:\n\n";
		{
			Car temp = carsList[0];
			temp.PrintListView();
			
			for (int i = 1; i < count ; i++)
			{				
				temp = carsList[i];
				temp.PrintListView();
			}			
		}
		delete[] carsList;
	}

	
	cout << "Total Number of Cars in System:\t" << Car::GetTotalCars() << endl << endl << endl;

	Car testCar;	
	testCar.Input(); // Take car data from user
	testCar.PrintDetailView();
		
	cout << "Total Number of Cars in System:\t" << testCar.GetTotalCars() << endl << endl << endl;

}

