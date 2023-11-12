#include <iostream>
#include <stack>
using namespace std;

class rec{
public:
	rec(int num,int sum)
	{
		int temp_var = num/10;
		if(temp_var>0)
		{
			stack.push(num%10);
			num = num/10;
		}
		
		else
		{	cout<<"else";
			cout<<sum;
			cout<<"\n";
			cout<<num;	
		}	
		
	}
	
};


int main()
{
	stack <int> stk;
	stk.pop();
	int num;
	cin>>num;
	rec r(num,0);

}
