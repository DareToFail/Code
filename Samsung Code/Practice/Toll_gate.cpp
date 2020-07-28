#include<iostream>
using namespace std;
int tp,th[100],tc[100],bp3,bp2,bp1,cc,min_cost,n;
void dfs(int tp,int bp3,int bp2,int bp1,int cc){
	int total_bp = bp3+bp2+bp1;
	if(cc>min_cost){
		return;
	}
	if(tp==n-1){
		if(total_bp<th[tp]){
			cc = cc +tc[tp];
		}
		if(cc<min_cost){
			min_cost=cc;
		}
		return;
	}
	
	dfs(tp+1,bp3,bp2,bp1,cc+tc[tp]);
	dfs(tp+1,bp3+th[tp],bp2,bp1,cc+2*tc[tp]);
	
	if(total_bp>=th[tp]){
		if(th[tp]>bp2+bp1){
			bp3 = total_bp - th[tp];
			bp2=0;
			bp1 =0;
		}
		else if(th[tp]>bp1){
			bp2 = bp2+bp1 - th[tp];
			bp1 = 0;
		}
		dfs(tp+1,0,bp3,bp2,cc);
	}
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		min_cost = 100000;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>th[i]>>tc[i];
		}
		dfs(0,0,0,0,0);
		cout<<min_cost<<endl;
	}
	return 0;
}
