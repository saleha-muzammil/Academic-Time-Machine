#include <iostream>
#include <cstring>  
#include <string>  
using namespace std;

class String
{
    char* str;
    int len;

public:
    String(const char* str = "")  // Constructor
    {
        if (str == nullptr) str = ""; 
        this->len = strlen(str);
        this->str = new char[this->len + 1];

        for (int i = 0; i < this->len; i++)
            this->str[i] = str[i];

        this->str[this->len] = '\0'; 
    }

    String(const String& obj)  // Copy Constructor
    {
        this->len = obj.len;
        this->str = new char[obj.len + 1];
        for (int i = 0; i < obj.len; i++)
            this->str[i] = obj.str[i];

        this->str[this->len] = '\0'; 
    }

    ~String() // Destructor
    {
        delete[] str;
        str = nullptr;
    }

    int Length() const
    {
        return strlen(str);
    }

    void Upper()
    {
        for (int i = 0; i < this->len; i++)
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - ('a' - 'A');

        str[this->len] = '\0';
    }

    void Lower()
    {
        for (int i = 0; i < this->len; i++)
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] + ('a' - 'A');

        str[this->len] = '\0';
    }

    char at(int i) const
    {
        if (i >= 0 && i < len)
            return this->str[i];
        return '\0'; 
    }

    String substring_(int start, int end) const
    {
        if (start < 0 || end >= len || start > end) 
            return String("");

        int newLen = end - start + 1;
        char* newStr = new char[newLen + 1];

        for (int i = 0; i < newLen; i++)
            newStr[i] = this->str[start + i];

        newStr[newLen] = '\0'; 

        String result(newStr); 
        delete[] newStr; 

        return result;
    }

    int startIndex(const char* substr) const
    {
        int subLen = strlen(substr);

        if (subLen > this->len)
            return -1;

        for (int i = 0; i <= this->len - subLen; i++)
        {
            bool flag = true;
            for (int j = 0; j < subLen; j++)
            {
                if (this->str[i + j] != substr[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }

    bool strCompare(const String& obj)
    {
        if (this->len != obj.len)
            return false;

        for (int i = 0; this->str[i] != 0; i++)
            if (this->str[i] != obj.str[i])
                return false;

        return true;
    }

    void concat(const String& obj)
    {
        int newLen = this->len + obj.len;
        char* newStr = new char[newLen + 1];

        for (int i = 0; i < this->len; i++)
            newStr[i] = this->str[i];

        for (int i = 0; i < obj.len; i++)
            newStr[this->len + i] = obj.str[i];

        newStr[newLen] = '\0';

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void concat(const char* cstr)
    {
        int newLen = this->len + strlen(cstr);
        char* newStr = new char[newLen + 1];

        for (int i = 0; i < this->len; i++)
            newStr[i] = this->str[i];

        for (int i = 0; i < strlen(cstr); i++)
            newStr[this->len + i] = cstr[i];

        newStr[newLen] = '\0';

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void concat(char c)
    {
        int newLen = this->len + 1;
        char* newStr = new char[newLen + 1];

        for (int i = 0; i < this->len; i++)
            newStr[i] = this->str[i];

        newStr[this->len] = c;
        newStr[newLen] = '\0';

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void concat(int num)
    {
        // to find length of string
        int temp = num;
        int digits = 0;
        if (num == 0) 
            digits = 1;
        else
        {
            while (temp != 0) 
            {
                digits++;
                temp = temp/10;
            }
        }
           
        int newLen = this->len + digits;
        char* newStr = new char[newLen + 1];

        for (int i = 0; i < this->len; i++)
            newStr[i] = this->str[i];

        for (int i = newLen - 1; i >= this->len; i--) //storing the number starting from the end
        {
            newStr[i] = (num % 10) + '0';
            num = num / 10;
        }

        newStr[newLen] = '\0';

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void concat(float num)
    {
        int intPart = num;
        float decimalPart = num - intPart;

        // Handling integer part
        concat(intPart);

        // Handling the decimal part
        concat('.');

        for (int i = 0; i < 5; i++) //only allowing upto 5 d.p. (checked from copilot)
        { 
            decimalPart = decimalPart * 10;
            int curDigit = decimalPart;
            concat(curDigit);
            decimalPart = decimalPart - curDigit;
        }
    }

    void prepend(const String& obj)
    {
        int newLen = this->len + obj.len;
        char* newStr = new char[newLen + 1];

        for (int i = 0; i < obj.len; i++)
            newStr[i] = obj.str[i];

        for (int i = 0; i < this->len; i++)
            newStr[obj.len + i] = this->str[i];

        newStr[newLen] = '\0';

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void prepend(const char* cstr)
    {
        int cstrLen = strlen(cstr);
        int newLen = this->len + cstrLen;
        char* newStr = new char[newLen + 1];

        for (int i = 0; i < cstrLen; i++)
            newStr[i] = cstr[i];

        for (int i = 0; i < this->len; i++)
            newStr[cstrLen + i] = this->str[i];

        newStr[newLen] = '\0';

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void prepend(char c)
    {
        int newLen = this->len + 1;
        char* newStr = new char[newLen + 1];

        newStr[0] = c;
        for (int i = 0; i < this->len; i++)
            newStr[i + 1] = this->str[i];

        newStr[newLen] = '\0';

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void prepend(int num)
    {
        // to find length of string
        int temp = num;
        int digits = 0;
        if (num == 0)
            digits = 1;
        else
        {
            while (temp != 0)
            {
                digits++;
                temp = temp / 10;
            }
        }

        int newLen = this->len + digits;
        char* newStr = new char[newLen + 1];
        
        for (int i = digits-1; i >= 0; i--)  //storing the number starting from the end   
        {
            newStr[i] = (num % 10) + '0';
            num = num / 10;
        }
           

        for (int i = 0; i < this->len; i++)
            newStr[digits + i] = this->str[i];

        newStr[newLen] = '\0';

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void prepend(float num)
    {
        int intPart = num;
        float decimalPart = num - intPart;

        int temp = intPart;
        int digits = 0;
        if (intPart == 0)
            digits = 1;
        else
        {
            while (temp != 0)
            {
                digits++;
                temp = temp / 10;
            }
        }

        int newLen = this->len + digits + 6;
        char* newStr = new char[newLen + 1];
        
        for (int i = digits - 1; i >= 0; i--)  //storing the number starting from the end   
        {
            newStr[i] = (intPart % 10) + '0';
            intPart = intPart / 10;
        }
        newStr[digits] = '.';

        for (int i = 1; i < 7; i++) //only allowing upto 5 d.p. 
        {
            decimalPart = decimalPart * 10;
            int curDigit = decimalPart;
            newStr[digits + i] = curDigit + '0';
            decimalPart = decimalPart - curDigit;
        }

        for (int i = 0; i < this->len; i++)
        {
            newStr[i + digits + 6] = this->str[i];
        }
        newStr[newLen] = 0;

        delete[] this->str;
        this->str = newStr;
        this->len = newLen;
    }

    void print() const
    {
        cout << this->str << endl;
    }

    friend String operator +(String& obj1, String& obj2);
    friend String operator +(String& obj1, char* cstr);
    friend String operator +(String& obj1, char c);
    friend String operator +(String& obj1, int num);
    friend String operator +(String& obj1, float num);

    friend String operator +(char* cstr, String& obj1);
    friend String operator +(char c, String& obj1);
    friend String operator +(int num, String& obj1);
    friend String operator +(float num, String& obj1);

    String& operator=(const String& obj) 
    {
        delete[] this->str;
        this->len = obj.len;
        this->str = new char[obj.len + 1];

        for (int i = 0; i < obj.len; i++)
            this->str[i] = obj.str[i];

        this->str[this->len] = '\0';
        return *this;
    }

    bool operator ==(const String& obj)
    {
        return strCompare(obj);
    }
    
    bool operator !=(const String& obj)
    {
        return !strCompare(obj);
    }

    bool operator <(const String& obj)
    {
        if (this->len < obj.len)
            return true;
        return false;
    }
    
    bool operator >(const String& obj)
    {
        if (this->len > obj.len)
            return true;
        return false;
    }

    friend ostream& operator <<(ostream& out, const String& obj);

    friend istream& operator >>(istream& in, String& obj);

	char operator [](int i) const
	{
		if (i >= 0 && i < len)
			return str[i];
		return '\0';
	}
};

String operator +(String& obj1, String& obj2)
{
    int newLen = obj1.len + obj2.len;
    char* newStr = new char[newLen + 1];

    for (int i = 0; i < obj1.len; i++)
        newStr[i] = obj1.str[i];

    for (int i = 0; i < obj2.len; i++)
        newStr[obj1.len + i] = obj2.str[i];

    newStr[newLen] = '\0';

    String s1(newStr);
    return s1;
}

String operator +(String& obj1, char* cstr)
{
    int newLen = obj1.len + strlen(cstr);
    char* newStr = new char[newLen + 1];

    for (int i = 0; i < obj1.len; i++)
        newStr[i] = obj1.str[i];

    for (int i = 0; i < strlen(cstr); i++)
        newStr[obj1.len + i] = cstr[i];

    newStr[newLen] = '\0';

    String s1(newStr);
    return s1;
}

String operator +(String& obj1, char c)
{
    int newLen = obj1.len + 1;
    char* newStr = new char[newLen + 1];

    for (int i = 0; i < obj1.len; i++)
        newStr[i] = obj1.str[i];

    newStr[obj1.len] = c;
    newStr[newLen] = '\0';

    String s1(newStr);
    return s1;
}

String operator +(String& obj1, int num)
{
    // to find length of string
    int temp = num;
    int digits = 0;
    if (num == 0)
        digits = 1;
    else
    {
        while (temp != 0)
        {
            digits++;
            temp = temp / 10;
        }
    }

    int newLen = obj1.len + digits;
    char* newStr = new char[newLen + 1];

    for (int i = 0; i < obj1.len; i++)
        newStr[i] = obj1.str[i];

    for (int i = newLen - 1; i >= obj1.len; i--) //storing the number starting from the end
    {
        newStr[i] = (num % 10) + '0';
        num = num / 10;
    }

    newStr[newLen] = '\0';

    String s1(newStr);
    return s1;
}

String operator +(String& obj1, float num)
{
    int intPart = num;
    float decimalPart = num - intPart;

    int temp = intPart;
    int digits = 0;
    if (intPart == 0)
        digits = 1;
    else
    {
        while (temp != 0)
        {
            digits++;
            temp = temp / 10;
        }
    }

    int newLen = obj1.len + digits + 6;
    char* newStr = new char[newLen + 1];

    for (int i = 0; i < obj1.len; i++)
        newStr[i] = obj1.str[i];



    for (int i = digits - 1 + obj1.len; i >= obj1.len; i--)  //storing the number starting from the end   
    {
        newStr[i] = (intPart % 10) + '0';
        intPart = intPart / 10;
    }
    newStr[digits + obj1.len] = '.';

    for (int i = 1; i < 7; i++) //only allowing upto 5 d.p. 
    {
        decimalPart = decimalPart * 10;
        int curDigit = decimalPart;
        newStr[digits + i + obj1.len] = curDigit + '0';
        decimalPart = decimalPart - curDigit;
    }

    newStr[newLen] = 0;

    String s1(newStr);
    return s1;
}


String operator +(char* cstr, String& obj1)
{
    int cstrLen = strlen(cstr);
    int newLen = obj1.len + cstrLen;
    char* newStr = new char[newLen + 1];

    for (int i = 0; i < cstrLen; i++)
        newStr[i] = cstr[i];

    for (int i = 0; i < obj1.len; i++)
        newStr[cstrLen + i] = obj1.str[i];

    newStr[newLen] = '\0';

    String s1(newStr);
    return s1;
}

String operator +(char c, String& obj1)
{
    int newLen = obj1.len + 1;
    char* newStr = new char[newLen + 1];

    newStr[0] = c;
    for (int i = 0; i < obj1.len; i++)
        newStr[i + 1] = obj1.str[i];

    newStr[newLen] = '\0';

    String s1(newStr);
    return s1;
}

String operator +(int num, String& obj1)
{
    // to find length of string
    int temp = num;
    int digits = 0;
    if (num == 0)
        digits = 1;
    else
    {
        while (temp != 0)
        {
            digits++;
            temp = temp / 10;
        }
    }

    int newLen = obj1.len + digits;
    char* newStr = new char[newLen + 1];

    for (int i = digits - 1; i >= 0; i--)  //storing the number starting from the end   
    {
        newStr[i] = (num % 10) + '0';
        num = num / 10;
    }


    for (int i = 0; i < obj1.len; i++)
        newStr[digits + i] = obj1.str[i];

    newStr[newLen] = '\0';

    String s1(newStr);
    return s1;
}

String operator +(float num, String& obj1)
{ 
    int intPart = num;
    float decimalPart = num - intPart;

    int temp = intPart;
    int digits = 0;
    if (intPart == 0)
        digits = 1;
    else
    {
        while (temp != 0)
        {
            digits++;
            temp = temp / 10;
        }
    }

    int newLen = obj1.len + digits + 6;
    char* newStr = new char[newLen + 1];

    for (int i = digits - 1; i >= 0; i--)  //storing the number starting from the end   
    {
        newStr[i] = (intPart % 10) + '0';
        intPart = intPart / 10;
    }
    newStr[digits] = '.';

    for (int i = 1; i < 7; i++) //only allowing upto 5 d.p. 
    {
        decimalPart = decimalPart * 10;
        int curDigit = decimalPart;
        newStr[digits + i] = curDigit + '0';
        decimalPart = decimalPart - curDigit;
    }

    for (int i = 0; i < obj1.len; i++)
    {
        newStr[i + digits + 6] = obj1.str[i];
    }
    newStr[newLen] = 0;

    String s1(newStr);
    return s1;
}


ostream& operator <<(ostream& out, const String& obj)
{
    out << obj.str;
    return out;
}

istream& operator >>(istream& in, String& obj)
{
    cout << "Enter the String: ";
    in >> obj.str;
    obj.len = strlen(obj.str);
    return in;
}

int main()
{
    String s1("aBcDeFgHiJ");
    s1.Lower();
    s1.print(); // Output: abcdefghij
    s1.Upper();
    s1.print(); // Output: ABCDEFGHIJ

    s1 = s1.substring_(2, 5);
    s1.print(); // Output: CDEF

    char xx2[4] = "EF";
    cout <<"Index is at: " << s1.startIndex(xx2) << endl; // Output: 2

    String s2("CDEF");
    if (s1.strCompare(s2))
        cout << "s1 and s2 are same\n";
    else
        cout << "s1 and s2 are not same\n";

    cout << endl;
    String s3("Skibidi");
    s3.concat(" Toilet");
    s3.print(); 

    s3.concat('!');
    s3.concat(' ');
    s3.print(); 

    s3.concat(69);
    s3.print(); 

    s3.concat(4.999999f);
    s3.print();

    cout << endl;
    String s4(" gulli");
    s4.prepend("linga ");
    s4.print();

    s4.prepend('-');
    s4.prepend(' ');
    s4.print();

    s4.prepend(6969);
    s4.print();

    s4.prepend(4.123456789f);
    s4.print();

	String w1("Hello");
	String w2("World");
    String w3("Sigma");
	String w4 = w1 + w2;
	cout << w4 << endl;
	w4 = w1 + ' ';
    cout << w4 << endl;
	w4 = w4 + w2;
	cout << w4 << endl;
	w4 = w4 + ' ';
	cout << w4 << endl;
	w4 = w4 + 69;
	cout << w4 << endl;
	w4 = w4 + 4.123456789f;
	cout << w4 << endl;

	w4 = ' ' + w1;
	cout << w4 << endl;
	w4 = ' ' + w4;
	cout << w4 << endl;
	w4 = 69 + w4;
	cout << w4 << endl;
	w4 = 4.123456789f + w4;
	cout << w4 << endl;

	cin >> w3;
	cout << w3 << endl;

	String r1("saa32");
	String r2("saa31");
	String r3("saa32");

	if (r1 == r2)
		cout << "r1 and r2 are same\n";
	else
		cout << "r1 and r2 are not same\n";

	if (r1 == r3)
		cout << "r1 and r3 are same\n";
	else
		cout << "r1 and r3 are not same\n";

	if (r1 != r2)
		cout << "r1 and r2 are not same\n";
	else
		cout << "r1 and r2 are same\n";

	if (r1 != r3)
		cout << "r1 and r3 are not same\n";
	else
		cout << "r1 and r3 are same\n";

	cout << "Char at index 2: " << s1[0] << endl;
    return 0;
}
