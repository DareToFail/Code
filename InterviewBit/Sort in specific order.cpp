#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int sort_specific_order(int *a,int *b,int n){
    int j=0,k=n-1;
    for(int i=0;i<n;i++){
        if(a[i]%2!=0){
            b[j]=a[i];
            j++;
        }
        else{
            b[k]=a[i];
            k--;
        }
    }
    sort(b,b+j,greater<int>());
    sort(b+j,b+n);
}
int printarray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
int main() {
	//code
	int t,n;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of array :- ";
	    cin>>n;
	    int a[n],b[n];
	    cout<<"Enter the element of the array as follows :- ";
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	sort_specific_order(a,b,n);
	cout<<"Specific Order Sorted Array as follows :- ";
	printarray(b,n);
	cout<<endl;
	}
	return 0;
}
