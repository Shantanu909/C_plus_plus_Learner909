#include <iostream>
using namespace std;

class Node {
public:
	int temp_num1;
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BT {
public:
	
    Node* root;
    
    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }
   
    int IoT(Node* node) {
    	int temp_stor;
        if (node != nullptr) {
            IoT(node->left);
            temp_stor = node->data;
            IoT(node->right);
            return temp_stor;
        }
    }
    
     int IoT() {
        int temo;
		temo = IoT(root);
		return temo;
    }
    
    BT() : root(nullptr) {}
    void insert(int value) {
        insert(root, value);}
};


int main() {
    BT tree;
    int choice, value;
    cout<<"Welcome to the code for BST searching.\n";
    cout<<"Please enter your BST of desired size.\n";
    int i =1;
    int counter1=0;
    int temp_store;
    while(i>0)
    	{
    		cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                counter1++;
		
    	cout<<"Would you like to add more?\n";
    	cout<<"Press 0 for No, any other number for yes\n";
    	cin>>i;
    }
    cout << "Enter kth index to search: ";
    cin >> value;
		temp_store = tree.IoT();
		if (temp_store!=NULL)
		{
			cout<<temp_store;
		} 
		else {
        cout << "kth element not found as there are only";
		cout<<counter1;
		cout<<" elements are available\n";
	}
return 0;
}