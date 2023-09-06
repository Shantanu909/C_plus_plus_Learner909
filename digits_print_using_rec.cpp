//1 Write a program to find sum of digit using recursion.
#include <iostream>
using namespace std;
int Num(int num)
{
	if(num!=0)
	{
	cout<<num%10; 
	cout<<"\n";
	num = num/10;
	Num(num);
}
}

int main()
{
	cout<<"Welcome to the code for finding sum of digits using recursion.\n";
	cout<<"Please enter your number\n";
	int n;
	cin>>n;	
	int temp_prod;
	temp_prod = Num(n);
	

}
	