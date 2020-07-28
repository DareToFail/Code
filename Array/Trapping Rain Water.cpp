/*Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1.
Compute how much water can be trapped in between blocks after raining.
Structure is like below:
|  |
|_|
We can trap 2 units of water in the middle gap.
Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_| 
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.
see link for clearity of question --- https://www.geeksforgeeks.org/trapping-rain-water/
*/
#include <iostream>
using namespace std;
int savewater(int a[],int n){
    int res = 0;
    int left = 0,right=0;
    int low=0,high=n-1;
    while(low<=high){
        if(a[low]<a[high]){
            if(a[low]>left)
                left = a[low];
            else{
                res += left - a[low];
                low++;
            }
        }
        else{
            if(a[high]>right)
                right = a[high];
            else{
                res += right - a[high];
                high--;
            }
        }
    }
    return res;
}
int main() {
	//code
	int t,n;
	cout<<"enter the no of test cases:- ";
	cin>>t;
	while(t--){
		cout<<"Enter the size of an array :- ";
	    cin>>n;
	    cout<<"Enter the element of an array :- ";
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cout<<"We can save amount of rain water is :- ";
	    cout<<savewater(a,n)<<endl;
	}
	return 0;
}
