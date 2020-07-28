/*Given a binary tree, write a function to get the maximum width of the given tree. Width of a tree is maximum of widths of all levels.
Let us consider the below example tree.

         1
        /  \
       2    3
     /  \     \
    4    5     8 
              /  \
             6    7
For the above tree,
width of level 1 is 1,
width of level 2 is 2,
width of level 3 is 3
width of level 4 is 2.
So the maximum width of the tree is 3.*/
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
long height(node *node){
    if(node==NULL){
        return 0;
    }
    return 1 + max(height(node->left),height(node->right));
}
//storing total nodes in each level in count array
long levelwidth(node *root,long *count ,long level){
    if(root){
        count[level]++;
        levelwidth(root->left,count,level+1);
        levelwidth(root->right,count,level+1);
    }
}
int getMaxWidth(node* root)
{
   long  level = 0, h;
   h = height(root);
   long  *count = new long[h];
   //initialize count array 0 i.e. zero node in each level
   for(long i = 0;i<h;i++){
       count[i]=0;
   }
   levelwidth(root,count,level);
   int max = count[0];
   for(long i=0;i<h;i++){
       if(count[i]>max)
        max = count[i];
   }
   return max;
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
	int n,ans;
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
	ans = getMaxWidth(root);
	cout<<"\nMaximum Width of Tree is :- "<<ans;
	return 0;
}
