/*The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate 
the span of stock’s price for all n days. The span Si of the stock’s price on a given day i is defined as the maximum number of 
consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, 
if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	cout<<"Enter the no. of test cases :- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the size of array :- ";
	    cin>>n;
	    int c[n];
	    cout<<"Enter the cost for each day :- ";
	    for(int j=0;j<n;j++){
	        cin>>c[j];
	    }
	    int ans[n];
	    ans[0]=1;
	    for(int j=1;j<n;j++){
	        int count = 1;
	        while((j-count)>=0 && c[j]>=c[j-count]){
	            count += ans[j-count];
	        }
	        ans[j] = count;
	    }
	    cout<<"Span of cost of each day :- ";
	    for(int j=0;j<n;j++){
	        cout<<ans[j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
