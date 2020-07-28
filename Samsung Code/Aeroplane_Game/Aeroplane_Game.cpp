/*We have a game where an airplane is placed in the middle column of the bottom row. The airplane can move right or left by one step and in every
step the row moves down. When the airplane meets ‘1’ (coin) the number of points increase by 1 and when the airplane meets ‘2’ (bomb) the number 
of points decrease by 1. Whenever the airplane meets the bomb with score 0 the airplane dies and game is over. The user has one detonate option 
throughout the game where he can detonate all the bombs in the next 5 rows.Find the maximum number of points (coins) that can be collected by the user.
Number of rows 1 <= N <= 12. Return -1 if score < 0
SAMPLE INPUT
3
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
5
1 1 0 0 0
1 2 2 2 1
1 1 2 2 1
2 2 2 1 2
2 2 0 2 0
6
2 2 2 2 2
0 0 0 0 0
0 0 2 0 0
2 0 0 0 2
0 0 0 0 0
1 2 2 2 1
SAMPLE OUTPUT
6
3
-1*/
#include<iostream>
using namespace std;
//12 rows max in game board and 5 column always
int gameboard[13][5];
//matrix which store bomb position in 5*5 space
int bomb[5][5];

//detonate i.e. bombard
void detonate(int row){
	//as row start from max n to low i.e. 0
	for(int i=row;i>row-5 && i>=0;i--){
		for(int j=0;j<5;j++){
			bomb[row-i][j]=0;//initially storing 0 bomb
			if(gameboard[i][j]==2){
				bomb[row-i][j] = 2;
				gameboard[i][j]=0;
			}
			
		}
	}
}

void undetonate(int row){
	for(int i=row;i>row-5 && i>=0;i--){
		for(int j=0;j<5;j++){
			if(bomb[row-i][j]==2){
				gameboard[i][j]=2;
			}
		}
	}
}

void getmaxcoin(int col_pos,int coin,int n,int &maxcoin){
	if(col_pos<0 || col_pos>4 || coin<0)
		return;
	if(gameboard[n-1][col_pos]==2)
		coin -= 1;
	else if(gameboard[n-1][col_pos]==1)
		coin += 1;
	if(n==1){
		if(coin>maxcoin)
			maxcoin =coin;
		return;
	}
	else{
		//3 option
		//move right
		getmaxcoin(col_pos+1,coin,n-1,maxcoin);
		//move left
		getmaxcoin(col_pos-1,coin,n-1,maxcoin);
		//not move
		getmaxcoin(col_pos,coin,n-1,maxcoin);
	}
}
int main(){
	int t,n,coin,score;
	cout<<"Enter the test case:- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the row no. <=12 and >=5:- ";
		cin>>n;
		cout<<"Enter the five value of each "<<n<<" rows value should be 0 ,1,2 :- \n";
		for(int j=0;j<n;j++){
			for(int k=0;k<5;k++){
				cin>>gameboard[j][k];
			}
		}
		//ground level zero point and bomb
		for(int j=0;j<5;j++){
			gameboard[n][j]=0;
		}
		//position of aeroplane in middle i.e. at col 3
		gameboard[n][2] = 3;
		score = -1;
		for(int j=n-1;j>0;j--){
			coin = -1;
			//detonate
			detonate(j);
			getmaxcoin(2,0,n,coin);
			if(coin>score)
				score = coin;
			//undetonate
			undetonate(j);
		}
		cout<<((score<0)?-1:score)<<endl;
		
	}
}
