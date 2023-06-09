#include <iostream>
using namespace std;

class HugeInt {

	int *data;
	int size;
public:

	HugeInt();
	HugeInt(int *d, int s);
	HugeInt(const HugeInt &obj);

	void input();
	void output();

	bool isLessThan(const HugeInt & obj);
	HugeInt add(HugeInt obj);

	~HugeInt();
};
HugeInt::HugeInt()
{
	data = nullptr;
	size = 0;
}
HugeInt::HugeInt(int *d, int s)
{
	size = s;
	if (s > 0 && s < 15)
	{
		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = d[i];
		}
	}
}
HugeInt::HugeInt(const HugeInt &obj)
{
	size = obj.size;
	if (size > 0 && size < 15)
	{
		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = obj.data[i];
		}
	}
}

void HugeInt::input()
{
	char arr[15];
	cout << "\n\tEnter HugeInt number: ";
	cin.getline(arr, 15, '\n');
	int l = 0;
	for (l = 0; arr[l] != '\0'; l++);

	size = l;
	for (int i = 0; i< l; i++)
	{
		data[i] = arr[i] - 48;
	}
}
void HugeInt::output()
{
	
	for (int i = 0; i, size; i++)
	{
		cout << data[i];
	}
}

bool HugeInt::isLessThan(const HugeInt & obj)
{
	if (size == obj.size)
	{
		for (int i = 0; i < size; i++)
			if (data[i] == obj.data[i]);
			else
			{
				if (data[i] < obj.data[i])
					return 1;
				else
					return 0;
			}
	}
	else
	{
		if(size < obj.size)
			return 1;
		else
		{
			return 0;
		}
	}

}
HugeInt HugeInt::add(HugeInt obj)
{
	int max = size; int a = 1;
	int min = obj.size;
	
	if (size < obj.size)
	{
		max = obj.size;
		a = 2;
	}
	else
		min = size;
	
	
	HugeInt tempObj;
	if (a == 1)
	{
		tempObj.size = size;
		for (int i = 0; i < size; i++)
		{
			tempObj.data[i] = data[i];
		}
	}
	else
	{
		tempObj.size = obj.size;
		for (int i = 0; i < obj.size; i++)
		{
			tempObj.data[i] = obj.data[i];
		}
	}


	int sizea = size, sizeb = obj.size, sizetemp = max;
	for (int i = min ; i > 0; i--)
	{
		if ((data[sizea] + obj.data[sizeb]) < 9)
		{
			tempObj.data[sizetemp] = data[sizea] + obj.data[sizeb];
			sizea--; sizeb--; sizetemp--;
		}
		else 
		{
			int num = data[sizea] + obj.data[sizeb];
			num = num%10;
			tempObj.data[sizetemp] = num;
			sizea--; sizeb--; sizetemp--;
			tempObj.data[sizetemp];
		}
	}
	
	return tempObj;
}
HugeInt ::~HugeInt()
{
	if(data != NULL)
	delete[]data;
}
void main()
{
	HugeInt obj1;
	obj1.input();
	int data[] = { 1,2,3,4,5,6,7,8,9,4,3,1 }; int size = 12;
	HugeInt obj2(data, size);
	HugeInt obj3 = obj1.add(obj2);
	obj3.output();
	cout << " = ";
	obj1.output();
	cout << " + ";
	obj2.output();

	if (obj2.isLessThan(obj3))
	{
		cout << "\nI am Lesser" << endl;
	}
	else
	{
		cout << "\nI am bigger" << endl;
	}
	system("pause");
}