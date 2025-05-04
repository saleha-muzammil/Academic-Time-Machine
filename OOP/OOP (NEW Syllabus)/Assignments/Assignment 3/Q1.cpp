#include <iostream>
#include <cmath> 
using namespace std;

class VectorType{

private:
	double* x;
	double* y;
	double* z;

public:

	VectorType(int x = 0, int y=0, int z=0) //default and parameterized constructor
	{
		this->x = new double(x);
		this->y = new double(y);
		this->z = new double(z); 
	}

	VectorType(const VectorType& obj)  //copy constructor
	{
		this->x = new double(*obj.x);
		this->y = new double(*obj.y);
		this->z = new double(*obj.z);
	}

	~VectorType()  //destructor
	{
		delete x; // Corrected delete syntax
		delete y; // Corrected delete syntax
		delete z; // Corrected delete syntax
	}

	void operator =(const VectorType& obj)  //overloaded assignment operator
	{
		*x = *(obj.x);
		*y = *(obj.y);
		*z = *(obj.z);
	}

	double operator *( VectorType& obj)  //for dot product
	{
		double res;
		res = *(this->x) * (*(obj.x)) + *(this->y) * (*(obj.y)) + *(this->z) * (*(obj.z));
		
		return res;
	}

	double LenV()   //function to find length
	{
		return sqrt((*x * *x + *y * *y + *z * *z));
	}

	double Angle(VectorType& obj) 
	{
		double ins;
		ins = (*this * obj) / (this->LenV() * obj.LenV());

		return acos(ins);
	}

	VectorType operator +(VectorType& obj)  //addition
	{
		double a, b, c;
		a = *this->x + *obj.x;
		b = *this->y + *obj.y;
		c = *this->z + *obj.z;

		VectorType rtrn(a, b, c);
		return rtrn;
	}

	VectorType operator -(VectorType& obj)  //subtraction
	{
		double a, b, c;
		a = *this->x - *obj.x;
		b = *this->y - *obj.y;
		c = *this->z - *obj.z;

		VectorType rtrn(a, b, c);
		return rtrn;
	}

	VectorType& operator ++()  //Pre-increment (++v)
	{
		++(*x);
		++(*y);
		++(*z);
		return *this;
	}

	VectorType operator ++(int k)  	//Post-increment (v++)
	{
		VectorType temp = *this;  
		++(*x);
		++(*y);
		++(*z);
		return temp;  
	}

	VectorType& operator --()  	//Pre-decrement (--v)
	{
		--(*x);
		--(*y);
		--(*z);
		return *this;
	}

	VectorType operator --(int k)	//Post-decrement (v--)
	{
		VectorType temp = *this;  
		--(*x);
		--(*y);
		--(*z);
		return temp;
	}

	friend bool operator==(VectorType& obj1, VectorType& obj2);
	friend bool operator!=(VectorType& obj1, VectorType& obj2);
	friend istream& operator>>(istream& in, VectorType& obj);
	friend ostream& operator<<(ostream& out, VectorType& obj);


};

bool operator==(VectorType& obj1, VectorType& obj2) // == operator
{
	if (*obj1.x == *obj2.x && *obj1.y == *obj2.y && *obj1.z == *obj2.z)
		return true;
	else
		return false;
}

bool operator!=(VectorType& obj1, VectorType& obj2) // != operator 
{
	if (obj1.x == obj2.x && obj1.y == obj2.y && obj1.z == obj2.z)
		return false;
	else
		return true;
}

istream& operator>>(istream& in, VectorType& obj) // >> operator
{
	cout << "Enter x, y, and z coordinates: ";
	in >> *obj.x >> *obj.y >> *obj.z;
	return in;
}

ostream& operator<<(ostream& out, VectorType& obj) // << operator
{
	out << "(" << *obj.x << ", " << *obj.y << ", " << *obj.z << ")";
	return out;
}


int main()
{
	VectorType v1;
	VectorType v2;
	VectorType v3;

	cin >> v1;
	cout << "You entered: " << v1 << endl;
	cin >> v2;
	cout << "You entered: " << v2 << endl;
	cin >> v3;
	cout << "You entered: " << v3 << endl;

	cout << "Vector 1: " << v1 << endl;
	cout << "Vector 2: " << v2 << endl;
	cout << "Vector 3: " << v3 << endl;


	double result = v1 * v2;
	cout << "Dot Product: " << result << endl<<endl;

	cout << "Length of Vector 1: " << v1.LenV() << endl;
	cout << "Length of Vector 2: " << v2.LenV() << endl << endl;

	cout << "Angle between Vector 1 and Vector 2: " << v1.Angle(v2) << endl << endl;

	VectorType v_add = v1 + v2;
	cout << "Vector Addition (v1 + v2): " << v_add << endl;

	VectorType v_sub = v1 - v2;
	cout << "Vector Subtraction (v1 - v2): " << v_sub << endl << endl;

	//Pre-Increment
	++v1;
	cout << "Vector 1 after Pre-Increment (++v1): " << v1 << endl;

	//Post-Increment
	VectorType v4 = v2++;
	cout << "Vector 2 before Post-Increment (v4 = v2++): " << v4 << endl;
	cout << "Vector 2 after Post-Increment: " << v2 << endl << endl;

	//Pre-Decrement
	--v1;
	cout << "Vector 1 after Pre-Decrement (--v1): " << v1 << endl;

	//Post-Decrement
	VectorType v5 = v2--;
	cout << "Vector 2 before Post-Decrement (v5 = v2--): " << v5 << endl;
	cout << "Vector 2 after Post-Decrement: " << v2 << endl << endl;

	cout << "== operator:\n";
	if (v1 == v3)
		cout << "v1 and v3 are equal.\n\n";
	else
		cout << "v1 and v3 are not equal.\n\n";

	cout << "!= operator:\n";
	if (v1 != v2)
		cout << "v1 and v2 are different.\n\n";
	else
		cout << "v1 and v2 are the same.\n\n";

	return 0;
}
