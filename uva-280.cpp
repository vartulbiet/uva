#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<math.h>
#include<cstdio>
#define INF 1<<20
#include<queue>
#include<algorithm>
using namespace std;
int graph[101][101];
int n;
bool visited[101];
void init()
{
	for(int i =0;i<101;i++)
	{
		for(int j =0;j<101;j++)
		{
		
		graph[i][j] =0;
		}
	}
}
void traversal(int s)
{
	for(int i =0;i<n;i++)
	{
		if(visited[i]!=true && graph[s][i]!=0)
		{
			visited[i] =true;
			traversal(i);
		}
	}
}
int main()
{
	cin>>n;
	while(n!=0)
	{
		int a =0;
		cin>>a;
		init();
		while(a!=0)
		{
			int b;
			cin>>b;
			while(b!=0)
			{
			graph[a-1][b-1] =1;
			cin>>b;
			}
			cin>>a;
		}
		//for(int i= 0;i<n;i++)
		//{
			//for(int j= 0;j<n;j++)
			//cout<<graph[i][j]<<" ";
			//cout<<endl;}
			//cout<<endl;
		int d;int e;
		cin>>d;
		for(int i=0;i<d;i++)
		{
			cin>>e;
			for(int i= 0;i<n;i++)
			visited[i] = false;
			traversal(e-1);
			int t =0;
			for(int i= 0;i<n;i++)
			if(visited[i]==false)
			t++;
			cout<<t;
			for(int i= 0;i<n;i++)
			if(visited[i]==false)
			cout<<" "<<i+1;
			cout<<endl;
		}
			
		cin>>n;
	}
	return 0;
}