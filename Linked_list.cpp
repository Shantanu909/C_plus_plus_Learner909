#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}
	
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

    void find(int value) {
        Node* current = head;
        int counter=0;
        while (current) {
            if (current->data == value) {
			    cout<<"Your number: ";
                cout<<value;
                cout<<"	is present at index no:";
                cout<<current; 
                cout<<"\n";
				counter++;        
				}
            current = current->next;
        }
        if(counter=0)
        {
        	cout<<"Element not found in list!";
		}
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
	
	void count_nodes()
	{
		Node* current = head;
        int counter=0;
        while (current) {
        	counter++;
        	current = current->next;
		}
		cout<<"There are: ";
		cout<<counter;
		cout<<" nodes in the list";
		
	
}
};

int main(){
	LinkedList list;
	
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
		list.insert(temp_s);
	}
	int df =1;
	while(df>0)
	{	
	cout<<"Linked List \n";
	cout<<"Enter 1 for Insert\n";
	cout<<"Enter 2 for Find\n";
	cout<<"Enter 3 for Delete\n";
	cout<<"Enter 4 for Display List\n";
	cout<<"Enter 5 for Reversing the list\n";
	cout<<"Enter 6 for counting the nodes in the list\n";
	cin>>choice;
	
	switch(choice){
		case 1: 			
			cout<<"Enter data to create a new node\n";
			cin>>data;
			list.insert(data);
			break;
		case 2: 			
			cout<<"Enter data to find from list\n";
			cin>>data;
		    list.find(data);
			break;
		case 3: 			
			cout<<"Enter data to be deleted\n";
			cin>>data;
			list.remove(data);
			break;
		case 4: 			
			list.display();
			break;
		case 5:
			list.ReverseTheLinkedList();
			break;
		case 6:
			list.count_nodes();
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

