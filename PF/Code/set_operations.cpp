#include<iostream>
#include<Windows.h>
#include <vector>  
#include <algorithm>  
 
using namespace std;
void task1();
void task2(int s1[], int s2[], int,int);
void task3(int s1[], int s2[], int, int);
void task4(int s1[], int s2[], int, int,bool,bool,int,int);
void task5(int s1[], int s2[], int, int);
void task6(int s1[], int s2[], int, int);
void task7(int s1[], int s2[], int, int);



void task1()
{
	
	int s1[500];
	int s2[500];
	int As, Bs;
	cout << "\t\tTask 1. Entering 2 sets (of unique integers)" << endl;
	

	cout << "\t\tEnter the number of elements in set A: ";
	cin >> As ;
	cout << "\t\tEnter the number of elements in set B: ";
	cin >> Bs;

	cout << endl;
	bool same = 0;
	if (As > 0)
	{
		cout << "Enter the elements in set A: \n";
	}
	
	for (int i = 0; i < As; i++)
	{
		cin >> s1[i];
		

		for (int j = 0; j < i; j++)
		{
			same = (s1[i]==s1[j]);

			if (same)
			{

				cout << "'" << s1[i] << "' at index " << j << " has already been entered.Enter different number \n";
				i--;
				break;	



			}
			else if (!same)
			{
				continue;
			}
		}

	}
	

	if(Bs>0)
	{
		cout << "Enter the elements in set B: \n";
	}
	
	for (int i = 0; i < Bs; i++)
	{
		cin >> s2[i];
		
		for (int j = 0; j < i; j++)
		{
			same = (s2[i]-s2[j]==0);

			if (same)
			{

				cout << "'" << s2[i] << "' at index " << j << " has already been entered.Enter different number \n";
				--i;
				break;
				



			}
			else if (!same)
			{
				continue;
			}
		}
		
	}
	
	task2(&s1[0], &s2[0], As, Bs);
	task3(&s1[0], &s2[0], As, Bs);
	
	
}
void task2(int s1[], int s2[], int As, int Bs)
{
	
	
	cout << endl << endl << "\n\n\t\tTask 2. Displaying the sets. " << endl;
	Sleep(2000);
	cout << " \t\tA = ";
	cout << " {";
	for (int i = 0; i < As; i++)//printing unsorted array
	{

		if (i == As-1)
			cout << s1[i];
		else
			cout << s1[i] << ",";
	}
	cout << "}" << endl;
	bool sol = 0;
	while (sol == 0)//asscending sorting of set A
	{
		sol = 1;
		for (int i = 0; i < As; i++)
		{
			if ((s1[i] > s1[i + 1]))
			{
				
				int tmp = s1[i];
				s1[i] = s1[i + 1];
				s1[i + 1] = tmp;
				sol = 0;

			}
		}
		
	}

	cout << " \t\tA = ";
	cout << " {";
	for (int i = 1; i <=As; i++)//printing sorted array of A
	{

		if (i == As)
			cout << s1[i];
		else
			cout << s1[i] << ",";
	}
	cout << "}" << endl<<endl;


	cout << "\t\tB = ";//unsorted arra=y printing
	cout << " {";
	for (int i = 0; i <Bs; i++)
	{
		if (i == Bs-1)
			cout << s2[i];
		else
			cout << s2[i] << ",";

	}
	cout << "}" << endl;

	sol = 0;
	while (sol == false)//asscending sorting of set B
	{
		sol = 1;
		for (int i = 0; i < Bs; i++)
		{
			if (s2[i] > s2[i + 1])
			{

				int tmp = s2[i];
				s2[i] = s2[i + 1];
				s2[i + 1] = tmp;
				sol = 0;

			}
		}
	}

	cout << "\t\tB = ";
	cout << " {";//sorted array of B
	for (int i = 1; i <= Bs; i++)
	{
		if (i == Bs)
			cout << s2[i];
		else
			cout << s2[i] << ",";

	}
	cout << "}" << endl << endl;



}

void task3(int s1[], int s2[], int As, int Bs)
{
	bool subset = 0;
	int countA = 0, countB = 0;

	cout << endl << endl << "\t\tTask 3. Checking relationship of A and B\n";
	Sleep(2000);
	for (int i = 0; i < Bs; i++) //does s1 belongs to s2
	{
		for (int j = 1; j <= As; j++)
		{
			if (s1[j] == s2[i])
			{
				countA++;
			}
		}
	}


	for (int i = 0; i < As; i++) //does s2 belongs to s1
	{
		for (int j = 1; j <= Bs; j++)
		{
			if (s1[i] == s2[j])
			{
				countB++;
			}
		}
	}
	int similarA = countA;
	int similarB = countB;
	cout << "\t\tSimilarity index " << countA<<" or "<<countB+1 << endl<<endl;
	
	
	bool isAsub = 0, isBsub = 0;
	if (countA == As)
	{
		
		cout << "\t\tA is a subset of B" << endl;
		isAsub = 1;
	}
	if (countB == Bs)
	{
		
		cout << "\t\tB is a subset of A";
		isBsub = 1;
	}
	if (countA != As && countB != Bs)
		cout << "\t\tNeither A nor B is a subset of the other. \n\n";

	task4(&s1[0], &s2[0], As, Bs, isAsub, isBsub,similarA,similarB);
	task5(&s1[0], &s2[0], As, Bs);
	task6(&s1[0], &s2[0], As, Bs);
	task7(&s1[0], &s2[0], As, Bs);


}
void task4(int s1[], int s2[], int As, int Bs, bool isAsub, bool isBsub, int similarA, int similarB)

