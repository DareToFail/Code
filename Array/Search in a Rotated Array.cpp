/*Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K.
The task is to find the index of the given element K in the array A.
Input:
The first line of the input contains an integer T, denoting the total number of test cases.
Then T test cases follow. Each test case consists of three lines. First line of each test case contains 
an integer N denoting the size of the given array. Second line of each test case contains N space separated 
integers denoting the elements of the array A. Third line of each test case contains an integer K denoting the element to be searched in the array.
Output:
Corresponding to each test case, output the index of the element found in the array.If element is not present, then output -1.
Example:
Input:
3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6
Output:
5
1
-1
Explanation:
Testcase 1: 10 is found at index 5*/
#include <iostream>
using namespace std;
// Returns index of key in arr[l..h] if  
// key is present, otherwise returns -1 
int search(int a[],int l,int h,int k){
    
	if(l>h)
        return -1;
    int mid = (l+h)/2;
    if(a[mid]==k)
        return mid;
     /* If arr[l...mid] is sorted */    
    if(a[l]<=a[mid]){
    	/* As this subarray is sorted, we can quickly 
        check if key lies in half or other half */
        if(a[l]<=k && a[mid]>=k)
            return search(a,l,mid-1,k);
        /*If key not lies in first half subarray,  
           Divide other half  into two subarrays, 
           such that we can quickly check if key lies  
           in other half */
        return search(a,mid+1,h,k);
    }
    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h] 
    must be sorted subarray */
    if(a[mid]<=k && a[h]>=k)
        return search(a,mid+1,h,k);
    return search(a,l,mid-1,k);
}
int main() {
	//code
	int t;
	cout<<"Enter no. of test cases :- ";
	cin>>t;
	while(t--){
	    int n;
	    cout<<"Enter the size of an array:- ";
	    cin>>n;
	    cout<<"Enter the element of an array:- ";
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int k;
	    cout<<"Enter the value to be seached :- "
	    cin>>k;
	    cout<<search(a,0,n-1,k)<<endl;
	}
	return 0;
}
