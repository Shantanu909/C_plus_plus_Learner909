//linked list
#include<iostream>
using namespace std;
class nodule {
	public:
		double		data;		
		nodule*		next;		
};
class stk_lis {
	public:
		stk_lis(void) { head = NULL; }	// constructor
		~stk_lis(void);				// destructor

		bool IsEmpty() { return head == NULL; }
		nodule* Insertnodule(int index, double x);	
		int Findnodule(double x);	
		int Deletenodule(double x);
		void Displaystk_lis(void);
	private:
		nodule* head;
};
nodule* stk_lis::Insertnodule(int index, double x) {
	if (index < 0) return NULL;	
	
	int currIndex	=	1;
	nodule* currnodule	=	head;
	while (currnodule && index > currIndex) {
		currnodule	=	currnodule->next;
		currIndex++;
	}
	if (index > 0 && currnodule == NULL) return NULL;
	
	nodule* newnodule	=	new	nodule;
	newnodule->data	=	x;	
	if (index == 0) {
		newnodule->next	=	head;
		head		=	newnodule;
	}
	else {
		newnodule->next	=	currnodule->next;
		currnodule->next	=	newnodule;
	}
	return newnodule;
}
int stk_lis::Findnodule(double x) {
	nodule* currnodule	=	head;
	int currIndex	=	1;
	while (currnodule && currnodule->data != x) {
		currnodule	=	currnodule->next;
		currIndex++;
	}
	if (currnodule) return currIndex;
	return 0;
}
int stk_lis::Deletenodule(double x) {
	nodule* prevnodule	=	NULL;
	nodule* currnodule	=	head;
	int currIndex	=	1;
	while (currnodule && currnodule->data != x) {
		prevnodule	=	currnodule;
		currnodule	=	currnodule->next;
		currIndex++;
	}
	if (currnodule) {
		if (prevnodule) {
			prevnodule->next	=	currnodule->next;
			
			delete currnodule;
		}
		else {
			head		=	currnodule->next;
			
			delete currnodule;
		}
		return currIndex;
	}
	return 0;
}
void stk_lis::Displaystk_lis()
{
   int num		=	0;
   nodule* currnodule	=	head;
   while (currnodule != NULL){
	cout << currnodule->data << endl;
	currnodule	=	currnodule->next;
	num++;
   }
   cout << "Number of nodes in the list: " << num << endl;
}
stk_lis::~stk_lis(void) {
   nodule* currnodule = head, *nextnodule = NULL;
   while (currnodule != NULL)
   {
	nextnodule	=	currnodule->next;
	// destroy the current node
	delete currnodule;	
	currnodule	=	nextnodule;
   }
}
int main(){
	stk_lis list;
	int chc = 0;
	
	int i = 1;
	int temp_dat=0;
	while(i>0)
	{
	cout<<"Linked stk_lis \n"<<"Enter 1 for Push\n"<<"Enter 2 for Display\n"<<"Enter 3 for Pop\n";
	cin>>chc;
	double data =0.0;
	switch(chc){
		case 1: 
			cout<<"Push\n";
			cin>>data;
			list.Insertnodule(0, data);
			temp_dat = data;
			break;
		case 2: 
			list.Displaystk_lis();
			break;
		
		case 3: 
			cout<<"Pop\n";
			list.Deletenodule(temp_dat);
			cout<<temp_dat;
			cout<<"\n";
			break;
		
		default:
			cout<<"provide valid input for function selection\n"<<endl;
	}
	cout<<"Do you want to do any other operation? [y]/[n]\n";
		char chc;
		cin>>chc;
		if(chc=='y')
		{
		
			i++;
		}
		else
		{
			i=0;
		}
}
}




// Copy,concanate,sp;oir