//Define a class which demonstrates use of single inheritance.

#include <iostream>
#include <string>
using namespace std;


	class Tree
	{
		public:
			    string color = "Green";
		    	int nodes = 10;
		    
	};

	class Leaf: public Tree
	{
		public:
		 string greet()
		 {
		 	
		 			Tree sdf;
					string color;
					color = sdf.color;
					return color;
		 }
	};
	
int main()
{
	Leaf sdf;
	string c;
	c = sdf.greet();
	cout<<c;
}	
