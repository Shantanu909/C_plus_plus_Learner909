#include <iostream>
#include <string>
using namespace std;
void greet(string s)
{
	cout<<"Welcome to the call by value program ";
	cout<<s;
}
int main()
{	string s;
	cout<<"Welcome to the code for call by value and call by refrence \n";
	cout<<"Please enter your name\n";
	cin >>  s;
	greet(s);
}