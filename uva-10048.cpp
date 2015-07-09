#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30
using namespace std;
int graph[105][105];

int n;
void init()
{
	for(int i =0;i<105;i++)
	{
		for(int j =0;j<105;j++)
			graph[i][j] =INF;
		graph[i][i] =0;
	}
}
void min_value_in_path()
{
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
				graph[j][k] = min(graph[j][k],max(graph[j][i],graph[i][k]));
			}
		}
	}
}
int main()
{
   int x,y;
   cin>>n>>x>>y;int t =1;
   while(n!=0 || x!=0 || y!=0)
   {
	init();
	if(t!=1)
	cout<<endl;
	for(int i =0;i<x;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		graph[a-1][b-1] =c;
		graph[b-1][a-1] =c;
	}
	min_value_in_path();
	cout<<"Case #"<<t++<<endl;
	for(int i =0;i<y;i++)
	{
		int a,b;
		cin>>a>>b;
		if(graph[a-1][b-1] == INF)
		cout<<"no path"<<endl;
		else
		cout<<graph[a-1][b-1]<<endl;
	}
	cin>>n>>x>>y;
   }
   return 0;
}