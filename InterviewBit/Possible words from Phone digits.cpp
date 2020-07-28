#include <iostream>
using namespace std;
/*https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/0/?track=sp-arrays-and-searching&batchId=105*/
char temp[8];
char b[8][4]={{'a','b','c','0'},{'d','e','f','0'},{'g','h','i','0'},{'j','k','l','0'},{'m','n','o','0'},{'p','q','r','s'},{'t','u','v','0'},{'w','x','y','z'}};
int recur(int *a,int n,int s,int z){
    int base;
    if(n>0){
        base =a[n-1];
        if(base==7 || base==9){
            for(int j=base-2,k=0;k<4;k++){
            temp[s]= b[j][k];
            s++;
            recur(a,n-1,s,z);
            s--;
            }            
        }
        else{
            for(int j=base-2,k=0;k<3;k++){
            temp[s] = b[j][k];
            s++;
            recur(a,n-1,s,z);
            s--;
            }
        }
    }
    else{
        for(int p=0;p<z;p++){
            cout<<temp[p];
        }
        cout<<" ";
        return 0;
    }
}
int main() {
	//code
	int t,n,z;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the no.:- ";
	    cin>>n;
	    int d[n];
	    cout<<"Enter the digit no. :- ";
	    for(int j=n-1;j>=0;j--){
	        cin>>d[j];
	    }
	    z=n;
	    cout<<"all possible words from phone digits with single space :- "<<endl;
	    recur(d,n,0,z);
	    cout<<endl;
	}	
	return 0;
}
