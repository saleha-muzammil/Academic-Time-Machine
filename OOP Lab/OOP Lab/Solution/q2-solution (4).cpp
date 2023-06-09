#include<iostream>
using namespace std;

template<class T1>
class Helper
{
public:
	static int  Length(T1* array);
	static T1* UniqueValues(T1* array,int size);
	static T1* Arraydiff(T1* arr1, T1* arr2,int size1,int size2);
	static T1* Arraymerge(T1* arr1, T1* arr2, int size1, int size2);
	static T1* ArraySort(T1* arr,int size);
	static T1* Intersection(T1* arr1, int size1, T1* arr2, int size2);
	static bool Comparison(T1* arr, T1* arr2, int size1, int size2);
};


template<class T1>
T1* Helper<T1>::UniqueValues(T1* array,int size)
{
	int realsize = size;
	int status = 0;
	int counter = 0;
	for (int i = 0;i < size;i++)
	{
		int n = array[i];
			for (int j = i + 1;j < size-1;j++)
			{
				
					if (n == array[j])
					{
						int temp = array[j];
						array[j] = array[j + 1];
						array[j + 1] = temp;
						status = 1;
						

					}
				
				

			}
			if (status == 1)
			{
				realsize--;
				
				status = 0;
			}

	}
	/*cout << realsize << endl;*/
	
	int n = array[realsize-1];
	T1* array1 = new T1[realsize+1];
	for (int i = 0;i < realsize;i++)
	{
		
		array1[i] = array[i];
		
		cout << array[i] << endl;
	}
	array[realsize+1] = n;
	for(int i = 0;i < realsize + 1;i++)
	{
		cout << array[i] << endl;
	}
	return array1;

}

template<class T1>
int  Helper<T1>::Length(T1* array)
{
	int counter=1;
	;
	for (int i = 1;array[i] != array[i-1];i++)
	{
		cout << array[i];
		counter++;
	}
	return counter;
}

template<class T1>
T1* Helper<T1>::Arraydiff(T1* arr1, T1*arr2,int size1,int size2)
{
	int realsize = size1 + size2;

	T1* array = new T1[realsize];
	int k = 0;
	
		for (int i = 0;i < size1;i++)
		{
			array[k] = arr1[i];
			k++;
		}
		for (int i = 0;i < size2;i++)
		{
			array[k] = arr2[i];
		}

		T1* real = Helper::UniqueValues(array, realsize);
		delete[] array;
		return real;
	
}

template<class T1>
T1* Helper<T1>::ArraySort(T1* arr,int size)
{
	
	
	for (int i = 0;i < size;i++)
	{
		
		for (int j = i + 1;j < size;j++)
		{
			if (arr[j ] < arr[i])
			{
				int small = arr[i];
				arr[i] = arr[j];
				arr[j] = small;
			}
		}

	}
	return arr;
}

template<class T1>
T1* Helper<T1>::Arraymerge(T1* arr1, T1* arr2, int size1, int size2)
{
	int realsize = size1 + size2;
	T1* array = new T1[realsize];
	int k = 0;
	for (int i = 0;i < size1;i++)
	{
		array[k] = arr1[i];
		k++;
	}
	for (int i = 0;i < size2;i++)
	{
		array[k] = arr1[i];
		k++;
	}
	T1* array1 = Helper::ArraySort(array, realsize);
	return array1;
};

template<class T1>
T1* Helper<T1>::Intersection(T1* arr1, int size1, T1* arr2, int size2)
{
	int counter = 0;
	int k = 0;
	for (int i = 0;i < size1;i++)
	{
		while (k != size2)
		{
			if (arr1 == arr2[k])
			{
				counter++;
				k = 0;
				break;
			}
			k++;
		}
		k = 0;
		
		
	}
	T1* real = new T1[counter];
	k = 0;
	int a = 0;
	for (int i = 0;i < size1;i++)
	{
		while (k != size2)
		{
			if (arr1 == arr2[k])
			{
				
				real[a] = arr2[k];
				a++;
				k = 0;
				break;
			}
			k++;
		}
		k = 0;


	}
	return real;
}

template<class T1>
bool Helper<T1>::Comparison(T1* arr1, T1* arr2, int size1, int size2)
{
	bool isFound = true;

	if (size1 == size2)
	{
		for (int i = 0;i < size1;i++)
		{
			if (arr1[i] != arr2[i])
			{
				isFound = false;
				return false;
			}
		}
		
	}
	else
	{
		return false;
	}
	return true;
}





template<class T>

class SET
{
private:
	T* data;
	int size;

public:
	SET();
	SET(T* array,int size1);
	~SET();
	void Print();

	T operator-(T arr2);
	T operator+(T arr2);
	T operator^(T temp);
	bool operator==(T temp);
};

template<class T>
SET<T>::SET()
{
	data = nullptr;
}

template<class T>
SET<T>::SET(T* array, int size1)
{
	data = Helper<T>::UniqueValues(array, size1);
	for (int i = 0;i < 3;i++)
	{
		cout << data[i] << endl;
	}
	size=Helper<T>::Length(data);


}
template<class T>
SET<T>::~SET()

{
	if (data != nullptr)
	{
		delete[] data;
	}
}

	template<class T>
T SET<T>::operator-(T arr2)
{
	if (data != nullptr)
	{
		T obj();
		obj.data = Helper<T>::Arraydiff(data, arr2.data, size, arr2.size);
		obj.size = Helper<T>::Length(obj.data);
	}
	else
	{
		return 0;
	}
	return obj;
}

template<class T>
void SET<T>::Print()
{
	if (data != nullptr)
	{
		for (int i = 0;i < size;i++)
		{
			cout << data[i] << " ";
		}
		cout << endl << endl;
	}
	else
	{
		cout << "No output in the array"<<endl;
	}
}

template<class T>
T SET<T>:: operator+(T arr2)
{
	if (data != nullptr)
	{
		T temp();
		obj.data = Helper<T>::Arraymerge(data, arr2.data, size, arr2.size);
		obj.size=Helper<T>::Length(obj.data)
	}
	else
	{
		return 0;
	}
	return obj;

}

template<class T>
T SET<T>::operator^(T temp)
{
	if (data != nullptr)
	{
		T obj();
		obj.data = Helper<T>::Intersection(data, size, temp.data, temp.size);
		obj.size = Helper<T>::Length(obj.data);
	}
	else
	{
		return 0;
	}
	return obj;

}

template<class T>
bool SET<T>::operator==(T temp)
{
	if (data != nullptr)
	{
		bool isFound = true;
		isFound = Helper<T>::Comparison(data,temp.data,size,temp.size);
		return isFound;
	}
	else
	{
		return false;
	}

	}
	



