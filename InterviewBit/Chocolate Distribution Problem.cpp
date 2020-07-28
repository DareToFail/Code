#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*Given an array A of positive integers of size N, where each value represents number of chocolates in a packet.
Each packet can have variable number of chocolates.There are M students, the task is to distribute chocolate packets such that :
1. Each student gets one packet
2. The difference between the number of chocolates given to the students having packet with maximum chocolates and student 
having packet with minimum chocolates is minimum.*/
int chocolate_distribution(int *a,int m,int n){
    int min,j=m-1;
    sort(a,a+n);
    min = a[n-1]-a[0];
    for(int i=0;j<n;j++,i++){
        if(a[j]-a[i]<min){
            min = a[j]-a[i];
        }
    }
    return min;
}
int main() {
	//code
	int t,n,m,result;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of array :- ";
	    cin>>n;
	    int a[n];
	    cout<<"Enter the element of the array as follows :- ";
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    cout<<"Enter the no. of Student:- ";
	    cin>>m;
	    result = chocolate_distribution(a,m,n);
	    cout<<"Answer :- ";
	    cout<<result;
	    cout<<endl;
	}
	return 0;
}
