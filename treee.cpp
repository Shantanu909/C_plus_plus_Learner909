preorder(Node* r){
	if(r==null)
	return 
	else{
		cout<<r.data
		if(r.left!=null)
			preorder(r.left)
		if(r.right!=null)
			preorder(r.right)
		return
	}
}
postorder(Node* r){
	if(r==null)
	return 
	else{
		if(r.left!=null)
			postorder(r.left)
		if(r.right!=null)
			postorder(r.right)
		cout<<r.data
		return
	}
}
inorder(Node* r){
	if(r==null)
	return 
	else{
		if(r.left!=null)
			postorder(r.left)
		cout<<r.data
		if(r.right!=null)
			postorder(r.right)
		
		return
	}
}