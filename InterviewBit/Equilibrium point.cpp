#include <iostream>
using namespace std;
/*Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array.
Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it*/
int summation(int *a,int i,int n){
    int sum =0;
    for(i;i<n;i++){
        sum = sum + a[i];
    }
    return sum;
}
int equilibrium_point(int *a,int n){
    int sum , temp1,temp2;
    if(n==1){
        return 1;
    }
    else{
        sum = summation(a,0,n);
        temp1 = a[0];
        temp2 = sum - temp1 - a[1];
        if(temp1==temp2){
            return 2;
        }
        for(int j=2;j<n-1;j++){
            temp1 = temp1+a[j-1];
            temp2 = sum - temp1 - a[j];
            if(temp1==temp2){
                return j+1;
            }
        }
    }
    return -1;
}
int main() {
	//code
	int t,n,print;
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
	print = equilibrium_point(a,n);
	cout<<"Equilibrium point is :- "<<print;
	cout<<endl;
	}
	return 0;
}
