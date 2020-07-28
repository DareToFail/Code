/*Write an Efficient Method to Check if a Number is Multiple of 3 similar algo for 11*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ismultipleof_3(int n){
	int even_count=0,odd_count=0;
	if(n==0){
		return 1;
	}
	if(n==1){
		return 0;
	}
	while(n){
		/* If odd bit is set then 
        increment odd counter */
        if (n & 1) 	//bitwise and
            odd_count++; 
  
        /* If even bit is set then 
        increment even counter */
        if (n & 2) //bitwise and
            even_count++; 
        n = n >> 2;	//right shift by 2 bits
	}
	return ismultipleof_3(abs(even_count-odd_count));
}
int main(){
	int n,success;
	cout<<"Enter the number :- ";
	cin>>n;
	success = ismultipleof_3(n);
	if(success){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}
