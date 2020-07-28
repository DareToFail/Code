/*Given a binary tree, print it vertically. The following example illustrates vertical order traversal.
           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9 
               
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9 
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
//method 1
//hd = horizantal distance
void min_max_hd(node *root,int *min,int *max,int hd){
	if(root==NULL)
		return;
	if(hd<*min)
		*min = hd;
	else if(hd>*max)
		*max = hd;
	min_max_hd(root->left,min,max,hd-1);
	min_max_hd(root->right,min,max,hd+1);
}
//vo = vertical order
void print_vo(node *root,int line_no,int hd){
	if(root==NULL)
		return;
	if(line_no==hd)
		cout<<root->data<<" ";
	print_vo(root->left,line_no,hd-1);
	print_vo(root->right,line_no,hd+1);
}
void vo(node *root){
	int min = 0,max =0;
	min_max_hd(root,&min,&max,0);
	for(int line_no=min;line_no<=max;line_no++){
		cout<<"Node at vertical line no. "<<line_no<<" are :- ";
		print_vo(root,line_no,0);
		cout<<endl;
	}
}
//method 2 using Double linked list
struct entry{
	int data;
	struct entry *next;
};
struct headnode{
	int hd;
	struct entry *list;
	struct headnode *left , *right;
};
struct entry *new_entry(int data){
	struct entry *temp = new struct entry; // creating a dynamic space of entry structure
	temp->data = data;
	temp->next = NULL;
	return temp;
}
struct headnode *new_headnode(int value){
	struct headnode *temp = new struct headnode;
	temp->hd = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->list = NULL;
	return temp;
}
//dll - double linked lsit
void build_dll(struct node *root,struct headnode *head,int hd){
	struct entry *e = new_entry(root->data);
	//e->next = head->list;
	//head->list = e;
	struct entry *temp = head->list;
	if(head->list==NULL)
		head->list = e;
	else{
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = e;
	}
	if(root->left){
		if(head->left==NULL){
			head->left = new_headnode(hd-1);
			head->left->right = head;
		}
		build_dll(root->left,head->left,hd-1);
	}
	if(root->right){
		if(head->right==NULL){
			head->right = new_headnode(hd+1);
			head->right->left = head;
		}
		build_dll(root->right,head->right,hd+1);
	}
}
void print(struct headnode *head){
	struct headnode *temp = head;
	int line = 0;
	while(temp->left!=NULL){
		temp = temp->left;
		line--;
	}
	while(temp!=NULL){
		struct entry *temp1 = temp->list;
		cout<<"Node at line no. "<<line<<" are :- ";
		while(temp1!=NULL){
			cout<<temp1->data<<" ";
			temp1 = temp1->next;
		}
		line++;
		cout<<endl;
		temp = temp->right;
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
	cout<<"\nBinary Tree in Vertical order in O(n^2) time complexity and O(n) space complexity :- "<<endl;
	vo(root);
	//method 2
	struct headnode *head = new_headnode(0);
	build_dll(root,head,0);
	cout<<"\nBinary Tree in Vertical order in O(n) time complexity and O(n) space complexity :- "<<endl;
	print(head);
	return 0;
}