{
	cout << endl << endl << "\n\t\tTask 4. Displaying Union set of A and B\n";
	Sleep(2000);
	//union of A and B
	int U = As + Bs;
	int onion[1000]={0};
	
	//assigning values to union set "onion"
	/*if (isAsub)
	{
		for (int i = 0; i < Bs; i++)
		{

			{
				onion[i] = s2[i];
			}

		}
	}
	if (isBsub)
	{
		for (int i = 0; i < As; i++)
		{

			{
				onion[i] = s1[i];
			}

		}
	}
	if (isBsub && isAsub)
	{
		for (int i = 0; i < As; i++)
		{

			{
				onion[i] = s1[i];
			}

		}
	}*/



	if (!isBsub && !isAsub)
	{
		
		/*for (int i = 0; i < Bs; i++)
			onion[i] = s2[i];

		cout << "\t\tA U B = {";
		int k=As;
		for (int i = 0; i < Bs; i++)
		{
			int c = 1;
			for (int j = 0; j < Bs; j++)
			{
				if (s2[i] == s1[j])
				{
					c = 0;
					break;
				}
			}
			if (c == 1)
			{
				onion[k] = s2[i];
				k++;
			}
		}*/


		/*for (int i = 0; i < k; i++)
			cout << onion[i] << ",";
		cout << "}\n\n";*/

		int i, k, a, j;
		cout << "\t\tA U B = {";


		for (a =1 ; a < As+1; a++)
		{
			cout << s1[a] << ",";
		}

		for (int k = 1; k <= Bs; k++)
		{
			for (i = 1; i <= As; i++)
			{
				if (s2[k] == s1[i])
					break;
			}
			if (i > As)
				cout<< s2[k]<<",";
			

			
		}
		cout << "}\n\n\n";
		
	}



	//printing onion which is union set of A and B
	if (isAsub)
	{
		
		cout << "\t\tA U B = ";
		cout << " {";//sorted array of B
		for (int i = 1; i <= Bs; i++)
		{
			if (i == Bs)
				cout << s2[i];
			else
				cout << s2[i] << ",";

		}
		cout << "}" << endl << endl;
			
				//cout << "\t\tA U B = ";
				//cout << " {";//sorted array of B
				//for (int i = 0; i < Bs; i++)
				//{
				//	if (i == Bs-1)
				//		cout << onion[i];
				//	else
				//		cout << onion[i] << ",";

				//}
				//cout << "}" << endl << endl;
			

		
	}




	if (isBsub)
	{
		cout << " \t\tA U B = ";
		cout << " {";
		for (int i = 1; i <= As; i++)//printing sorted array of A
		{

			if (i == As)
				cout << s1[i];
			else
				cout << s1[i] << ",";
		}
		cout << "}" << endl;

		//cout << "\t\tA U B = ";
		//cout << " {";//sorted array of u
		//for (int i = 1; i <= As; i++)
		//{
		//	if (i == As-1)
		//		cout << onion[i];
		//	else
		//		cout << onion[i] << ",";

		//}
		//cout << "}" << endl << endl;
	}



	if (isBsub && isAsub)
	{
		cout << " \t\tA U B = ";
		cout << " {";
		for (int i = 1; i <= As; i++)//printing sorted array of AUB i.e. A
		{

			if (i == As)
				cout << s1[i];
			else
				cout << s1[i] << ",";
		}
		cout << "}" << endl;
	}


	if (!isBsub && !isAsub && (similarA == 0 && similarB==0 ))
	{
		cout << " \t\tA U B = ";
		cout << " {";
		for (int i = 1; i <= As; i++)//printing sorted array of A
		{

			
		
				cout << s1[i] << ",";
		}
		for (int i = 1; i <= Bs; i++)
		{
			if (i == Bs)
				cout << s2[i];
			else
				cout << s2[i] << ",";
		}
		cout << "}" << endl;
	}


	
	
	
	
}
void task5(int s1[], int s2[], int As, int Bs)
{
	cout << "\n\n\t\tTask 5. Intersection of set A and B\n";
	Sleep(4000);
	cout << "\t\tA ^ B = { ";


	for (int i = 1; i <= As; i++)
	{
		for (int j = 1; j <= Bs; j++)
		{
			if (s1[i] == s2[j])
			{
				
				cout << s1[i] << ",";
				
			}
			
		}
	}

	cout << "}\n\n\n";
}
void task6(int s1[], int s2[], int As, int Bs)
{
	cout << "\n\n\t\tTask 6. Difference of set A and B\n";
	Sleep(4000);
	cout << "\t\tA - B = { ";

	int j=0;
	for (int i = 1; i <=As; i++)
	{
		for (j = 1; j <= Bs;j++)
		{
			if (s1[i] == s2[j])
				break;
		}
		if (j > Bs)
		cout << s1[i]<<",";
		
	}
	

	cout << "}\n";

	cout << "\t\tB - A = { ";

	j = 0;
	for (int i = 1; i <= Bs; i++)
	{
		for (j = 1; j <= As; j++)
		{
			if (s1[j] == s2[i])
				break;
		}
		if (j > As)
			cout << s2[i] << ",";

	}

	cout << "}\n\n\n";
}
void task7(int s1[], int s2[], int As, int Bs)
{
	cout << "\n\n\t\tTask 7. Cartesian Product of set A and B\n\n";
	Sleep(5000);
	cout << "\t\t A x B = = { ";
	for (int x = 1; x <= (As); x++)
	{
		for (int y = 1; y <= (Bs); y++)
		{
			if (x == As && y == Bs)
				cout << "(" << s1[x] << "," << s2[y] << ")";
			else
			cout << "(" << s1[x] << "," << s2[y] << "),";
		}
	}
	cout << " }\n\n";

}
int main()
{
	task1(); //also has task2
	//task3();
	getchar();
	int x;
	cin >> x;


}
