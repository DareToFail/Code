/*Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
Input:
The first line of input contains an integer T denoting the number of test cases.
The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

Explanation:
Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cout<<"Enter the no. of test case :- ";
	cin>>t;
	while(t--){
	    int n;
	    cout<<"Enter the size of an array :- ";
	    cin>>n;
	    cout<<"Enter the element of an array :- ";
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int curr_max =a[0],final_max = a[0];
	    for(int i=1;i<n;i++){
	        curr_max = max(curr_max+a[i],a[i]);
	        final_max = max(final_max,curr_max);
	    }
	    cout<<"The maximum value :- "<<final_max<<endl;
	}
	return 0;
}
