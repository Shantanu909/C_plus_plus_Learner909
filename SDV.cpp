//Wruite a program to show use of multiple inheritance
//Define a class which demonstrates use of single inheritance.

#include <iostream>
#include <string>
using namespace std;


	class Father
	{
		public:
			    string  eye_col = "Green";
		    	
		    
	};
	class Mother
	{
		public:
			    string  eye_col = "Blue";
		    	
		    
	};


	class Son: public Father, Mother
	{
		public:
		 string greet()
		 {
		 	Father fd;
		 	Mother md;
		 	string str1,str2;
			str1 = fd.eye_col;
			str2 = fd.eye_col;
		 }
	};
	
int main()
{
	Leaf sdf;
	string c;
	c = sdf.greet();
	cout<<c;
}	
