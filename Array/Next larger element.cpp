#include <bits/stdc++.h>
using namespace std;
void next_larger_element(int a[],int result[],int n){
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(s.empty()==false){
            if(a[s.top()]<a[i]){
                result[s.top()] = a[i];
                s.pop();
            }
            else{
            	break;
            }
        }
        s.push(i); 
        
    }
}
int main() {
	//code
	int t,n;
	cout<<"Enter the test cases :- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of an array :- ";
	    cin>>n;
	    int a[n],result[n];
	    cout<<"Enter the element of an array :- ";
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	        result[j] =-1;
	    }
	    next_larger_element(a,result,n);
	    for(int j=0;j<n;j++){
	        cout<<result[j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
