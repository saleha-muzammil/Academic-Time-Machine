#include <iostream>
#include <cstring>
using namespace std;

class RomanNumber 
{
	int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	const char* symbols[14] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	char* roman;
	int len;
public:
	RomanNumber(const char* roman = nullptr, int len = 0)
	{
		this->len = len;
		this->roman = new char[this->len + 1];

		for (int i = 0; i < this->len; i++)
			this->roman[i] = roman[i];
		this->roman[len] = 0;
	}

	RomanNumber(const RomanNumber& obj)
	{
		this->len = obj.len;
		this->roman = new char[this->len + 1];

		for (int i = 0; i < this->len; i++)
			this->roman[i] = obj.roman[i];
		this->roman[len] = 0;
	}

	RomanNumber(int num)
	{
		char* ptr = IntToRoman(num);
        this->len = strlen(ptr);
		this->roman = new char[this->len + 1];

        for (int i = 0; i < this->len; i++)
            this->roman[i] = ptr[i];
        this->roman[len] = 0;
        delete[] ptr;
	}

	~RomanNumber()
	{
		delete[] this->roman;
		this->roman = nullptr;
	}

    int RomanCharToValue(char c)
    {
        switch (c)
        {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
    }

    int RomanToInt(string s)
    {
        int total = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int currentVal = RomanCharToValue(s[i]);
            if (i < n - 1)
            {
                int next = RomanCharToValue(s[i + 1]);
                if (currentVal < next)
                    total = total - currentVal;
                else
                    total = total + currentVal;
            }
            else
                total = total + currentVal;
        }
        return total;
    }

    char* IntToRoman(int num)
    {
        char* newRoman = new char[100]; // Sufficient size for Roman numerals
        int index = -1; // Start at -1 to correctly increment index

        for (int i = 0; i < 13; i++)
        {
            while (num >= values[i])
            {
                for (int j = 0; symbols[i][j] != '\0'; j++)
                {
                    newRoman[++index] = symbols[i][j]; // Write characters starting at index 0
                }
                num -= values[i];
            }
        }
        newRoman[++index] = '\0'; // Properly terminate the string

        return newRoman;
    }

    friend RomanNumber operator +(RomanNumber obj1, RomanNumber obj2);
    friend RomanNumber operator -(RomanNumber obj1, RomanNumber obj2);
    friend RomanNumber operator *(RomanNumber obj1, RomanNumber obj2);
    friend RomanNumber operator /(RomanNumber obj1, RomanNumber obj2);
    friend bool operator ==(RomanNumber obj1, RomanNumber obj2);
    friend bool operator !=(RomanNumber obj1, RomanNumber obj2);
    friend bool operator >(RomanNumber obj1, RomanNumber obj2);
    friend bool operator <(RomanNumber obj1, RomanNumber obj2);
    
    RomanNumber operator ++()
    {
		int num = RomanToInt(this->roman);
		num++;
		char* newRoman = IntToRoman(num);

		delete[] this->roman;
		this->roman = newRoman;
		this->len = strlen(this->roman);
		return *this;
    }
     
    RomanNumber operator ++(int k)
    {
		int num = RomanToInt(this->roman);
        RomanNumber temp(num);
		num++;
		char* newRoman = IntToRoman(num);

		delete[] this->roman;
		this->roman = newRoman;
		this->len = strlen(this->roman);
		return temp;
    }

    RomanNumber operator --()
    {
		int num = RomanToInt(this->roman);
		num--;
		char* newRoman = IntToRoman(num);

		delete[] this->roman;
		this->roman = newRoman;
		this->len = strlen(this->roman);
		return *this; 
    }

    RomanNumber operator --(int k)
    {
		int num = RomanToInt(this->roman);
		RomanNumber temp(num);
		num--;
		char* newRoman = IntToRoman(num);

		delete[] this->roman;
		this->roman = newRoman;
		this->len = strlen(this->roman);
		return temp;
    }
};

