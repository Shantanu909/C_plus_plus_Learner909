#include <iostream>

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
		
	insert(int data){
		
		Node* Node = new Node(value);
		if(root==null)
		{
			root = newNode;
		}else{
			Node* temp = root;
			isPlaced = false;
			while(!isPlaced){
				if(temp.data<data){
					if(temp.right==null){
						temp.right = newNode;
						isPlaced = true;
					}else{
						temp = temp.right;
					}
				}else{
					if(temp.left==null){
						temp.left = newNode;
						isPlaced = true;
					}else{
						temp = temp.left;
					}
				}
			}
		}
		
	
	bool search(int find){
	if(root==null)
	{
		cout<<"Empty tree"
		return 0
	}
	else{
			cout<<"1.) Pre-order";
			cout<<"2.) Post-order";
			cout<<"3.) In-order";
			int choice1;
			cin>>choice1;
			if(choice1==1)
			{
				order(find);
				}	
			else if(choice1==2)
			{
				order(find,1);
				}	
			if(choice1==3)
			{
				order(find,true);
				}	
			
//		Node*  temp  = root;
//		isNotFound = true;
//		while(isNotFound){
//			if(temp==null){return 0;}
//			else if(temp.data == find){
//				isNotFound= false;
//				return 1;
//			}else if(temp.data < find){
//			temp = temp.right;
//			}else{
//			temp = temp.left;
//			}
		}
	}
	
		//preorder
	order(Node* r){
		if(r==null)
		return 
		else{
			cout<<r.data
			if(r.left!=null)
				order(r.left)
			if(r.right!=null)
				order(r.right)
			return
		}
	}
	//postorder
	order(Node* r,int n){
		if(r==null)
		return 
		else{
			if(r.left!=null)
				order(r.left,2)
			if(r.right!=null)
				order(r.right,2)
			cout<<r.data
			return
		}
	
	//inorder
	order(Node* r, bool r){
		if(r==null)
		return 
		else{
			if(r.left!=null)
				order(r.left,1)
			cout<<r.data
			if(r.right!=null)
				order(r.right,1)
			
			return
		}
	}
	
	
	
	}
}
};

int main()
{
	cout<<"Welcome to the code for binary tree.";
	cout<<"What do you want to do with the tree?";
	cout<<"1.) Insert";
	cout<<"2.) Delete";
	cout<<"3.) Search";
	cout<<"4.) Display";
	int choice;
	cin>>choice;
	switch(choice):
		case 1:
			cout<<"Please give the element you want to insert.";
			int n;
			cin>>n;
			insert(n);	
			break;
		case 2:
			cout<<"Please give the element you want to delete.";
			int n;
			cin>>n;
			insert(n);	
			break;
		case 3:
			cout<<"Please give the element you want to search.";
			int n;
			cin>>n;
			search(n);
			break;
		default:
			cout<<"Please enter correct option ";

}