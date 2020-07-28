/*Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
A height balanced tree
        1
     /     \
   10      39
  /
5
An unbalanced tree
        1
     /    
   10   
  /
5*/
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
int height(node *node){
    if(node==NULL){
        return 0;
    }
    return 1 + max(height(node->left),height(node->right));
}
bool isBalanced(node *root)
{
    //  Your Code here
    int left_height,right_height;
    if(root==NULL){
        return 1;
    }
    left_height = height(root->left);
    right_height = height(root->right);
    if(abs(left_height-right_height)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}
void inorder(struct node *node){
	if(node==NULL){
		return;
	}
	else{
		inorder(node->left);
		cout<<node->data<<" ";
		inorder(node->right);
	}
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
	cout<<"Inorder of constructed tree is as follow :- ";
	inorder(root);
	ans = isBalanced(root);
	cout<<"\n";
	if(ans)
		cout<<"Tree is height balanced ";
	else
		cout<<"Tree is not height balanced ";
	return 0;
}
