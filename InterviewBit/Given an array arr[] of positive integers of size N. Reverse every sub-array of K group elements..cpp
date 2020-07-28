#include <iostream>
using namespace std;
int reverse(int *a,int start,int end){
    int temp;
    end = end-1;
    while(start<end){
    temp=a[start];
    a[start]=a[end];
    a[end]=temp;
    start++;
    end--;
    }
    return 0;
}
int rotate(int *a,int d,int n){
    int i;
    for(i=0;(i+d)<=n;){
        reverse(a,i,i+d);
        i=i+d;
    }
    if(d%n!=0){
        reverse(a,i,n);
    }
}
int printarray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
int main() {
	//code
	int t,n,k;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of array and the group value i.e. k :- ";
	    cin>>n>>k;
	    int a[n];
	    cout<<"Enter the element of the array as follows :- ";
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    rotate(a,k,n);
	    cout<<k<<"-Groupwise Reverse array is :- ";
	    printarray(a,n);
	    cout<<endl;
	}
	return 0;
}
