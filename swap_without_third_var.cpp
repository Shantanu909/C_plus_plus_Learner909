// Write a program to swap two numbers without third variable.
#include <iostream>
using namespace std;
int main()
{
	cout<<"Welcome to theh code for swapping wihtout variables\n";
	cout<<"Please enter your first number\n";
	int temp1,temp2;
	cin>>temp1;
	cout<<"Please enter your second number\n";

	cin>>temp2;
	cout<<"your first number before swap is: ";
	cout<<temp1;
	cout<<"\nyour second number before swap is: ";
	cout<<temp2;
	temp1 = temp1+temp2;
	temp2  = temp1-temp2;
	temp1 = temp1-temp2;
	cout<<"\nyour first number now is: ";
	cout<<temp1;
	cout<<"\nyour second number now is: ";
	cout<<temp2;
}
	