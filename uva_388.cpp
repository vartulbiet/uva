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
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
	int graph[28][28];
void BFS(vector<double>value,int n)
{
	queue<int>q;
	int *dis = (int*)malloc(sizeof(int)*28);
	memset(dis,0,sizeof(int)*28);
	q.push(27);
	while(!q.empty())
	{
		int y = q.front();
		q.pop();
		for(int i =0;i<n;i++)
		{
			if(dis[i] == 0 && graph[y][i] == 1 && i != 0)
			{
				q.push(i);
				dis[i] = dis[y] + 1;
			}
		}
	}
	double maxc =0;int ans =0;
	for(int i = 0;i<27;i++)
	{
		if(maxc <value[i]*pow(.95,dis[i]))
		{
			maxc = value[i]*pow(.95,dis[i]);
			ans =i;
		}
	}
	cout<<"Import from "<<char(ans+'A')<<endl;
}
int main()
{
	int n =0;
	while(scanf("%d",&n) == 1)
	{
		vector<double>val(28);
		int j =n;
		memset(graph,0, sizeof(graph));
		while(n--)
		{
			char x;double y;string z;
			cin>>x>>y>>z;
			val[x-'A'] = y;
			for(int k =0;k<z.size();k++)
			{
				if(z[k] == '*')
				{
					graph[x-'A'][27] =1;
					graph[27][x-'A'] = 1;
				}
				else
				{	
					graph[x-'A'][z[k] - 'A'] =1;
					graph[z[k] - 'A'][x-'A'] = 1;
				}
			}
		}
		BFS(val,j+1);
	}
	return 0;
}