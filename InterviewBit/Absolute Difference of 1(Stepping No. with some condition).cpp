#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*Given an array A of size N. Print all the numbers less than K in the array.
The numbers should be such that the difference between every adjacent digit should be 1.
Note: Print '-1' if no number if valid.*/
int swap(unsigned long int *a,unsigned long int *b){
    int temp;
    temp = *a;
    *a =*b;
    *b=temp;
    return 0;
}
int small(unsigned long int *a,unsigned int k,unsigned long int n){
    int i=-1,j=0;
    for(i,j;j<n;j++){
        if(a[j]<k){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    return i;
}
bool stepping_no(unsigned long int n){
    int prevdigit = -1;
   /* if(n<10){
        return false;
    }*/
    while(n){
        int curdigit = n%10;
        if(prevdigit==-1){
            prevdigit = curdigit;
        }
        else{
            if(abs(prevdigit-curdigit)!=1){
                return false;
            }
        }
        prevdigit=curdigit;
        n /= 10;
    }
    return true;
}
int print_stepping_no(unsigned long int *a,unsigned long int n){
    bool success = false;
    if(n==-1){
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<=n;i++){
        if(stepping_no(a[i])){
            cout<<a[i]<<" ";
            success = true;
        }
    }
    if(success== false){
        cout<<"-1";
    }
}
int main() {
	//code
	int t;
	unsigned long int n,k,end;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of array and no. to compare :- ";
	    cin>>n>>k;
	    unsigned long int a[n];
	    cout<<"Enter the element of the array as follows :- ";
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    end = small(a,k,n);
	    cout<<"The stepping no. less than given no. "<<k<<" as follows:- ";
	    print_stepping_no(a,end);
	    cout<<endl;
	}
	return 0;
}
