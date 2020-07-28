/*
tp-- toll position i.e. index
th[]--contains hire person at toll
tc[]--contains toll cost
n-- no of toll
cc--current cost
min_cost-- minimum cost
bp1_bp2_bp3--- battle person with life time 1,2,3 respectively
*/
#include<iostream>
using namespace std;
int n,tp,tc[100],th[100],min_cost,cc,bp3,bp2.bp1;
void dfs(int tp,int bp3,int bp2,int bp1,int cc){
	int tot_bp = bp3+bp2+bp1;
	if(cc>min_cost)	//to avoid unnecessary cpu cycle
		return;
	if(tp==n-1)		//base condition i.e. standing at the last toll
	{
		if(tot_bp < th[tp])	//persong with us is less than person at toll
			cc = cc + tc[tp];
		if(cc<min_cost)
			min_cost = cc;
		return;
	}
	
	//case 1: pay toll money and pass
	dfs(tp+1,bp3,bp2,bp1,cc+tc[tp]);
	
	//case2: toll pay double and hire
	 dfs(tp+1,bp3+th[tp],bp2,bp1,cc+2*tc[tp]);
	 
	 //case 3: battle fight
	 if(tot_bp>=th[tp]){
	 	if(th[tp] > bp2+bp1){
	 		bp3 = tot_bp - th[tp];
		}
		if(th[tp] > bp1){
		 	bp2 = th[tp]-bp1 >=bp2 ? 0:bp2-th[tp]+bp1;
		}
		dfs(tp+1,0,bp3,bp2,cc); //baatle pool 3 becomes battle pool 2 as for every fight they loose one life time
	 }
}
int main(){
	int t;
	cout<<"Enter the no. of test cases:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		min_cost = 1000000;
		cout<<"Enter the no. of total toll:- ";
		cin>>n;
		cout<<"Enter the each toll hire and cost at that toll:-\n";
		for(int j=0;j<n;j++){
			cin>>th[j]>>tc[j];
		}
		dfs(0,0,0,0,0);
		cout<<min_cost<<endl;
	}
	return 0;
}
