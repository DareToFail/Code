#include <iostream>
using namespace std;
int swap(int *a,int *b){
    int temp;
    temp = *a;
    *a =*b;
    *b=temp;
    return 0;
}
int partition(int *a,int start,int end){
    int i,j,pivot;
    pivot = a[end];
    j=start-1;
    for(i=start;i<end;i++){
        if(a[i]<=pivot){
            j++;
            swap(&a[j],&a[i]);
        }
    }
    swap(&a[j+1],&a[end]);
    return j+1;
}
int quicksort(int *a,int start,int end){
    int divide;
    if(start<end){
        divide = partition(a,start,end);
        quicksort(a,start,divide-1);
        quicksort(a,divide+1,end);
    }
    return 0;
}
bool checksum(int *a,int n,int x){
    quicksort(a,0,n-1);
    int l=0,r=n-1;
    for(;l<r;){
        if(a[l]+a[r]==x){
            return 1;
        }
        if(a[l]+a[r]<x){
            l++;
        }
        else
            r--;
    }
    return 0;
}
int main() {
	//code
	int t,n,x,success;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of array and the sum value :- ";
	    cin>>n>>x;
	    cout<<"Enter the element of the array as follows :- ";
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    success=checksum(a,n,x);
	    if(success==1)
	        cout<<"Yes pair exit whose sum is "<<x<<endl;
	    else
	        cout<<"No pair doesn't exit whose sum is "<<x<<endl;
	  	}
	return 0;
}
