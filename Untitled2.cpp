#include <iostream>
using namespace std;

int method_over()
{
	int temp1;
	bool temp2;
	cout <<"Welcome to the code for method overloading. Please enter your age.\n";
	cin >> temp1;
	if(temp1>18)
	{temp2 =true; }
	else{temp2 =false;}
	return temp2;
}

string method_over(int x)
{
	int temp1;
	string temp2;
	cout <<"Are you a Male or Female\n";
	cin >> temp2;
	if(temp2=="MALE"||temp2=="Male"||temp2=="male")
	{
		temp2 = "M"; 
	}
	else if(temp2=="FEMALE"||temp2=="Female"||temp2=="female")
	{
		temp2 = "F";
	}
	return temp2;
}
int method_over(int x,string s)
{
	if(x==true&&s=="M")
	{
		cout<<"You can vote";
		
	}
	else if(x==false||s=="M")
	{
		cout<<"You can vote";
	}
	
	else if(x==true&&s=="F")
	{
		cout<<"You can vote";
	}
	else if(x==false&&s=="F")
	{
		cout<<"You cannot vote";
	}
	
}
 
int main()
{
	int temp_3;
	string s;
	temp_3 = method_over();
	s = method_over(temp_3);
	method_over(temp_3,s);
}