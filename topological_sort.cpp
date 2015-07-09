#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(long long)
#define FEL(i,a,b) for(long long i=a;i<b;i++)
#define INF 1<<10
#define PB push_back()
using namespace std;
int graph[6][6]  =	{0,0,0,0,0,0,
					0,0,0,0,0,0,
					0,0,0,1,0,0,
					0,1,0,0,0,0,
					1,1,0,0,0,0,
					1,0,1,0,0,0};
	

void topology(bool* visited,stack<int>&st,int k)
{
	visited[k] = true;
	for(int i =0;i<6;i++)
	if((visited[i]== false) && graph[k][i] ==1)
		topology(visited,st,i);
	st.push(k);
}
	
void topological_sort()
{
	stack<int>st;
	bool visited[6];
	
	for(int i = 0; i < 6;i++)
		visited[i] = false;
	for(int i = 0; i < 6;i++)
	{
		if(visited[i]== false)
			topology(visited,st,i);
	}
	
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
}
int main()
{
	topological_sort();
	return 0;
}