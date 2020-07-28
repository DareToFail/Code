/*Mountain / Rock Climbing
Mr. Kim is very good at climbing rocks, rocks are represented by 1 and spaces are represented by 0, all cells in the ground level contains 1,
bottom left cell is always the src and is represented by 2, destination can be anywhere and is represented by 3
he can move up down & left right,In horizontal direction Kim cant skip rocks however vertical direction he can.
Input:-
2
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
2 1 1 1 1 1 1 1
5 6
0 1 1 1 0 0
3 1 0 1 1 0
0 0 0 0 1 1
0 0 0 0 0 1
2 1 1 1 1 1

#Case 1
2
#Case 2
1

*/
#include<iostream>
using namespace std;
int n,m;//row and column
int graph[100][100];
int visited[100][100];
int front =0,rear = 0;

struct index{
	int x;		// x- horizontal direction
	int y;		// y- vertical direction
};

index queue[1000];		//will store the position of kim

//checking boundry condition
bool isvalid(int x , int y){
	if( x>=0 && x<n && y>=0 && y<m){
		//checking path exit there means no rock.
		if(graph[x][y]!=0){				
			return true;
		}
	}
	return false;
}


int bfs(int x,int y,int height){
	visited[x][y]=1;
	//entering the position of kim in queue and increment rear position
	queue[rear++]={x,y};
	
	//Visiting node breadth wise
	while(front<rear){
		//storing the current position of kim in fifo order
		struct index currpos = queue[front];
		front++;//poping queue
		int X = currpos.x;
		int Y = currpos.y;
		
		//checking if final destination reached
		if(graph[X][Y]==3){
			return height;
		}
		
		//Moving right and left by checking boundry condition and visiting position first time
		if(isvalid(X,Y+1) && visited[X][Y+1]==0){
			queue[rear++] = {X,Y+1};
			visited[X][Y+1]=1;
		}
		if(isvalid(X,Y-1) && visited[X][Y-1]==0){
			queue[rear++] = {X,Y-1};
			visited[X][Y-1] = 1;
		}
		
		//Moving up or down from 1 steps initially to k jump steps(here k is height)
		for(int k=1;k<=height;k++){
			if(isvalid(X-k,Y) && visited[X-k][Y]==0){
				queue[rear++] = {X-k,Y};
				visited[X-k][Y] = 1;
			}
			if(isvalid(X+k,Y) && visited[X+k][Y]==0){
				queue[rear++] = {X+k,Y};
				visited[X+k][Y] = 1;
			}
		}
		
	}
	return 0;	
}

int main(){
	int t;
	cout<<"Enter the test cases :- ";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Size of row and column:- ";
		cin>>n>>m;
		cout<<"Enter the value at respective positive with 0,1,2 or 3i.e 2 is source 3 is destination 0 rock 1 path :-\n";
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin>>graph[j][k];
				//initially all position are not visited
				visited[j][k] = 0;
			}
		}
		graph[n-1][0]=2;
		int min_height = 0;
		for(int j=1;j<n;j++){
			//always start from source i.e.position x=n-1,y=0
			min_height = bfs(n-1,0,j);
			if(min_height>0)
				break;
			//again visit by increasing height value so flush old values
			for(int k=0;k<n;k++){
				for(int l=0;l<m;l++){
					visited[k][l]=0;
				}
			}
		}
		cout<<"Min_height to reach destination is for test case "<<t<<" is:- "<<min_height<<endl;
	}
}
