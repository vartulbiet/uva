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
	memset(color,-INF,sizeof(int)*nodes);
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
			if(color[i] == -INF && graph[y][i] == 1)
			{
				color[i] = color[y]-1;
				q.push(i);
			}
			else if(graph[y][i] == 1 && color[i] == color[y])
				return false;
		}
	}
	return true;
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
		int x,y;
			cin>>x>>y;
		while(x||y)
		{
			graph[x-1][y-1] =1;
			graph[y-1][x-1] =1;
			cin>>x>>y;
		}
		bool t =BFS(graph,m);
		if(!t)
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
		cin>>m;
	}
	return 0;
}