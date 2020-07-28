/*Given an index k, return the kth row of the Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?
Example:
Input : k = 3
Ans: [1,3,3,1]*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>getRow(int A) {
    int i,j;
    vector<int> ans;
    ans.push_back(1);
    if(A==0)
        return ans;
    ans.push_back(1);
    if(A==1)
        return ans;
    for(i=2;i<=A;i++)
    {
        vector<int> previous;
        for(j=0;j<ans.size();j++)
            previous.push_back(ans[j]);
        ans.clear();
        for(j=0;j<=i;j++)
        {
            if(j==0 || j==i)
                ans.push_back(1);
            else
                ans.push_back(previous[j-1]+previous[j]);
        }
    }
    return ans;
}
int main() {
    int n;
    string a;
	cout<<"Enter the row number for Pascal Triangle value to print :-";
	cin>>n;
	switch(n){
	    case 1: a="st";
	            break;
	    case 2: a = "nd";
	            break;
	    case 3: a = "rd";
	            break;
	    default: a = "th";
	}
	vector<int> pascal_row_value;
	pascal_row_value = getRow(n);
	cout<<n<<a<<" row value of pascal triangle is :- ";
	for(int i=0;i<pascal_row_value.size();i++)
	    cout<<pascal_row_value[i]<<" ";
	return 0;
}
