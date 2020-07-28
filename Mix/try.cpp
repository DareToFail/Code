#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
	int a[3] = {1,2,3};
	int k=2;
	//cin>>k;
	sort(a,a+3,greater<int>());
	int i =0;
	float temp;
	for(int j=0;j<k;j++){
	    if(a[i]<a[i+1]){
	     temp = a[i+1];
	     i++;
	    }
	    else
	    temp = a[i];
	    
	    cout<<temp<<endl;
	    temp = ceil(temp/2);
	    cout<<temp<<endl;
	    a[i] = temp;
	}
	int sum =0;
	cout<<endl;
	for(int i=0;i<3;i++){
	    sum = sum + a[i];
	}
	cout<<sum;
}
