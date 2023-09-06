//linked list
#include<iostream>
using namespace std;
class Node {
	public:
		double	data;		// data
		Node*	next;		// pointer to next
		Node(int value) : data(value), next(NULL) {}
};
class List {
	private: 
	 Node* head;
public:
   List():head(NULL) {}
	
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        std::cout << "Element " << value << " inserted." << std::endl;
    }

    bool find(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(int value) {
        if (!head) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Element " << value << " deleted." << std::endl;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                std::cout << "Element " << value << " deleted." << std::endl;
                return;
            }
            current = current->next;
        }

        std::cout << "Element " << value << " not found." << std::endl;
    }

    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
   void ReverseTheLinkedList(){
    
	Node* current = head;
    Node *prev = NULL, *next = NULL;
 
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;	
		
	}
};

int main(){
	List list;
	
	int choice = 0;
	int i = 0;
	double data =0.0;
	int temp_size;
	int temp_s;
	cout<<"Please enter the length of your linklist\n";
	cin>>temp_size;
	cout<<"Please enter the list elements one after another\n";
	for(int i=0;i<temp_size;i++)
	{
		cin>>temp_s;
		list.insert(i,temp_s);
	}
	int df =1;
	while(df>0)
	{	
	cout<<"Linked List \n"<<"Enter 1 for Insert\n"<<"Enter 2 for Find\n"<<"Enter 3 for Delete\n"<<"Enter 4 for Display List\n";
	cin>>choice;
	
	switch(choice){
		case 1: 			
			cout<<"Enter index and data to create a new node";
			cin>>i>>data;
			list.InsertNode(i, data);
			break;
		case 2: 			
			cout<<"Enter data to find from list";
			cin>>data;
			list.FindNode(data);
			break;
		default:
			cout<<"Invalid choice";
	}
	cout<<"Press 0 for exit, any other number to rerun.";
	int x;
	cin>>x;
	if(x==0)
	{
		df=0;
	}
}
	
}




