//https://www.geeksforgeeks.org/adding-one-to-number-represented-as-array-of-digits -- question link
/*Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is first element of array.
Example:

If the vector has [0,1, 2, 3]

the returned vector should be [1, 2, 4]

as 0123 + 1 = 0124...but given msb should not be zero*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    int carry =0,sum;
    sum = A[n-1]+1;
    A[n-1] = sum%10;
    carry  = sum/10;
    for(int i=n-2;i>=0;i--){
        if(carry==1){
            sum = A[i]+carry;
            A[i] = sum%10;
            carry = sum/10;
        }
        else
            break;
    }
    if(carry!=0){
        A.insert(A.begin(),1);
    }
    vector<int>::iterator position;
    position = A.begin();
    while(A[0]==0){
        A.erase(position);
    }
    return A;
}
// driver code 
int main() 
{ 
    int n,x;
    vector<int> A;//={1, 7, 8, 9};
    cout<<"Enter the size of element:- ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        A.push_back(x);
    }
    plusOne(A); 
  
    for (int i=0; i<A.size(); i++) 
       cout << A[i] << " "; 
  
    return 0; 
}
