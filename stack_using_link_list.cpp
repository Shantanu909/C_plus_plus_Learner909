// Implement a stack Data structure using a Linked List.
#include<iostream>
using namespace std;
class nodule {
	public:
		double		Dat;		
		nodule*		Nxt;		
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
	
	int crIndex	=	1;
	nodule* crnodule	=	head;
	while (crnodule && index > crIndex) {
		crnodule	=	crnodule->Nxt;
		crIndex++;
	}
	if (index > 0 && crnodule == NULL) return NULL;
	
	nodule* newnodule	=	new	nodule;
	newnodule->Dat	=	x;	
	if (index == 0) {
		newnodule->Nxt	=	head;
		head		=	newnodule;
	}
	else {
		newnodule->Nxt	=	crnodule->Nxt;
		crnodule->Nxt	=	newnodule;
	}
	return newnodule;
}
int stk_lis::Findnodule(double x) {
	nodule* crnodule	=	head;
	int crIndex	=	1;
	while (crnodule && crnodule->Dat != x) {
		crnodule	=	crnodule->Nxt;
		crIndex++;
	}
	if (crnodule) return crIndex;
	return 0;
}
int stk_lis::Deletenodule(double x) {
	nodule* prevnodule	=	NULL;
	nodule* crnodule	=	head;
	int crIndex	=	1;
	while (crnodule && crnodule->Dat != x) {
		prevnodule	=	crnodule;
		crnodule	=	crnodule->Nxt;
		crIndex++;
	}
	if (crnodule) {
		if (prevnodule) {
			prevnodule->Nxt	=	crnodule->Nxt;
			
			delete crnodule;
		}
		else {
			head		=	crnodule->Nxt;
			
			delete crnodule;
		}
		return crIndex;
	}
	return 0;
}
void stk_lis::Displaystk_lis()
{
   int num		=	0;
   nodule* crnodule	=	head;
   while (crnodule != NULL){
	cout << crnodule->Dat << endl;
	crnodule	=	crnodule->Nxt;
	num++;
   }
   cout << "Number of nodes in the list: " << num << endl;
}
stk_lis::~stk_lis(void) {
   nodule* crnodule = head, *Nxtnodule = NULL;
   while (crnodule != NULL)
   {
	Nxtnodule	=	crnodule->Nxt;
	// destroy the crent node
	delete crnodule;	
	crnodule	=	Nxtnodule;
   }
}
int main(){
	stk_lis list;
	int chc = 0;
	
	int i = 1;
	int temp_dat=0;
	while(i>0)
	{
	cout<<"Linked List \n"<<"Enter 1 for Push\n"<<"Enter 2 for Display\n"<<"Enter 3 for Pop\n";
	cin>>chc;
	double Dat =0.0;
	switch(chc){
		case 1: 
			cout<<"Push\n";
			cin>>Dat;
			list.Insertnodule(0, Dat);
			temp_dat = Dat;
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