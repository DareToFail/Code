#include <iostream>
using namespace std;
int swap(int *a,int *b){
    int temp;
    temp = *a;
    *a =*b;
    *b=temp;
    return 0;
}
int bubblesort(int *a,int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped=false;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)
            break;
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
	bubblesort(a,n);
	cout<<"Sorted array is :- ";
	printarray(a,n);
	return 0;
}
