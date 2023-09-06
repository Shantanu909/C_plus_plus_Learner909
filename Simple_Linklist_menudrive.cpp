/**1.) Implement Single linkedinlist using Menu driven porgram. perform insert, 
delete, count node and display all nodes.*/
//linked list
#include<iostream>
using namespace std;
class nodule {
	public:
		double	dat;		// dat
		nodule*	next;		// pointer to next
		nodule(int value) : dat(value), next(NULL) {}
};
class Lis {
	private: 
	 nodule* head;
public:
   Lis():head(NULL) {}
	
    void insert(int value) {
        nodule* newNode = new nodule(value);
        if (!head) {
            head = newNode;
        } else {
            nodule* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Element " << value << " inserted.\n" << std::endl;
    }

    bool find(int value) {
        nodule* current = head;
        while (current) {
            if (current->dat == value) {
                cout<<"Present\n";
				return true;
            }
            current = current->next;
        }
        cout<<"Not present\n";
        return false;
    }

    void del(int value) {
        if (!head) {
            cout << "Lis is empty. Cannot delete.\n" << std::endl;
            return;
        }

        if (head->dat == value) {
            nodule* temp = head;
            head = head->next;
            delete temp;
            cout << "Element " << value << " deleted.\n" << std::endl;
            return;
        }

        nodule* current = head;
        while (current->next) {
            if (current->next->dat == value) {
                nodule* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Element " << value << " deleted.\n" << std::endl;
                return;
            }
            current = current->next;
        }

        cout << "Element " << value << " not found.\n" << std::endl;
    }

    void disp() {
        if (!head) {
            cout << "Lis is empty.\n" << std::endl;
            return;
        }

        nodule* current = head;
        while (current) {
            cout << current->dat << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
  
};

int main(){
	Lis list;
	
	int choice = 0;
	int i = 0;
	double dat =0.0;

	int df =1;
	while(df>0)
	{	
	cout<<"Linked Lis \n"<<"Enter 1 for Insert\n"<<"Enter 2 for Find\n"<<"Enter 3 for Delete\n"<<"Enter 4 for Display List\n";
	cin>>choice;
	
	switch(choice){
		case 1: 			
			cout<<"Enter data to create a new node\n";
			cin>>dat;
			list.insert(dat);
			break;
		case 2: 			
			cout<<"Enter data to find from list\n";
			cin>>dat;
			list.find(dat);
			break;
		case 3: 			
			cout<<"Enter data to delete from list\n";
			cin>>dat;
			list.del(dat);
			break;
		case 4: 			
			cout<<"Display list\n";
			
			list.disp();
			break;
		default:
			cout<<"Invalid choice\n";
	}
	cout<<"Press 0 for exit, any other number to rerun.\n";
	int x;
	cin>>x;
	if(x==0)
	{
		df=0;
	}
}
	
}




