#include<iostream>
using namespace std;
int n,m;
int graph[100][100],visit[100][100];
int rear = 0,front =0;
struct index{
	int x,y;
};
index q[1000];


