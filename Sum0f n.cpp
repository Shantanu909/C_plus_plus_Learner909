/**Finding the sum of first natural n numbers*/
#include <iostream>
using namespace std;
	void sumf(int x,int temp_sum) {
	
	int n = x;
    temp_sum = temp_sum + n;
	n = n-1;
	if(n>0)
	{
	sumf(n,temp_sum);
	}
	else
	{
		cout << temp_sum;
	}
	}
	
int main() {
	cout << "Welcome to the code for sum of n number\n";
	cout << "Please enter the nth number of your number series.";
	int temp_n;
	cin >> temp_n;
	int sum = 0;
	sumf(temp_n,sum);
	
}
