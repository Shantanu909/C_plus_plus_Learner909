// Write a program to find the factors of a positive integer using recursion.

#include <iostream>
using namespace std;
int Facto(int fact, int num)
{
	if(fact>0)
	{
	
	if(num%fact==0)
	{
		cout<<fact;
		cout<<"\n";
	}
	fact = fact-1;
	Facto(fact,num);
}
}
int main()
{
	cout<<"Welcome to the code for finding factors of n using recursion.\n";
	cout<<"Please enter your number\n";
	int n;
	cin>>n;
	int temp=n;
	
	int temp_prod;
	temp_prod = Facto(temp,n);
	

}
	