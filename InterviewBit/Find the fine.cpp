#include <iostream>
using namespace std;
/*Given an array of penalties P, an array of car numbers C, and also the date D.
 The task is to find the total fine which will be collected on the given date.
  Fine is collected from odd-numbered cars on even dates and vice versa.*/
int fine_calculation(int *a,int *b,int d,int n){
    int fine = 0;
    for(int i=0;i<n;i++){
        if(d%2==0){
            if(a[i]%2!=0){
                fine = fine + b[i];
            }
        }
        else{
            if(a[i]%2==0){
                fine =fine +b[i];
            }
        }
    }
    return fine;
}
int main() {
	//code
	int t,n,d,fine;
	cout<<"Enter the no of Test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the no. of car and date :- ";
	    cin>>n>>d;
	    int c[n],p[n];
	    cout<<"Enter the car no. :- ";
	    for(int j=0;j<n;j++){
	        cin>>c[j];
	    }
	    cout<<"Enter penalty for the car no. :- ";
	    for(int j=0;j<n;j++){
	        cin>>p[j];
	    }
	    fine = fine_calculation(c,p,d,n);
	    cout<<"Total Fine :- ";
	    cout<<fine;
	    cout<<endl;
	}	
	return 0;
}
