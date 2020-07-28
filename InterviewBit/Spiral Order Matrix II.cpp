/*Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.
Input Format: The first and the only argument contains an integer, A.
Output Format: Return a 2-d matrix of size A x A satisfying the spiral order.Examples
Input 1: n = 3
Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]
Input 2: n = 4
Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > generateMatrix(int A) {
    vector<vector<int> > b(A);
    for(int i=0;i<A;i++){
        b[i]=vector<int>(A);
    }
    int row_start=0,row_end = A,col_start =0,col_end=A,j=1;
    while(row_start<row_end && col_start<col_end){
        //printing the first row from remaining rows
        for(int i=col_start;i<col_end;i++){
            b[row_start][i] = j;
            j++;
        }
        row_start++;
        //printing the last column from remaining column
        for(int i = row_start;i<row_end;i++){
            b[i][col_end-1]= j;
            j++;
        }
        col_end--;
        //printing the last row from remaining row
        if(row_start<row_end){
            for(int i = col_end-1;i>=col_start;i--){
                b[row_end-1][i] = j;
                j++;
            }
            row_end--;
        }
        //printint the first column from remaining one
        if(col_start<col_end){
            for(int i =row_end-1;i>=row_start;i--){
                b[i][col_start]=j;
                j++;
            }
            col_start++;
        }
    }
    return b;
}
int main() {
	int n;
	vector<vector<int> > sol;
	cout<<"Enter the size of an array :- ";
	cin>>n;
	sol = generateMatrix(n);
	cout<<"Square matrix filled with natural no. 1 to "<<n*n<<" in a spiral order is :-"<<endl;
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        cout<<sol[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
