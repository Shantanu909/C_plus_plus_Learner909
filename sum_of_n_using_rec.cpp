// Write a program to find sum of first n natural numbers using recursion.
#include <iostream>
using namespace std;
int rec_Sum(int sum, int count)
{
	count = count-1;
	if(count>0)
	{
	sum = sum+count;
	rec_Sum(sum,count);
	}
	if(count==0)
	{
		return sum;
	}
}
int main()
{
	cout<<"Welcome to the code for sum of natural number recursion.\n";
	cout<<"Please enter your upper limit of natural numbers\n";
	int n;
	cin>>n;
	int temp=n;
	int temp_sum;
	temp_sum = rec_Sum(n,temp);
	
	cout<<"sum of all natural numbers till";
	cout<< n;
	cout<< " is= ";
	cout<<temp_sum;
}
	