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
//Queue Implemantation using linked list
struct list{
	struct node *curr;
	struct list *next;
};
struct queue{
	struct list *front , *rear;
};
struct list *new_node(struct node *root){
	struct list *temp = new struct list;
	temp->curr = root;
	temp->next = NULL;
	return temp;
}
struct queue *createqueue(){
	struct queue *temp = new struct queue;
	temp->front = NULL;
	temp->rear =NULL;
	return temp;
}
void enqueue(struct node *root,struct queue *q){
	struct list *temp = new_node(root);
	if(q->rear==NULL){
		q->rear = q->front = temp;
	}
	else{
		q->rear->next = temp;
		q->rear = temp;
	}
}
struct node *dequeue(struct queue *q){
	if(q->front==NULL){
		return 0;
	}
	struct node *temp = q->front->curr;
	q->front = q->front->next;
	if(q->front==NULL){
		q->rear = NULL;
	}
	return temp;
}
void levelorder(struct node *root,struct queue *q){
	struct node *temp = root;
	while(temp){
		cout<<temp->data<<" ";
		if(temp->left)
			enqueue(temp->left,q);
		if(temp->right)
			enqueue(temp->right,q);
		temp = dequeue(q);
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
	cout<<"\nBinary Tree in Level Order :- "<<endl;
	struct queue *q = createqueue();
	levelorder(root,q);
	return 0;
}