RomanNumber operator +(RomanNumber obj1, RomanNumber obj2)
{
    int num1 = obj1.RomanToInt(obj1.roman);
    int num2 = obj2.RomanToInt(obj2.roman);

    int sum = num1 + num2;

    RomanNumber rtrn;
    rtrn.roman = rtrn.IntToRoman(sum);
    rtrn.len = strlen(rtrn.roman);
    return rtrn;
}

RomanNumber operator -(RomanNumber obj1, RomanNumber obj2)
{
    int num1 = obj1.RomanToInt(obj1.roman);
    int num2 = obj2.RomanToInt(obj2.roman);

	if (num1 < num2)
	{
		cout << "Subtraction not possible" << endl;
		RomanNumber rtrn;
		rtrn.roman = nullptr;
		rtrn.len = 0;
		return rtrn;
	}
    else
    {
        int sub = num1 - num2;

        RomanNumber rtrn;
        rtrn.roman = rtrn.IntToRoman(sub);
        rtrn.len = strlen(rtrn.roman);
        return rtrn;
    }
    
}

RomanNumber operator *(RomanNumber obj1, RomanNumber obj2)
{
    int num1 = obj1.RomanToInt(obj1.roman);
    int num2 = obj2.RomanToInt(obj2.roman);

    int mult = num1 * num2;

    RomanNumber rtrn;
    rtrn.roman = rtrn.IntToRoman(mult);
    rtrn.len = strlen(rtrn.roman);
    return rtrn;
}

RomanNumber operator /(RomanNumber obj1, RomanNumber obj2)
{
    int num1 = obj1.RomanToInt(obj1.roman);
    int num2 = obj2.RomanToInt(obj2.roman);

    int divs = num1 / num2;

    RomanNumber rtrn;
    rtrn.roman = rtrn.IntToRoman(divs);
    rtrn.len = strlen(rtrn.roman);
    return rtrn;
}

bool operator ==(RomanNumber obj1, RomanNumber obj2)
{
    if (obj1.RomanToInt(obj1.roman) == obj2.RomanToInt(obj2.roman))
        return true;
	return false;
}

bool operator !=(RomanNumber obj1, RomanNumber obj2)
{
    if (obj1.RomanToInt(obj1.roman) != obj2.RomanToInt(obj2.roman))
        return true;
    return false;
}

bool operator >(RomanNumber obj1, RomanNumber obj2)
{
    if (obj1.RomanToInt(obj1.roman) > obj2.RomanToInt(obj2.roman))
        return true;
    return false;
}

bool operator <(RomanNumber obj1, RomanNumber obj2)
{
    if (obj1.RomanToInt(obj1.roman) < obj2.RomanToInt(obj2.roman))
        return true;
    return false;
}


int main()
{
	RomanNumber rn;
	char* roman = rn.IntToRoman(1994);
	cout << "1994 in Roman numerals is: " << roman << endl;
	delete[] roman; 

    int ans = rn.RomanToInt("MCMXCIV");
    cout << ans<<endl;
    cout << rn.RomanToInt("IV")<<endl;

    RomanNumber r1(4);          
    RomanNumber r2("X", 1);     
    RomanNumber r3(r2);         

    RomanNumber a("III", 3);    
    RomanNumber b("II", 2);     
    RomanNumber c = a + b;      
    RomanNumber d = a * b;      
    RomanNumber e = c - b;     
    RomanNumber f = c / b;      

    RomanNumber g("II", 2);
    RomanNumber h("X", 1);
    RomanNumber i = g - h;      

    bool test1 = (RomanNumber("V") == RomanNumber(5));    
    bool test2 = (RomanNumber("IV") != RomanNumber(5));  
    bool test3 = (RomanNumber("X") > RomanNumber("V"));   
    bool test4 = (RomanNumber("III") < RomanNumber("IV"));

    RomanNumber j("IV");
    ++j;                      
    j++;                      
    --j;                      
    j--;                      

    RomanNumber zeroTest = RomanNumber(0); 
    RomanNumber maxTest(3999); 

	return 0;
}
