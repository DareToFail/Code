/*Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer 
that satisfy the given input string.D or d means the next number is smaller, while I or i means the next number is greater.
Notes
Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example : Input 1: n = 3
s = ID
Return: [1, 3, 2]
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> findPerm(const string A, int B) {
    vector<int> output;
    int max = B;
    int min =1;
    for(int i=B-2;i>=0;i--){
        if(A[i]=='I'|| A[i]=='i'){
            output.push_back(max);
            max--;
        }
        else{
            output.push_back(min);
            min++;
        }
    }
    output.push_back(min);
    reverse(output.begin(),output.end());
    return output;
}
int main() {
    string a;
    int n;
    vector<int> ans;
	cout<<"Enter any number < 10 :- ";
	cin>>n;
	cout<<"Enter string as I or D whose size should be "<<n-1<<":- ";
	cin>>a;
	ans = findPerm(a,n);
	cout<<"The required permutation is as :- ";
	cout<<"[ ";
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<" ]";
	return 0;
}
