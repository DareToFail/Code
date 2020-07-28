#include <iostream>
#include<bits/stdc++.h>
/*Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.*/
using namespace std;
bool pythagorean_triplet(int *a,int n){
    for(int i=0;i<n;i++){
	        a[i] *= a[i];
	    }
	sort(a,a+n);
	for(int j=n-1;j>1;j--){
	    int right=j-1;
	    int left =0;
	    while(left<right){
	        if(a[left]+a[right]==a[j]){
	            return true;
	        }
	        (a[left] + a[right] < a[j]) ? left++ : right--; 
	    }

	}
    return false;
}
int main() {
	//code
	int t,n;
	bool result;
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
	result = pythagorean_triplet(a,n);
	cout<<"Follow Pythagorean Triplet ? :-";
    if(result==true){
        cout<<"Yes";
    }
    else
        cout<<"No";
	cout<<endl;
	}
	return 0;
}
