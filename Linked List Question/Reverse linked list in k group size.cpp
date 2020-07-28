#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
//
struct node *newnode(int value){
	struct node *p = new struct node;
	p->data = value;
	p->next = NULL;
	return p;
}
//inserting new node and calling the newnode function to insert its value
struct node *insertnewnode(int a[],struct node *root,int i,int n){
	if(i<n){
		struct node *temp = newnode(a[i]);
		root = temp;
		root->next = insertnewnode(a,root->next,i+1,n);
	}
	return root;
}


//getting last element address in linked list
struct node *last_element(node *root){
	node *last = root;
	while(last->next!=NULL){
		last = last->next;
	}
	return last;
}


//creating loop in linked list
void loop(node *list1,node *list2){
	node *list1_last = last_element(list1);
	node *list2_last = last_element(list2);
	list1_last->next = list2;
	list2_last->next = list2;
}

//printing list
void print_single_linked_list(node *root,int end){
	node *temp = root;
	if(temp!=NULL){
		cout<<temp->data;
		temp = temp->next;
	}
	int i=1;
	while(temp!=NULL && i<end){
		cout<<"->"<<temp->data;
		temp = temp->next;
		i++;
	}
}

//remove loop
void removeloop(node *head)
{
    if (head == NULL || head->next == NULL) 
        return; 
  
    node *slow = head, *fast = head; 
  
    // Move slow and fast 1 and 2 steps 
    // ahead respectively. 
    slow = slow->next; 
    fast = fast->next->next; 
  
    // Search for loop using slow and 
    // fast pointers 
    while (fast && fast->next) { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
    /* If loop exists */
    if (slow == fast) { 
        slow = head; 
        while (slow->next != fast->next) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
        fast->next = NULL; 
    } 
}


//Reverse a sinlge linked list in a group of given size
struct node *reverse(node *head,int k){
	node *prev = NULL , *curr = head , *next = NULL;
	int count = 0;
	while(curr!=NULL && count<k){
		next =curr->next;
		curr->next = prev;
		prev = curr;
		curr =next;
		count++;
	}
	if(next!=NULL){
		head->next = reverse(next,k);
	}
	return prev;
}
int main(){
	int n,m;
	cout<<"Enter the size of an array i.e. no. of element in the linked list :- ";
	cin>>n;
	int a[n];
	cout<<"Enter their value :- ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	struct node *root = insertnewnode(a,root,0,n);
	cout<<"\nElement entered in single linked list :- ";
	print_single_linked_list(root,n);
	
	
	//creating loop in single linked lsit
	cout<<"\n\nEnter the size of an array i.e. no. of element in the linked list for creating loop:- ";
	cin>>m;
	int b[m];
	cout<<"Enter their value :- ";
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	struct node *list2 = insertnewnode(b,list2,0,m);
	struct node *list1 = root;
	node *temp = last_element(list1);
	loop(list1,list2);
	cout<<"\nElement in single linked list with loop:- ";
	print_single_linked_list(root,n+m);
	cout<<"->"<<temp->data<<"-> in loop..";
	
	//Detect and Remove Loop
	removeloop(root);
	cout<<"\n\nElement in single linked list after removing loop:- ";
	print_single_linked_list(root,n+m);
	
	
	
	//Reverse a sinlge linked list in a group of given size
	int k;
	cout<<"\n\nEnter the group size from which linked list to be reversed :- ";
	cin>>k;
	root = reverse(root,k);
	cout<<"\nSingle linked list after reversing in group of size "<<k<<" is :- ";
	print_single_linked_list(root,n+m);
	return 0;
}
