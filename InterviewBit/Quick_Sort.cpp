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
	quicksort(a,0,n-1);
	cout<<"Sorted array is :- ";
	printarray(a,n);
	return 0;
}
