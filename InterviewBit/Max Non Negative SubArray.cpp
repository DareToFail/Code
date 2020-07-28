/*Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.
The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
Maximum sub-array is defined in terms of the sum of the elements in the sub-array.Find and return the required subarray.
NOTE:- 1. If there is a tie, then compare with segment's length and return segment which has maximum length.
       2. If there is still a tie, then return the segment with minimum starting index.
Input 1: A = [1, 2, 5, -7, 2, 3]
Output 1: [1, 2, 5]
Explanation 1: The two sub-arrays are [1, 2, 5] [2, 3].
               The answer is [1, 2, 5] as its sum is larger than [2, 3].*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>maxset(vector<int> &A) {
    long long int n = A.size();
    long long int curr_max = 0 , final_max = -1;
    long long int curr_start =0,curr_end =0,final_start=0,final_end=0;
    for(int i=0;i<n;i++){
        if(A[i]<0){
            curr_max = 0;
            curr_start=i+1;
        }
        else{
            if(curr_max+(long long int)A[i]>(long long int)A[i]){
                curr_max += (long long int)A[i];
                curr_end = i;
            }
            else if(curr_max+(long long int)A[i]==(long long int)A[i]){
                curr_end = i;
                curr_max += (long long int)A[i];
            }
            else{
                curr_max = (long long int)A[i];
                curr_start =i;
                curr_end =i;
            }
        }
        if(curr_max>final_max){
            final_max = curr_max;
            final_start = curr_start;
            final_end =curr_end;
        }
        if(curr_max==final_max){
            int len1 ,len2;
            len1 =curr_end -curr_start+1;
            len2 =final_end -final_start+1;
            if(len1>len2){
                final_start = curr_start;
                final_end =curr_end;
            }
        }
    }
    vector<int> sol;
    if(final_max==-1 && A[0]<0 && final_end == 0)
        return sol;
    while(final_start<=final_end){
        sol.push_back(A[final_start]);
        final_start++;
    }
    return sol;
}
int main() {
	int n,x;
	cout<<"Enter the size of array :- ";
	cin>>n;
	vector<int> A,result;
	cout<<"Enter the element in the array :- ";
	for(int i=0;i<n;i++){
	    cin>>x;
	    A.push_back(x);
	}
	result =maxset(A);
	if(result.empty()){
	    cout<<"Given array contains all negative number :";
	    return 0;
	}
	cout<<"The maximum sum sub-array of non negative numbers from given array is :- ";
	for(int i=0;i<result.size();i++){
	    cout<<result[i]<<" ";
	}
	return 0;
}
