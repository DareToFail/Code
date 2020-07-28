/*Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Make sure the returned intervals are also sorted.*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct interval{
    int start;
    int end;
};
bool com(interval a,interval b){
    return a.start<b.start;
}
vector<interval> solution(vector<interval> &a,interval newinterval){
    a.push_back(newinterval);
    sort(a.begin(),a.end(),com);
    vector<interval> result;
    int n = a.size();
    result.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(result[result.size()-1].end>=a[i].start){
            result[result.size()-1].end = max(result[result.size()-1].end,a[i].end);
        }
        else
        result.push_back(a[i]);
    }
    return result;
}
int main() {
	vector<interval> a,result;
	struct interval temp,newinterval;
	int n;
	cout<<"Enter the size of an array:- ";
	cin>>n;
	cout<<"Enter the start and end value i.e. non-overlapping interval for each element in array:- "<<endl;
	for(int i=0;i<n;i++){
	    cin>>temp.start>>temp.end;
	    a.push_back(temp);
	}
	cout<<"Enter the new interval to be inserted:- "<<endl;
	cin>>newinterval.start>>newinterval.end;
	result = solution(a,newinterval);
	cout<<"The resultant array is :- ";
	for(int i=0;i<result.size();i++){
	    cout<<"["<<result[i].start<<" "<<result[i].end<<"]"<<" ";
	}
	return 0;
}
