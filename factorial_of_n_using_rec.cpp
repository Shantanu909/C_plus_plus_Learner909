//Write a program to find factorial of n using recursion.
#include <iostream>
using namespace std;
int Fact(int prod, int multip)
{
	prod = prod*multip;
	
	multip = multip-1;
	if(multip==1)
	{
		return prod;
	}
	Fact(prod,multip);
	
}
int main()
{
	cout<<"Welcome to the code for finding factorial of n using recursion.\n";
	cout<<"Please enter your number\n";
	int n;
	cin>>n;
	int temp=1;
	
	int temp_prod;
	temp_prod = Fact(temp,n);
	
	cout<<"Factorial product of all natural numbers till ";
	cout<< n;
	cout<< " is = ";
	cout<<temp_prod;
}
	