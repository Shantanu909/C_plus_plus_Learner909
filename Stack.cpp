#include<iostream>
using namespace std;
class StackUsingArray{
	public:
		int s[10];
		int top;
		StackUsingArray(){
			top = -1;
		}
		int pop(){
			if(top==-1)
			{
				cout<<"Underflow";
				return -1;
			}else{
				return s[top--];
			}	
		}
		void push(int data){
			if(top == (sizeof(s)/sizeof(int))-1){
				cout<<"Overflow";
			}
			else{
				top++;
				s[top] = data;
			}
		}
		void display(){
			if(top==-1)
			{
				cout<<"Stack is empty";
				return;
			}
			cout<<"stack"<<"\n";
			for(int i=0;i<=top;i++)
			{
				cout<<s[i]<<"\n";
			}
		}
		
};

int main(){
	StackUsingArray sobj;
	int choice;
	cout<<"Welcome to the code for Stack interfacing\n";
		int i;
	i=1;
	while(i>0)
	{
	cout<<"Please select your choice of function for the stack\n";
	cout<<"1.POP\n";
	cout<<"2.PUSH\n";
	cout<<"3.Display\n";
	cin>>choice;

	
		switch(choice)
		{
		
			case 1:
			sobj.pop();
			
			break;
			case 2:			
				int var;
				cout<<"Please enter the number you want to push\n";
				cin>>var;
				sobj.push(var);
			break;
			
			case 3:
			{
			
				sobj.display();
			}
				break;
			default:
			
			
				cout<<"Invalid input!\n";
			
			break;
	}
		cout<<"Do you want to do any other operation? [y]/[n]\n";
		char choice;
		cin>>choice;
		if(choice=='y')
		{
		
			i++;
		}
		else
		{
			i=0;
		}
	
}
}
