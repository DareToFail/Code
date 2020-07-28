/*You are given a binary string S. In a single operation, you can choose two indices L and R such that 1 = L = R = N and
 complement the characters between L and R i.e SL, SL+1, …, SR. By complement, we mean change character 0 to 1 and vice-versa.
You task is to perform ATMOST one operation such that in final string number of 1s is maximised. If there is no need to completement, 
i.e., string contains all 1s, return -1.Else, return the two values denoting L and R. If there are multiple solutions, 
return the lexicographically smallest pair of L and R.
Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
question link -- https://practice.geeksforgeeks.org/problems/complement/0 */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>flip(string A) {
    int n = A.length();
    int curr_max=0,final_max=0,k=0,l=INT_MAX,r=INT_MAX;
    vector<int> b(n),ret;
    for(int i=0;i<n;i++){
        if(A[i]=='1')
            b[i]=-1;
        else
            b[i]=1;
    }
    //Applying Kadane algorithms i.e. maximum contigous zeros as ones can be included in counting of one
    for(int i=0;i<n;i++){
        if(curr_max+b[i]<0){
            k =i+1;
            curr_max=0;
        }
        else
            curr_max += b[i];
        if(curr_max>final_max){
            final_max = curr_max;
            l=k;
            r=i;
        }
    }
    if(l==INT_MAX)
        return ret;
    else{
        ret.push_back(l+1);
        ret.push_back(r+1);
    }
    return ret;
}
int main(){
	string A;
	vector<int> sol;
	cout<<"Enter a no. containig only ones and zeros:- ";
	cin>>A;
	sol = flip(A);
	if(sol.empty()){
		cout<<"-1";
		return 0;
	}
	for(int i=0;i<2;i++){
		cout<<sol[i]<<" ";
	}
	return 0;
}

