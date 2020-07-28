/*Given a Binary Tree, convert it into its mirror.
Suppose there is a tree:

             1
            / \
           2   3
              / \
             4   5
Then the mirror image will be:

              1
             / \
            3   2
           / \
          5   4
*/
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
void mirror(struct node *root){
	if(root==NULL){
		return;
	}
	else{
		struct node *temp;
		mirror(root->left);
		mirror(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
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
	mirror(root);
	cout<<"\nInorder of constructed tree after a mirror image is as follow :- ";
	inorder(root);
	return 0;
}
