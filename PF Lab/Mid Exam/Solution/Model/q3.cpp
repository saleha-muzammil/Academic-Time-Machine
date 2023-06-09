#include <iostream>
using namespace std;


int main(){
	int c,d,a,num,previous_num,f_previous_num1,f_previous_num2;
	num = 0;
	c = 1;
	bool arithmetic,geometric,fibonacci;

	arithmetic = true;
	geometric = true;
	fibonacci = true;

	while(num != -9999){
		
		cin >> num;
		if (num== -9999){break;}

		if(c == 1){

			a = num;
			previous_num = num;
			f_previous_num1 = num;
			
		} else if (c == 2){

			d = num - previous_num;
			f_previous_num2 = num;

			

		}else if(c >= 3){

			if(num == f_previous_num1 + f_previous_num2){

				f_previous_num1 = f_previous_num2;
				f_previous_num2 = num;

			} else {
				fibonacci = false;
			}

			if( !(num == a + (c-1)*d) ){
				arithmetic = false;
			}

			
		}


		c++;
	}

	if(arithmetic){
		cout<<"The series is Arithmetic";
	}else if(fibonacci){
		cout<<"The series is Fibonacci";
	}else {
		cout<<"This is not a series";
	}



	cout<<endl;
	system("PAUSE");
	return 0;
}