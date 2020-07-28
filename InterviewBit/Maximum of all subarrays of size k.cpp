#include <iostream>
using namespace std;
/*Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90*/
int temp[2];
int maximum(int *a,int i,int n){
    temp[0]=a[i];
    temp[1]=i;
    for(i;i<n;i++){
        if(temp[0]<a[i]){
            temp[0]=a[i];
            temp[1]=i;
        }
    }
}
int maximum_in_subarray(int *a,int k,int n){
    
    maximum(a,0,k);
    for(int i=0,j=k-1;j<n;j++,i++){
        if(temp[1]>i){
            if(temp[0]<a[j]){
                temp[0]=a[j];
                temp[1]=j;
            }
            cout<<temp[0]<<" ";
        }
        else{
            maximum(a,i,j+1);
            cout<<temp[0]<<" ";
        }
    }
}
int main() {
	//code
	int t,n,k;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of array and subgroup size :- ";
	    cin>>n>>k;
	    int a[n];
	    cout<<"Enter the element of the array as follows :- ";
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	cout<<"Maximum vlue in "<<k<<"Subarray as follows :- ";
	maximum_in_subarray(a,k,n);
	cout<<endl;
	}	
	return 0;
}
