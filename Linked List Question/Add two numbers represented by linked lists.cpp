/*Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.
The sum list which is a linked list representation of addition of two input numbers.
Input: List1: 5->6->3  // represents number 365
       List2: 8->4->2 //  represents number 248
Output: Resultant list: 3->1->6  // represents number 613


Input: List1: 7->5->9->4->6  // represents number 64957
       List2: 8->4 //  represents number 48
Output: Resultant list: 5->0->0->5->6  // represents number 65005*/
#include<iostream>
#include<bits/stdc++.h>
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
void print_single_linked_list(node *root){
	node *temp = root;
	vector<int> num;
	if(temp!=NULL){
		cout<<temp->data;
		num.push_back(temp->data);
		temp = temp->next;
	}
	int i=1;
	while(temp!=NULL){
		cout<<"->"<<temp->data;
		num.push_back(temp->data);
		temp = temp->next;
		i++;
	}
	reverse(num.begin(),num.end());
	cout<<"\nThe corresponding value is :- ";
	for(int i = 0;i<num.size();i++){
		cout<<num[i];
	}
}

//adding two list no.
node* addTwoLists(node* first, node* second) {
    // Code here
    node *res = NULL;
    node *prev = NULL , *temp = NULL;
    int carry = 0,sum;
    while(first!=NULL || second!=NULL){
        sum = carry + (first ? first->data:0)+(second ? second->data:0);
        carry = sum/10;
        sum = sum%10;
        temp = newnode(sum);
        if(res==NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if(first)
            first = first->next;
        if(second)
            second = second->next;
    }
    if (carry > 0)  
    temp->next = newnode(carry);
    return res;
}
int main(){
	int n,m;
	cout<<"Enter the size of an array i.e. no. of element in the linked list 1 :- ";
	cin>>n;
	int a[n];
	cout<<"Enter their value :- ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	struct node *list1 = insertnewnode(a,list1,0,n);
	cout<<"\nElement entered in single linked list 1 :- ";
	print_single_linked_list(list1);
	
	
	//creating second single linked lsit
	cout<<"\n\nEnter the size of an array i.e. no. of element in the linked list 2:- ";
	cin>>m;
	int b[m];
	cout<<"Enter their value :- ";
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	struct node *list2 = insertnewnode(b,list2,0,m);
	cout<<"\nElement entered in single linked list 2 :- ";
	print_single_linked_list(list2);
	
	//Adding two linked list no.
	struct node *result = addTwoLists(list1,list2);
	cout<<"\n\nResultant list after sum :- ";
	print_single_linked_list(result);
	return 0;
}
