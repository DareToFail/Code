#include <iostream>
using namespace std;
int insertionsort(int *a,int n){
    int i,j,key;
    for(i=0;i<n;i++){
        key = a[i];
        j=i-1;
        for(;j>=0 && a[j]>key;j--){
            a[j+1] = a[j];
        }
    a[j+1]=key;
    }
    return 0;
}
int printarray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
int main() {
    int n;
	cout<<"Enter the no of the element in the array:-";
	cin>>n;
	int a[n];
	cout<<"Enter the element of an array:- ";
	for(int i=0;i<n;i++)
	    cin>>a[i];
	cout<<"Unsorted array is :- ";
	printarray(a,n);
	cout<<endl;
	insertionsort(a,n);
	cout<<"Sorted array is :- ";
	printarray(a,n);
	return 0;
}
