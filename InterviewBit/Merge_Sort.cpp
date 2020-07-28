#include <iostream>
using namespace std;
int merge(int *a,int start,int mid,int end){
    int n1,n2;
    n1 = mid - start + 1;
    n2 = end - mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=a[start+i];
    }
    for(int j=0;j<n2;j++){
        r[j]=a[mid+1+j];
    }
    int i=0,j=0,k=start;
    for(;i<n1 && j<n2;k++){
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }
        else{
            a[k]=r[j];
            j++;
        }
    }
    while(i<n1){
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=r[j];
        j++;
        k++;
    }
    return 0;
}
int mergesort(int *a,int start,int end){
    int mid;
    if(start<end){
        mid = start+(end-start)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
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
	mergesort(a,0,n-1);
	cout<<"Sorted array is :- ";
	printarray(a,n);
	return 0;
}
