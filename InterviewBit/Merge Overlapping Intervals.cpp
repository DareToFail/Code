/*Given a collection of intervals, merge all overlapping intervals.
For example:
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
Make sure the returned intervals are sorted.*/
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
vector<interval> solution(vector<interval> &a){
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
	cout<<"Enter the start and end value i.e. overlapping interval for each element in array:- "<<endl;
	for(int i=0;i<n;i++){
	    cin>>temp.start>>temp.end;
	    a.push_back(temp);
	}
	result = solution(a);
	cout<<"The resultant array is :- ";
	for(int i=0;i<result.size();i++){
	    cout<<"["<<result[i].start<<" "<<result[i].end<<"]"<<" ";
	}
	return 0;
}
