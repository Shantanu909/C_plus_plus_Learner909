// Write a program to swap two numbers using call by reference.
#include <iostream>
using namespace std;

void swap(int a, int  b)
{
	int temp;
	temp =a;
	a=b;
	b=temp;
	cout<<"\nyour first number now is: ";
	cout<<a;
	cout<<"\nyour second number now is: ";
	cout<<b;
}
int main()
{
	cout<<"Welcome to theh code for swapping with call by refrence\n";
	cout<<"Please enter your first number\n";
	int temp1,temp2;
	cin>>temp1;
	cout<<"Please enter your second number\n";

	cin>>temp2;
	cout<<"your first number before swap is: ";
	cout<<temp1;
	cout<<"\nyour second number before swap is: ";
	cout<<temp2;
	swap(temp1,temp2);
	
}
	