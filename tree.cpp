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