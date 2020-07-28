/*Fishing Spots: 1 to N
3 Gates with gate position and number of fishermen waiting to get in
Distance between consecutive spots = distance between gate and nearest spot = 1 m.
Fishermen are waiting at the gates to get in and occupy nearest fishing spot. Only 1 gate can be opened at a time and all fishermen
of that gate must occupy spots before next gate is open.
There could be 2 spots closest to the gate. Assign only 1 spot to the last fisherman in such a way that we get minimum walking distance. 
For rest of the fishermen, ignore and assign any one.
Write a program to return sum of minimum distance need to walk for fishermen.
The problem can be solved using Recursion and Backtracking by considering all possible combinations.*/
#include<iostream>
using namespace std;
int min_dist;


void mindist(int per[],int gate[],int people[],int visited[],int index,int dist,int n){
	//if all gate visited
	if(index==3){
		if(dist<min_dist){
			min_dist = dist;
		}
		return;
	}
	
	int i = per[index];			//storing gate index
	int pep = people[i];		//storing total waiting people of gate i
	int left = gate[i];			//curser to move left to search space to seat
	int right = gate[i]+1;		//cursor to move right to search space to sit
	
	//all people getting seat
	for(int j=0;j<pep;j++){
		while(left>=0 && visited[left]==1){		//if left side space is not empty
			left--;
			if(left==-1){
				break;
			}
		}
		while(right<n && visited[right]==1){		//if right side space is not empty
			right++;
			if(right==n){
				break;
			}
		}
		if(left<=-1 && right >=n){				//if both left and right side got full
			return;
		}
		if(left==-1){							//if left side is full
			dist += right - gate[i]+1;
			visited[right] = 1;
			right++;
		}
		else if(right==n){						//if right side is full
			dist += gate[i] - left +1;
			visited[left] = 1;
			left--;
		}
		else if(j==pep-1 && right - gate[i]==gate[i]-left){		//if last person of gate i to seat and have two option same dist
			int visited1[n];
			for(int k=0;k<n;k++){								//for considering both option we define other visited array
				visited1[k] = visited[k];
			}
			//selecting right side
			visited[right] = 1;
			dist += right - gate[i] + 1;
			right++;
			mindist(per,gate,people,visited,index+1,dist,n);
			
			//restoring the previous value i.e. not selecting right but selecting left
			right--;
			dist -= right - gate[i]+1;
			//visited[right] = 0;
			dist += gate[i] - left +1;
			visited1[left] = 1;
			left--;
			mindist(per,gate,people,visited1,index+1,dist,n);
		}
		//if moving left give less distance then right
		else if(gate[i]-left < right - gate[i]){
			dist += gate[i] - left + 1;
			visited[left] = 1;
			left--;
		}
		else if(gate[i]-left >= right-gate[i]){
			dist += right - gate[i]+1;
			visited[right]=1;
			right++;
		}
	}
	mindist(per,gate,people,visited,index+1,dist,n);
}
int main(){
	int t,n;
	cout<<"Enter the no. of test cases:- ";
	cin>>t;
	while(t--){
		cout<<"Enter the no. of fishery spot :- ";
		cin>>n;
		int gate[3],people[3];	 	//gate store the gate no. and people array store people in waiting in respective gate
		int per[3];					//per array contains permutation of gate in which order to open
		cout<<"Enter the  3 gate no. from 1 to "<<n<<" and the respective people waiting their :-\n";
		for(int k=0;k<3;k++){
			cin>>gate[k]>>people[k];
			gate[k]--;						//as we consider gate no. from 0 - n-1 but user is enter as 1-n
		}
		
		int visited[n];
		min_dist = 999999;
		//permutation 1 of gate selecting
		for(int j=0;j<n;j++)	
			visited[j] = 0;
		per[0] = 0 ; per[1] = 1; per[2] = 2;
		mindist(per,gate,people,visited,0,0,n);	
		
		//permutation 2
		for(int j=0;j<n;j++)	
			visited[j] = 0;
		per[0] = 0 ; per[1] = 2; per[2] = 1;
		mindist(per,gate,people,visited,0,0,n);	
		
		//permutation 3
		for(int j=0;j<n;j++)	
			visited[j] = 0;
		per[0] = 1 ; per[1] = 0; per[2] = 2;
		mindist(per,gate,people,visited,0,0,n);
		
		//permutation 4
		for(int j=0;j<n;j++)	
			visited[j] = 0;
		per[0] = 1 ; per[1] = 2; per[2] = 0;
		mindist(per,gate,people,visited,0,0,n);
		
		//permutation 5
		for(int j=0;j<n;j++)	
			visited[j] = 0;
		per[0] = 2 ; per[1] = 0; per[2] = 1;
		mindist(per,gate,people,visited,0,0,n);
		
		//permutation 6
		for(int j=0;j<n;j++)	
			visited[j] = 0;
		per[0] = 2 ; per[1] = 1; per[2] = 0;
		mindist(per,gate,people,visited,0,0,n);
		
		cout<<"Min distance is :- "<<min_dist<<endl;			
	}
	return 0;
}
/*Input:-
5
//1st test case
10
4 5
6 2
10 2
// 2nd test case
10
8 5
9 1
10 2
//3rd test case
24 
15 3
20 4
23 7
//4th test case
39
17 8
30 5
31 9
//5th test case
60
57 12
31 19
38 16
Output
18
25
57
86
339*/
