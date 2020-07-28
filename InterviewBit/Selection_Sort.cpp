#include <iostream>
using namespace std;
int swap(int *a,int *b){
    int temp;
    temp = *a;
    *a =*b;
    *b=temp;
    return 0;
}
int selectionsort(int *a,int n){
    int min_index;
    for(int i=0;i<n-1;i++){
        min_index = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_index])
                min_index = j;
        }
    swap(&a[i],&a[min_index]);
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
	selectionsort(a,n);
	cout<<"Sorted array is :- ";
	printarray(a,n);
	return 0;
}
