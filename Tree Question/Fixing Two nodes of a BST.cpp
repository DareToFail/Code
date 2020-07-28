/*Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST if necessary.
Input Tree:
         10
        /  \
       5    8
      / \
     2   20

In the above tree, nodes 20 and 8 must be swapped to fix the tree.  
Following is the output tree
         10
        /  \
       5    20
      / \
     2   8
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
void preorder(node *root,node **prev,node **a,node **b,node **c,int& count){
    if(root){
        preorder(root->left,prev,a,b,c,count);
        if(*prev==NULL)
            *prev = root;
        else{
            if((*prev)->data > root->data){
                if(count==0){
                    *a = *prev;
                    *b = root;
                    count++;
                }
                else{
                    *c = root;
                    count++;
                }
            }
            *prev = root;
        }
        preorder(root->right,prev,a,b,c,count);
    }
}
struct node *correctBST( struct node* root )
{
    struct node *prev = NULL,*a,*b,*c;
    int temp;
    int count=0;
    preorder(root,&prev,&a,&b,&c,count);
    if(count==1){
      temp = a->data;
      a->data = b->data;
      b->data = temp;
      return root;
    }
    if(count==2){
        temp = a->data;
        a->data = c->data;
        c->data = temp;
        return root;
    }
    else
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
	if(correctBST(root)){
	cout<<"\nInorder of BST after correction is as follow :- ";
	inorder(root);
	}
	else
		cout<<"\nNo correction required as it is already a BST";
	return 0;
}
