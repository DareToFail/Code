/*Given a list of non negative integers, arrange them such that they form the largest number.
For example:
Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Given [ 0 0 0 0 ] , the largest formed is 0 not 0000.
Note: The result may be very large, so you need to return a string instead of an integer.*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int com(string a,string b){
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba) > 0 ? 1:0;
}
string largestNumber(const vector<int> &A) {
    vector<string> b;
    string sol="0";
    int n=A.size(),sum;
    sum = accumulate(A.begin(),A.end(),0);
    if(sum==0){
        return sol;
    }
    for(int i=0;i<n;i++){
    	string temp = to_string(A[i]);//converting int to string
        b.push_back(temp);
    }
    sol.erase();
    sort(b.begin(),b.end(),com);
    for(int i=0;i<n;i++){
        sol = sol.append(b[i]);
    }
    return sol;
}
int main() {
	vector<int> a;
	string result;
	int n,x;
	cout<<"Enter the size of an array :- ";
	cin>>n;
	cout<<"Enter the value in the array :- ";
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	result = largestNumber(a);
	cout<<"The largest no. from the given no. is :- "<<result;
	return 0;
}
