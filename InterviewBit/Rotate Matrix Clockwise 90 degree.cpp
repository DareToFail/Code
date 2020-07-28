#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void rotate_matrix(vector<vector<int> > &a){
    int n = a.size();
          // Swap elements of each cycle 
            // in clockwise direction
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-1-i;j++){
            int temp = a[i][j];
            a[i][j] = a[n-1-j][i];
            a[n-1-j][i] = a[n-1-i][n-1-j];
            a[n-1-i][n-1-j] = a[j][n-1-i];
            a[j][n-1-i] = temp;
        }
    }
}
int main() {
	int n;
	cout<<"Enter the size of square matrix :- ";
	cin>>n;
	vector<vector<int> > a(n);
	cout<<"Enter the element of the matrix :- "<<endl;
	for(int i=0;i<n;i++){
		a[i] = vector<int>(n);
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	rotate_matrix(a);
	cout<<"Matrix after rotating 90 degree clockwise :- "<<endl;
	for(int i=0;i<n;i++){
		cout<<"[ ";
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<" ]"<<endl;
	}
	return 0;
}
