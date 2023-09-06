// Implement a stack data structure using an array.
#include<iostream>
using namespace std;
class StackA{
	public:
		int arr1[10];
		int up;
		StackA(){
			up = -1;
		}
		int pop(){
			if(up==-1)
			{
				cout<<"Underflow\n";
				return -1;
			}else{
				return arr1[up--];
			}	
		}
		void push(int data){
			if(up == (sizeof(arr1)/sizeof(int))-1){
				cout<<"Overflow\n";
			}
			else{
				up++;
				arr1[up] = data;
			}
		}
		void display(){
			if(up==-1)
			{
				cout<<"Stack is empty";
				return;
			}
			cout<<"stack"<<"\n";
			for(int i=0;i<=up;i++)
			{
				cout<<arr1[i]<<"\n";
			}
		}
		
};

int main(){
	StackA stkobj;
	int choose;
	cout<<"Welcome to the code for Stack interfacing\n";
		int i;
	i=1;
	while(i>0)
	{
	cout<<"Please select your choice of function for the stack\n";
	cout<<"1.POP\n";
	cout<<"2.PUSH\n";
	cout<<"3.Display\n";
	cin>>choose;

	
		switch(choose)
		{
		
			case 1:
			stkobj.pop();
			
			break;
			case 2:			
				int var;
				cout<<"Please enter the number you want to push\n";
				cin>>var;
				stkobj.push(var);
			break;
			
			case 3:
			{
			
				stkobj.display();
			}
				break;
			default:
			
			
				cout<<"Invalid input!\n";
			
			break;
	}
		cout<<"Do you want to do any other operation? [y]/[n]\n";
		char dec;
		cin>>dec;
		if(dec=='y')
		{
		
			i++;
		}
		else
		{
			i=0;
		}
	
}
}
