/*Given a binary number, write a program that prints 1 if given binary number is a multiple of 3.  
Else prints 0. The given number can be big upto 2^100. It is recommended to finish the task using one traversal of input binary string.
Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string containing 0's and 1's.
Output:
For each test case, output a 1 if string is multiple of 3, else 0.
Example:
Input:
2
011
100

Output:
1
0*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cout<<"Enter the test case :- ";
	cin>>t;
	while(t--){
	    string input;
	    cout<<"Enter the binary no. <=100 :- ";
	    cin>>input;
	    int size = input.size();
	    reverse(input.begin(),input.end());
	    int odd_count = 0,even_count = 0;
	    for(int i=0;i<size;i++){
	        if(input[i]=='1')
	            odd_count++;
	       i++;
	       if(i>=size)
	            break;
	       if(input[i]=='1')
	            even_count++;
	    }
	    if(abs(even_count-odd_count)%3==0)
	        cout<<"Yes";
	   else
	        cout<<"No";
	   cout<<endl;
	}
	return 0;
}
