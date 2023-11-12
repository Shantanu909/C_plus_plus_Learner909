#include<iostream>
using namespace std;

int SizeofQueue = 5;
int queue[5];
int head = -1;
int tail = -1;
void enqueue(int data){
		if(tail==SizeofQueue-1){
			if(head==0)
			{
			cout<<"Queue is full";
	        }
	        else
	        {
	        	
			}
		}
		queue[++tail]=data;
		if(head==-1)
		head++;		
}
void dequeue(){
	if(head==-1 || tail==-1)

	cout<< "Queue is empty"; 
	int data;
	data = queue[head];
	if(head==tail){
		head = -1;	
			tail = -1;
	}else{
		head++;	
	}
}
int main()
{
		int j;
	j=1;
	while(j>0){
		
	cout<<"Welcome to the code for Queue\n";
	cout<<"Please enter your choice of operation\n";
	cout<<"1. Add element\n";
	cout<<"2. Delete element\n";
	cout<<"3. Get head count\n";
	cout<<"4. Get tail count\n";
	

	
	int choice;
	cin>>choice;
	if(choice==1)
	{
		cout<<"Please enter the data you want to add.\n";
		int dat;
		cin>>dat;
		enqueue(dat);
	}
	else if(choice==2)
	{
		dequeue();
		cout<<"\n";
		
	}	
	else if(choice=3)
	{
		cout<<head;
		cout<<"\n";
	}
	else if(choice==4)
	{
		cout<<tail;
		cout<<"\n";
	}
	cout<<"Queue: \n";
	int i;
	for(i=0;i<SizeofQueue;i++)
	{
		cout<<queue[i];
		cout<<"\n";
	
	}
	cout<<"Would you like to exit the code? Press zero for yes, any other number for no.\n";
	cin>>j;
	}

}