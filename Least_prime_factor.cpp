#include <iostream>
using namespace std;


int main()
{
	int num;
	cin>>num;
	if(num==1)
	{
	 		cout<<"Least prime factor of \n";
			cout<<num;
			cout<<":\n";
			cout<<1;
			cout<<"\n";
	}
	for(int i =2;i<=num;i++)
		{         	 
			if(num%i==0)
			{
				cout<<"Least prime factor of \n";
				cout<<num;
				cout<<":\n";
				cout<<i;
				cout<<"\n";
				break;	
			}	
		}		   
			
}	
		