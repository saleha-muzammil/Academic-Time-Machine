# include <iostream>
bool Findsubstr(char *a,char*b,int l1,int l2);
using namespace std;
int main()
{
	char *a;
	char *b;
	int l1=0;
	int l2=0;
	cout<<"Enter the length of first string"<<endl;
	cin>>l1;
	cout<<"Enter the length of second string"<<endl;
	cin>>l2;
	a=new char [l1+1];
	b=new char [l2+1];
	cout<<"Enter first string"<<endl;
	cin.ignore();
	gets(a);
	cout<<"Enter second string"<<endl;
	cin.getline(b,l2);
	bool flag=Findsubstr(a,b,l1,l2);
	if(flag==1)
		cout<<"true"<<endl;
	else if(flag==0)
		cout<<"false"<<endl;
	system("pause");
	return 0;
}
bool Findsubstr(char *a,char*b,int l1,int l2)
{
	bool flag=0;
	for(int i=0;i<l1-l2+1;i++)
	{
		if(a[i]==b[0])
		{
			flag=1;
			for(int j=1;j<l2;j++)
			{
				if(a[i+j]!=b[j])
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
				break;
		}
	}
	return flag;
}
