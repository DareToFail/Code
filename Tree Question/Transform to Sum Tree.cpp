/*Given a Binary Tree where each node has positive and negative values.
Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree.
The values of leaf nodes are changed to 0.
For example, the following tree

             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

should be changed to

       20(4-2+12+6)
          /        \
     4(8-4)      12(7+5)
       /   \      /  \
     0      0    0    0
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
void toSumTree(node *node)
{
    // Your code here
    if(node==NULL){
        return;
    }
    else{
        int lold=0,rold=0,lnew=0,rnew=0;//lold - left_old_value..similarily others
        if(node->left!=NULL)
            lold = node->left->data;
        if(node->right!=NULL)
            rold = node->right->data;
        node->data = lold + rold;
        toSumTree(node->left);
        toSumTree(node->right);
        if(node->left!=NULL)
            lnew = node->left->data;
        if(node->right!=NULL)
            rnew = node->right->data;        
        node->data = node->data + rnew + lnew;
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
	toSumTree(root);
	cout<<"\nInorder of constructed tree after transform sum is as follow :- ";
	inorder(root);
	return 0;
}
