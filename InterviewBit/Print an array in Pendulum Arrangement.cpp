#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int pendulum_arrangement(int *a,int *b,int n){
    int i=1,k=0,j=(n-1)/2;
    if(n%2!=0){
        a[j]=b[k];
        k++;
        while((j+i)<n){
           a[j+i]=b[k];
           a[j-i]=b[++k];
           i++;
           k++;
        }
    }
    else{
        a[j]=b[k];
        k++;
        while(j+i<=n-1){
            a[j+i]=b[k];
            a[j-i]=b[++k];
            i++;
            k++;
        }
        a[j+i]=b[k];
    }
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
	        b[j]=a[j];
	    }
	    sort(a,a+n);
	    sort(b,b+n);
	    pendulum_arrangement(a,b,n);
	    cout<<"Pendulum_arranged array as follow :- ";
        printarray(a,n);
        cout<<endl;
	}
	return 0;
}
