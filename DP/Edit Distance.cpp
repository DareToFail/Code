/*Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1' into ‘str2'.
Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.
Example:
Input:
1
4 5
geek gesek

Output:
1*/
#include<bits/stdc++.h>
using namespace std;
int editdistance(string str1 ,string str2 ,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1+min(min(dp[i-1][j],//Remove
                                     dp[i][j-1] //Insert
                                    ),dp[i-1][j-1]//Replace
                                );
        }
    }
    return dp[m][n];
}
int main() {
	//code
	int t,p,q;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of string1 and string2 :- ";
	    cin>>p>>q;
	    cout<<"Enter the two string separated by space of same case(i.e.both in capital or lower) :- ";
	    string str1,str2;
	    cin>>str1;
	    cin>>str2;
	    cout<<"the minimum number of operations required to make both string same is :- "<<editdistance(str1,str2,p,q);
	    cout<<endl;
	}
	return 0;
}
