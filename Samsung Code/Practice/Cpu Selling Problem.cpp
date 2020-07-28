#include<iostream>
using namespace std;
#define MAX(a,b) (a>b) ? (a):(b)

int model[8][4],visit[8],N,max_cost,c,m,C,M,B;

void getmax(int cpu ,int mem ,int board,int n,int cost){
	int j;
	max_cost = MAX(max_cost , (cost + cpu*c + mem*m ));
	if(n==4 || cpu==0 || mem ==0 || board == 0){
		return;
	}
	for(int i=0;i<N;i++){
		if(visit[i]==0){
			j = 1;
			visit[i] = 1;
			while(1){
				if(j*model[i][0]<=cpu && j*model[i][1]<=mem && j*model[i][2]<=board){
					getmax(cpu-j*model[i][0], mem-j*model[i][1], board-j*model[i][2],  n+1,  cost+j*model[i][3]);
				}
				else{
					break;
				}
				j++;
			}
		}
		visit[i]=0;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>C>>M>>B;
		cin>>c>>m;
		cin>>N;
		for(int i=0;i<N;i++){
			for(int j=0;j<4;j++){
				cin>>model[i][j];
			}
			//cin>>model[i][0]>>model[i][1]>>model[i][2]>>model[i][3];
			visit[i]=0;
		}
		max_cost =0;
		getmax(C,M,B,1,0);
		cout<<max_cost<<endl;
	}
}
