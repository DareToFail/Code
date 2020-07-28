/*Given a string str containing alphanumeric characters, calculate sum of all numbers present in the string.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains a string containing alphanumeric characters.
Output:
Print the sum of all numbers present in the string.
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc

Output:
24
4
100
123*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cout<<"Enter the no. of test cases:- ";
	cin>>t;
	while(t--){
	    string s,tem="0";
	    cout<<"Enter the string containg some number :- ";
	    cin>>s;
	    int sum =0,more=0;
	    for(int i=0;;){
	        while(s[i]!='\0'){
	            if(isdigit(s[i])){
	                tem += s[i];
	                more =1;
	            }
	            else{
	                sum += stoi(tem);
	                tem = "0";
	                more = 0;
	            }
	            i++;
	        }
	        break;
	    }
	    if(more==1){
	        sum += stoi(tem);
	    }
	    cout<<"Sum of number in string is :- "<<sum<<endl;
	}
	return 0;
}
