//Prints hardcoded list of item's prices, subtotal of the sale and the total sale.
#include <iostream>
using namespace std;

int main()
{
	float item1 = 12.95;
	float item2 = 24.95;
	float item3 = 6.95;
	float item4 = 14.95;
	float item5 = 3.95;
	float sub_total = 0.0;
	float tax_factor = 0.06;
	float sales_tax = 0.0;
	float total_sale = 0.0;

	cout << "Price of item 1 = Rs " << item1 << endl;
	cout << "Price of item 2 = Rs " << item2 << endl;
	cout << "Price of item 3 = Rs " << item3 << endl;
	cout << "Price of item 4 = Rs " << item4 << endl;
	cout << "Price of item 5 = Rs " << item5 << endl;
	
	sub_total = item1 + item2 + item3 + item4 + item5;
	sales_tax = sub_total * tax_factor;
	total_sale = sub_total + sales_tax;
	cout << endl;
	cout << "The subtotal of the sale: " << sub_total << endl;
	cout << "The sales tax is: " << sales_tax << endl;
	cout << "Total sale: " << total_sale << endl;
	return 0;
}