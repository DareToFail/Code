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
#include<bits/stdc++.h>
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
//Level Order Method
void levelorder(struct node *root,vector<int> &level,vector<int> &hd){
	queue<node *> q;
	queue<int> h;
	if(root==NULL)
		return;
	q.push(root);
	h.push(0);
	while(q.empty()==false){
		level.push_back(q.front()->data);
		hd.push_back(h.front());
		if(q.front()->left!=NULL){
			q.push(q.front()->left);
			h.push(h.front()-1);
		}
		if(q.front()->right!=NULL){
			q.push(q.front()->right);
			h.push(h.front()+1);
		}
		q.pop();
		h.pop();
	}
}
void printlevelorder(vector<int> &level){
	int n = level.size();
	for(int i=0;i<n;i++){
		cout<<level[i]<<" ";
	}
}
//vertical order using level order 
void verticalorder(vector<int> &hd,vector<pair<int,int>> &vertical){
	int n = hd.size();
	for(int i=0;i<n;i++){
		vertical.push_back(make_pair(hd[i],i));
	}
}
void printverticalorder(vector<pair<int,int>> &vertical,vector<int> &level,vector<int> &hd){
	int n = level.size();
	int d = INT_MAX;
	//cout<<"Value at horizantal distance ";
	for(int i=0;i<n;i++){
		if(d!=vertical[i].first){
			cout<<"\nValue at horizantal distance ";
			d = vertical[i].first;
			cout<<d<<":- ";
		}
		cout<<level[vertical[i].second]<<" ";
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
	vector<int> level;
	vector<int> hd;
	levelorder(root,level,hd);
	cout<<"\nBinary Tree in Level Order :- "<<endl;
	printlevelorder(level);
	//for vertical order
	vector<pair<int,int>> vertical;
	verticalorder(hd,vertical);
	sort(vertical.begin(),vertical.end());
	cout<<"\nBinary Tree in Vertical Order using Level order :- ";
	printverticalorder(vertical,level,hd);
	return 0;
}
