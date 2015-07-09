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
#define MP make_pair
#define INF 1<<30
using namespace std;
bool BFS(int**graph,int nodes)
{
	int s =0;
	int*color = (int*)malloc(sizeof(int)*nodes);
	memset(color,-1,sizeof(int)*nodes);
	color[s] =0;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int y = q.front();
		q.pop();
		int c = color[y];
		for(int i =0;i<nodes;i++)
		{
			if(color[i] == -1 && graph[y][i] == 1)
			{
				if(c == 1)
				{
					color[i] =0;
				}
				else
					color[i] = 1;
				q.push(i);
			}
		}
	}
	bool bt =true;
	for(int i =0;i<nodes;i++)
	{
		for(int j =0;j<nodes;j++)
		{
			if(graph[i][j] == 1 && color[i] == color[j])
			bt =false;
		}
	}
	return bt;
}
int main()
{
	int m,n =0;
	cin>>m;
	while(m!=0)
	{
		int **graph = (int**)malloc(sizeof(int*)*m);
		for(int i =0;i<m;i++)
		graph[i] = (int*)malloc(sizeof(int)*m);
		cin>>n;
		while(n--)
		{
			int x,y;
			cin>>x>>y;
			graph[x][y] =1;
			graph[y][x] =1;
		}
		bool t =BFS(graph,m);
		if(!t)
		cout<<"NOT BICOLORABLE."<<endl;
		else
		cout<<"BICOLORABLE."<<endl;
		cin>>m;
	}
	return 0;
}