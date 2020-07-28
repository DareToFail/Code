/*Given an array a[1..N]. For each element at position i (1 <= i <= N). Where
L(i) is defined as closest index j such that j < i and a[j] > a[i]. If no such j exists then L(i) = 0.
R(i) is defined as closest index k such that k > i and a[k] > a[i]. If no such k exists then R(i) = 0.
LRProduct(i) = L(i)*R(i) 
Return: Maximum special product of any integer in the array modulo 1000000007.
Input : 5 4 3 4 5
Output : 8
For {5, 4, 3, 4, 5}, L[] = {0, 0, 1, 0, 0} and R[] = {0, 4, 3, 4, 0},
LRProduct = {0, 0, 3, 0, 0} and max in this is 3
here index start consider from 0 we can use as 1 also but for that we need to modify our code*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int maxSpecialProduct(vector<int> &A) {
    stack<long long int> left,right;
    long long int n = A.size();
    vector<long long int> l(n,0),r(n,0);
    //calculating leftmost next greater
    for(long long int i=n-1;i>=0;i--){
        while(!left.empty() && A[i]>A[left.top()]){
            long long int temp = left.top();
            left.pop();
            l[temp] = i;
        }
        left.push(i);
    }
    //calculating rightmost next greater
    for(long long int i=0;i<n;i++){
        while(!right.empty() && A[i]>A[right.top()]){
            long long int temp = right.top();
            right.pop();
            r[temp]=i;
        }
        right.push(i);
    }
    long long int ans = -1;
    for(int i=0;i<n;i++){
        ans = max(ans,l[i]*r[i]);
    }
    return ans%1000000007;
    
}
int main() {
    int n,ans;
	cout<<"Enter the size of array :- ";
	cin>>n;
	vector<int> a(n);
	cout<<"Enter the element of the array :- ";
	for(int i=0;i<n;i++)
	    cin>>a[i];
	ans = maxSpecialProduct(a);
	cout<<"Required Ans :- "<<ans;
	return 0;
}
