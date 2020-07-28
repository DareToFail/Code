/*A company has to produce IOT products of different models,
Each product requires cpus,memories and boards. After production of models, some spare equipments may be left.
In these, cpus and memories can be sold as spare parts but boards cannot be sold.
Due to manufacturing constraints maximum 3 models can be produced.
Each product can be sold at the cost of its model.
Given N different models.
D cpus with price d each.
E memories with price e each.
F boards.
Input:-
T number of testcases, followed by testcases,
Each test case consists of
D total  number of cpus available.
E total number of memories available.
F total number of boards available.
N number of models followed by N lines consisting of
ai, bi, ci and pi where ai is the number of cpus,bi number of memories, ci number of boards
required for producing one unit of that model and pi is the selling price of the one unit of that model.

Output:-
Print the testcase number followed by the Maximum profit that can be made.

Note:- Maximum profit can also be attained without any production that is by just selling  its components.

Constraints:-
1 = N = 8,  1 = D,E,F = 100,  1 = d,e = 10,  1 = ai,bi,ci = 5,  1 = pi = 100
*/
#include<iostream>
#define MAX(a,b) (a>b) ? (a):(b)
using namespace std;

int D; /*No_of_CPU*/;
int E; /*No_of_Memory*/;
int F; /*No_of_Board*/;
int d; /*cpu price per unit*/
int e; /*memory price per unit*/
int N; /*No_of_model*/
int model[8][4]; /*0th-CPU, 1-Memory, 2-Board,3-Price*/
int visited[8];
int max_cost;

void getmax(int cpu,int mem,int board,int n,int cost){
	int j;
	max_cost = MAX(max_cost ,(cost+cpu*d+mem*e));
	if(n==4 || cpu==0 || mem==0 || board==0){
		return;
	}
	for(int i=0;i<N;i++){
		if(visited[i]==0){
			visited[i]=1;
			j=1;
			while(1){
				if(j*model[i][0]<=cpu && j*model[i][1]<=mem && j*model[i][2]<=board){
					getmax(cpu-j*model[i][0] , mem-j*model[i][1] , board-j*model[i][2] , n+1,cost+j*model[i][3] );
				}
				else{
					break;
				}
				j++;
			}
		}
		visited[i]=0;
	}
}

int main(){
	int t;
	cout<<"Enter the no. of test cases :- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Enter the no. of cpu available,memory available,board available :- ";
		cin>>D>>E>>F;
		cout<<"Enter the price of Cpu and Memory per unit :- ";
		cin>>d>>e;
		cout<<"Enter the no. of Models :- ";
		cin>>N;
		cout<<"Enter the cpu used ,mem used ,board used and collective price for each model :-\n";
		for(int j=0;j<N;j++){
			visited[j]=0;
			cin>>model[j][0]>>model[j][1]>>model[j][2]>>model[j][3];
		}
		max_cost = 0;
		getmax(D,E,F,1,0);
		cout<<"Max price can be earned is :- "<<max_cost<<endl;
	}
	return 0;
}
/*Input:
--------
7 

2 2 2 
1 1
1
2 2 2 6

5 10 10 
1 1       
2
2 1 1 8
1 1 1 6

10 10 10 
2 1      
1
1 2 2 3

4 6 4 
2 1         
4
2 4 2 9
1 3 1 7
2 1 1 8
1 2 2 6

40 80 60 
1 3      
7
3 2 2 56
5 4 2 12
3 5 3 65
1 2 5 78
5 5 2 85
4 2 3 76
5 5 1 48

100 100 100  
6 10      
8
3 3 1 74
2 3 1 41
3 2 1 64
2 2 3 68
2 2 2 71
2 3 2 66
2 3 3 84
3 3 1 48 


100 100 100 
1 1
8
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

Output:

#1 6
#2 35
#3 30
#4 21
#5 1338
#6 3550
#7 200

--------------------------------------------
Time taken including input reding.
#1  time = 0.002
#2 time = 0.002
#3 time = 0.001
#4 time = 0.003
#5 time = 0.064
#6 time = 0.203
#7 time = 0.001


*/
