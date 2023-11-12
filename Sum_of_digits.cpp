#include <iostream>
using namespace std;

class rec{
public:
	rec(int num,int sum)
	{
		
		if(num>0)
		{
			sum = sum+(num%10);
			num = num/10;		
			rec(num,sum);
		}
		
		else
		{	
			cout<<sum;
			cout<<"\n";
			cout<<num;	
		}	
		
	}
	
};

int main()
{
	int num;
	cin>>num;
	rec r(num,0);
}
