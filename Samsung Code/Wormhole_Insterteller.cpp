  /*There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.There are N number of warmholes each warmhole 
has 5 values.First 2 values are starting co-ordinate of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 
5th value is represents cost to pass through this warmhole. Now these warmholes are bi-direction.Now the to go from (x1,y1) to (x2,y2) is 
abs(x1-x2)+abs(y1-y2).The main problem here is to find minimum distance to reach spaceship from source to destination co-ordinate using 
any number of warm-hole. It is ok if you wont use any warmhole
Smaple inputs..
4     // Number of test cases

0     // number of worm holes
0 0 60 60 // co-ordinates of start and end points.

1			// number of worm holes
0 0 2 0		// co-ordinates of start and end points.
1 0 1 2 0   // Co-ordinates of entry/exit and exit/entry with time taken to travel through the worm hole.

1 
0 0 60 60 
40 40 20 20 20 

2 
100 50 10 5 
80 40 10 6 10 
80 10 70 40 5 

3
500 500 1000 1000 
501 501 999 999 1000
1 1 499 499 100
1000 999 0 0 200
output-
120
2
41
305*/
#include<iostream>
using namespace std;
//Storing distace from one coordinate to other
int dist_graph[101][101];
//storing the x-coordinate and y-coordinate
int x[101],y[101];

int w_price[101];		//Storing price for one to other through wormhole

int getmin(int cost[],int visited[],int n){			//returning next minimum element
	int min = 999999;
	int index;
	for(int i=0;i<n;i++){
		if(min>cost[i] && visited[i]==0){
			min = cost[i];
			index = i;
		}
	}
	return index;
}

//For absolute value
int absolute(int i){
	if(i>0)
		return i;
	else
		return -1*i;
}

//Dijkastra Algorithms
int dijkastra(int size){
	int visited[size];			//Mainting the cost / distance for dijkastra
	int cost[size];				//Mainting the cost / distance for dijkastra
	for(int i=0;i<size;i++){	//Initially cost of source = 0 and other node is infinity
		cost[i] = 9999999;
		visited[i] = 0;
	}
	cost[0] = 0;
	for(int i=0;i<size;i++){
		int index = getmin(cost,visited,size);
		visited[index] = 1;
		for(int j=0;j<size;j++){
			if(i==j){
				continue;
			}
			else if(cost[j]> cost[index] + dist_graph[index][j]){
				cost[j] = cost[index] + dist_graph[index][j];
			}
		}
	}
	return cost[1];		//As destination is at index 1
}

int main(){
	int t,n;
	cout<<"Enter the no. of test cases :- ";
	cin>>t;
	for(int l=0;l<t;l++){
		cout<<"Enter the no. of wormhole :- ";
		cin>>n;
		cout<<"Enter the coordinates of source and destination as (x,y) :- ";
		cin>>x[0]>>y[0]>>x[1]>>y[1];
		if(n>0)
			cout<<"Enter the wormhole src and dest. coordinated followed by price:- ";
		
		int k = 2;				//Storing wormhole after source and destination
		for(int j=0;j<n;j++){
			cin>>x[k]>>y[k]>>x[k+1]>>y[k+1];
			k++;
			cin>>w_price[k-1];
			k++; 
		}
		//Calculating distace from one node to each other node 
		for(int i=0;i<k;i++) {
            for(int j=i+1;j<k;j++) {
            	
                dist_graph[i][j] = absolute(x[i] - x[j]) + absolute(y[i] - y[j]);
				if(i%2 == 0 && j == i+1 && i!=0) {
                    dist_graph[i][j] = min(w_price[i],dist_graph[i][j]);
                }
                
                dist_graph[j][i] = dist_graph[i][j];
            }
        }
        cout<<"The min distance between given src and dest. is :- ";
        /*for(int i=0;i<k;i++) {
            for(int j=0;j<k;j++) {
                cout<<dist_graph[i][j]<<" ";
            }    cout<<endl;
        }*/
        cout<<dijkastra(k)<<endl<<endl;
	}
	return 0;
}


