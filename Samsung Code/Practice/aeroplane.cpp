#include<iostream>
using namespace std;
int gameboard[13][5],bomb[5][5];
void detonate(int row){
	for(int i=row;i>row-5 && i>=0;i--){
		for(int j=0;j<5;j++){
			bomb[i-row][j]=0;
			if(gameboard[i][j]==2){
				bomb[i-row][j]=2;
				gameboard[i][j]=0;
			}
		}
	}
}
void undetonate(int row){
	for(int i=row;i>row-5 && i>=0;i--){
		for(int j=0;j<5;j++){
			if(bomb[i-row][j]==2){
				bomb[i-row][j]=0;
				gameboard[i][j]=2;
			}
		}
	}
}
void getmax(int col_pos,int coin,int n,int &maxcoin){
	if(col_pos<0 || col_pos>4 || coin<0){
		return;
	}
	if(gameboard[n-1][col_pos]==2){
		coin -= 1;
	}
	else if(gameboard[n-1][col_pos]==1){
		coin += 1;
	}
	if(n==1){
		if(coin>maxcoin){
			maxcoin = coin;
		}
		return;
	}
	
	getmax(col_pos+1,coin,n-1,maxcoin);
	getmax(col_pos-1,coin,n-1,maxcoin);
	getmax(col_pos,coin,n-1,maxcoin);
}
int main(){
	int t,n,score,coin;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				cin>>gameboard[i][j];
			}
		}
		for(int j=0;j<5;j++){
			gameboard[n][j]=0;
		}
		gameboard[n][2]=3;
		score = -1;
		for(int i=n-1;i>0;i--){
			coin = -1;
			detonate(i);
			getmax(2,0,n,coin);
			if(coin>score){
				score = coin;
			}
			undetonate(i);
		}
		cout<<((score<0)? -1:score)<<endl;
	}
	return 0;
}
