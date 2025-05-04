#include <iostream>
using namespace std;

void allocateMemory(int*& arr, int& size)
{
    do {
        cout << "Enter the size of the array: ";
        cin >> size;
        if (size <= 0)
            cout << "Invalid size. Please enter a positive number\n";
    } while (size <= 0);

    arr = new int[size];

    //Q1: What if both the parameters were by value?
    //Ans: The changes made to the parameters in the function would not be reflected in the main function.
}

void getData(int* const& p, int* const& q)
{
    int i = 0;
    while (i < (q - p + 1)) {
        cout << "Enter the element of the array at index#" << i << ": ";
        cin >> *(p + i);
        if (*(p + i) < 0)
            cout << "Invalid input. Please enter a positive number\n";
        else
            i++;
    }

    //Q2: What if we receive the parameters as by reference const pointer to const int?
    //Ans: The function would not be able to change the values of the parameters.
}

void growArray(int*& ptr, int& size)
{
    int newSize;
    do {
        cout << "Enter the new size of the array (Grow): ";
        cin >> newSize;
        if (newSize <= size * 2)
            cout << "Invalid size. Please enter a number greater than double the current size\n";
    } while (newSize <= size * 2);

    int* temp = new int[newSize];

    for (int i = 0; i < size; i++)
        *(temp + i) = *(ptr + i);

    for (int i = size; i < newSize; i++) 
    {
        do {
            cout << "Enter the element of the array at index#" << i << ": ";
            cin >> *(temp + i);
            if (*(temp + i) < 0)
                cout << "Invalid input. Please enter a positive number\n";
        } while (*(temp + i) < 0);
    }

    delete[] ptr; // Deallocate old memory
    ptr = temp;
    size = newSize;

    //Q3: Why de-allocation and relocation?
    //Ans: We deallocate the memory to free up the space and then reallocate the memory to the new size.

    //Q4: What if any of the parameters i.e., pointer or the size variable or both of them were by-value.
    //Ans: The changes made to the parameters in the function would not be reflected in the main function.
}

void printArray(int const* const& ptr, int const& size)
{
    for (int i = 0; i < size; i++)
        cout << *(ptr + i) << " ";
    cout << endl;

//Q5: Why we are receiving the parameters by-reference?
//Ans: So that the changes made to the parameters in the function are reflected in the main function.

//Q6 : Why we are receiving by-reference const pointer?
//Ans: So that the function is not able to change the value of the pointer.

//Q7 : Why we are receiving by-reference const pointer to const integer?
//Ans: So that the function is not able to change the value of the pointer and the value it is pointing to.

//Q8 : Why we are receiving by-reference const integer size?
//Ans: So that the function is not able to change the value of the size.
}

void shrinkArray(int*& ptr, int& size)
{
    int newSize;
    do {
        cout << "Enter the new size of the array (Shrink): ";
        cin >> newSize;
        if (newSize >= size / 2)
            cout << "Invalid size. Please enter a number less than half of the current size\n";
    } while (newSize >= size / 2);

    int* temp = new int[newSize];

    for (int i = 0; i < newSize; i++)
        *(temp + i) = *(ptr + i);

    delete[] ptr;
    ptr = temp;
    size = newSize;
}

void getDistinct(int*& ptr, int& size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = 0; j < i && flag == false; j++)
        {
            if (*(ptr + i) == *(ptr + j))
            {
                flag = true;
            }
        }
        if (flag == false)
            count++;
    }
    int* newArr = new int[count];

    for (int i = 0, k = 0; i < size && k < count; i++)
    {
        bool flag = false;
        for (int j = 0; j < i && flag == false; j++)
        {
            if (*(ptr + i) == *(ptr + j))
                flag = true;
        }

        if (flag == false)
        {
            newArr[k] = *(ptr + i);
            k++;
        }
    }

    delete[] ptr;
    ptr = newArr;
    size = count;
}

void releaseResources(int*& ptr)
{
    delete[] ptr;
    ptr = nullptr;

    //Q9: What if we receive by-reference const pointer to integer in the parameters list? Will there be
    //any issue in de-allocation? Will there be any issue in relocating the pointer to NULL?

    //Ans: There will be no issue in de-allocation and relocating the pointer to NULL (as we are not changing the value for ptr).
}

int main()
{
    int* arr = nullptr;
    int* ptr = nullptr;
    int size = 0;

    allocateMemory(arr, size);
    ptr = arr;  

    getData(arr, arr + size - 1);

    growArray(ptr, size);
    printArray(ptr, size);

    shrinkArray(ptr, size);
    printArray(ptr, size);

    getDistinct(ptr, size);
    cout << "\nDisting Elements only: \n";
    printArray(ptr, size);

    releaseResources(ptr);
    return 0;
}
