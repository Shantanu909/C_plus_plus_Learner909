// Write a program to generate the nth Fibonacci number using recursion.
#include <iostream>
using namespace std;
void Fib(int num, int prev1,int prev2, int max)
{
if(num<=max)
	{
		num = prev1+prev2;
		prev1 = prev2;
		prev2 = num;
		if(num<=max)
		{
		cout<<num;
		cout<<" ";
		}
		Fib(num,prev1,prev2,max);
    }
	
}
int main()
{
	cout<<"Welcome to the Fibonnaci Sequence Generator.\n";
	cout<<"Please enter your upper limit of Fibonnaci Sequence\n";
	int max;
	cin>>max;
	int n=0;
	int prev1 = 1;
	int prev2 = 1;
	cout<<"1 ";
	cout<<"1 ";
	Fib(n,prev1,prev2,max);
}
	