/**10). Write a program to find the sum of factors of a positive integer using
recursion.
8=> factors{1,2,4,8} => sum = 15
*/
#include <iostream>
using namespace std;

void rec_fun(int sum, int fac, int num)
{
	if(fac>0)
	{		
		if(num%fac==0)
		{
			sum = sum+fac;
		}
	fac=fac-1;
	rec_fun(sum,fac,num);
	}
	else
	{
		cout<<sum;
	}
}

int main()
{
	cout<<"Welcome to the code for factor sum\n";
	cout<<"please enter the desired number\n";
	int temp_num,temp_sum;
	cin >> temp_num;
	temp_sum=0;
	rec_fun(temp_sum,temp_num, temp_num);
}
