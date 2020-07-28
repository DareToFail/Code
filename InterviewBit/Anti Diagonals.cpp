/*Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
Example: Input: 	
1 2 3
4 5 6
7 8 9
Return the following :
[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >diagonal(vector<vector<int> > &A) {
    int n = A.size(),temp,k;
    vector<vector<int> > ret(n+n-1);
    for( k=0;k<n;k++){
        ret[k]=vector<int>(k+1);
        for(int i=0,j=k;i<=k;i++,j--){
             ret[k][i] = A[i][j];
        }
    }
    temp=k;
    for(int k=1;k<n;k++){
        ret[temp] = vector<int>(n-k);
        for(int i=k,j=n-1,c=0;i<n;i++,j--,c++){
            ret[temp][c]=A[i][j];
        }
        temp++;
    }
    ret[n+n-2]=vector<int>(1);
    ret[n+n-2][0]=A[n-1][n-1];
    return ret;
}
int main() {
	int n,x;
	cout<<"Enter the size of an square matrix:- ";
	cin>>n;
	vector<vector<int> > A(n),sol;
	cout<<"Enter the element in a square matrix :- "<<endl;
	for(int i=0;i<n;i++){
	    A[i]=vector<int>(n);
	    for(int j=0;j<n;j++){
	        cin>>x;
	        A[i][j]=x;
	    }
	}
	sol = diagonal(A);
	cout<<"Required anti diagnol value of given matrix:- "<<endl;
	for(int i=0;i<sol.size();i++){
	    for(int j=0;j<sol[i].size();j++){
	        cout<<sol[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
