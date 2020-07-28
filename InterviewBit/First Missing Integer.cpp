/*Given an unsorted integer array, find the first missing positive integer in O(n) time and constant Space*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int> &A) {
    int n = A.size(),missing_no;
    int j=0;
    //putting all non positive no. left hand side and counting total such no.
    for(int i=0;i<n;i++){
        if(A[i]<=0){
            swap(A[i],A[j]);
            j++;
        }
    }
    int *p = &A[j];
    int size = n-j;
    for(int i=0;i<size;i++){
        if (abs(p[i]) - 1 < size && p[abs(p[i]) - 1] >0)
            p[abs(p[i]) - 1] = -p[abs(p[i]) - 1]; 
    }
    for(int i=0;i<size;i++){
        if(p[i]>0){
            missing_no = i+1;
            return missing_no;
        }
    }
    missing_no = size+1;
    return missing_no;
}
int main() {
    int ans,n,x;
    vector<int> A;
    cout<<"Enter the size of an array :- ";
    cin>>n;
    cout<<"Enter the element of an array :- ";
    for(int i=0;i<n;i++){
        cin>>x;
        A.push_back(x);
    }
	ans = firstMissingPositive(A);
	cout<<"The first missing positive value in a given array is :- "<<ans;
	return 0;
}
