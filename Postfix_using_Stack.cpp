// Write a program to Evaluate Postfix Expression using stack. "23*5+"
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
				
				return -1;
			}else{
				return arr1[up--];
			}	
		}
		void push(int data){
			if(up == (sizeof(arr1)/sizeof(int))-1){
				
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
			cout<<"Answer:"<<"\n";
			for(int i=0;i<=up;i++)
			{
				cout<<arr1[i]<<"\n";
			}
		}
		
};

int main(){
	StackA stkobj;
	cout<<"Welcome to the code for Stack operations\n";
		 //"23*5+"
	stkobj.push(2);
	stkobj.push(3);
	int temp1, temp2;
	temp1 = stkobj.pop();
	temp2 = stkobj.pop();
	stkobj.push(temp1*temp2);
	stkobj.push(5);
	temp1 = stkobj.pop();
	temp2 = stkobj.pop();
	stkobj.push(temp1+temp2);
	stkobj.display();	
}

