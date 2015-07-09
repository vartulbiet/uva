#include<iostream>
#include<vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<10
using namespace std;
vector<int>graph[105];
int dp[105];
int last[105];
void init()
{
	for(int i =0;i<105;i++)
	{
	//for(int j =0;j<105;j++)
	dp[i] = -1;
	last[i] = INF;
	graph[i].clear();
	}
}
int longest_path(int i,int n)
{
	int l = 0;
	bool bt =true;
	int y =i;
	if(dp[i] != -1)
	{
		return dp[i];
	}
	
	vector<int>g =graph[i];
	
	if(g.size()==0)
	{
		last[i] =i;
		return dp[i] =0;
	}
	
	for(int j =0;j<g.size();j++)
	{

			int x = 1+longest_path(g[j],n);
			if(l<x)
			{
				y = last[g[j]];
				l = x;
			}
			else if(l == x)
			{
				y = min(y,last[g[j]]);
			}
	}
	last[i] = y;
	return dp[i] = l;
}
int main()
{
	int n =0;
	scanf("%d", &n);int tc =0;
	while(n!=0)
	{
		int s =0;
		scanf("%d", &s);
		init();
		int x,y;
		cin>>x>>y;
		while(x!=0 && y!=0)
		{
			graph[x-1].PB(y-1);
			cin>>x>>y;
		}
		//cout<<"hi"<<endl;
		int u =longest_path(s-1,n);
		int l = last[s-1];
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++tc, s, dp[s-1], last[s-1]+1);
		scanf("%d", &n);
	}
	return 0;
}