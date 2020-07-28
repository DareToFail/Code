#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *right;
	struct node *left;
};
//
struct node *newnode(int value){
	struct node *p = new struct node;
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}
//inserting new node and calling the newnode function to insert its value
struct node *insertnewnode(int a[],struct node *root,int i,int n){
	if(i<n){
		struct node *temp = newnode(a[i]);
		root = temp;
		root->left = insertnewnode(a,root->left,2*i+1,n);
		root->right = insertnewnode(a,root->right,2*i+2,n);
	}
	return root;
}
//checkfor bst
bool isBST(node *root,node *&prev){
	if(root){
		if(!isBST(root->left,prev))
			return false;
		if(prev!=NULL && root->data <= prev->data)
			return false;
		prev = root;
		return (isBST(root->right,prev));
	}
	return true;
}
int main(){
	int n;
	bool ans;
	cout<<"Enter the size of an array i.e. no. of element in tree :- ";
	cin>>n;
	int a[n];
	cout<<"Enter the value of tree in level order :- ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	struct node *root = insertnewnode(a,root,0,n);
	node *prev = NULL;
	ans = isBST(root,prev);
	if(ans)
		cout<<"Tree is BST ";
	else
		cout<<"Tree is not BST ";
	return 0;
}
