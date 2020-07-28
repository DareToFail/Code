/*. Write a function that takes an integer value n as input and prints first n lines of the Pascal’s triangle.
 Following are the first 6 rows of Pascal’s Triangle.
1  
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> >solve(int A) {
    int row = A;
    int column;
    vector<vector<int> > sol(row);
    for(int i=0;i<row;i++){
        column = i+1;
        sol[i] = vector<int>(column);
        for(int j=0;j<=i;j++){
            if(j==0||j==i)
                sol[i][j] = 1;
            else{
                sol[i][j] = sol[i-1][j-1]+sol[i-1][j];
            }
        }
    }
    return sol;
}
int main() {
    int n;
	cout<<"Enter the number for Pascal Triangle :-";
	cin>>n;
	vector<vector<int> >pascal;
	pascal = solve(n);
	for(int i=0;i<n;i++){
	    for(int j=0;j<=i;j++)
	        cout<<pascal[i][j]<<" ";
	   cout<<endl;
	}
	return 0;
}
