/*Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.
Input Format: The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Constraints:
1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:
Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ] */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int> > &A) {
    int rowflag=1,colflag=1; // variable to check if there is zero in first row and column.
    int row = A.size();
    int col = A[0].size();
    //making rowflag zero if first row contains atleast one zero.
    for(int i=0;i<col;i++){
        if(A[0][i]==0){
            rowflag = 0;
            break;
        }
    }
     //making colflag zero if first column contains atleast one zero.
    for(int i=0;i<row;i++){
        if(A[i][0]==0){
            colflag=0;
            break;
        }
    }
    //updating 1st row and column if zero is countered
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(A[i][j]==0){
                A[0][j]=0;
                A[i][0]=0;
            }
        }
    }
    //modifying matrix based on first row and column value.
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(A[0][j]==0 || A[i][0]==0)
                A[i][j]=0;
        }
    }
    //modifying row and column if flag was zero
    if(!rowflag){
        for(int i=0;i<col;i++)
            A[0][i]=0;
    }
    if(!colflag){
        for(int i=0;i<row;i++)
            A[i][0]=0;
    }
    
}
int main() {
	int m,n;
	cout<<"Enter the the row and column size of a matrix :- ";
	cin>>m>>n;
	vector<vector<int> > a(m);
	cout<<"Enter the value (0s or 1s) of matrix row-wise:- "<<endl;
	for(int i=0;i<m;i++){
		a[i] = vector<int>(n);
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	setZeroes(a);
	cout<<"Resultant matrix after applying setzeroes:-"<<endl;
	for(int i=0;i<m;i++){
		cout<<"[ ";
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<" ]"<<endl;
	}
	return 0;
}
