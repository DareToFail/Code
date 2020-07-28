#include<iostream>
using namespace std;
int x[100],y[100],n,ans = INT_MAX,value;

int dist(int i,int j){
	return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}

void optimal(int index,int count,int visit[],int value){
	if(n==count){
		if(value+dist(index,n+1)<ans){
			ans = dist(index,n+1)+value;
		}
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			visit[i]=1;
			optimal(i,count+1,visit,value+dist(index,i));
			visit[i]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>x[0]>>y[0]>>x[n+1]>>y[n+1];
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i];
		}
		int visit[n+1];
		for(int i=0;i<=n;i++){
			visit[i]=0;
		}
		ans = INT_MAX;
		optimal(0,0,visit,value);
		cout<<ans<<endl;
	}
}
