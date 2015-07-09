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
int graph[205][205];
int color[205];
void BFS(int n)
{
	queue<int>q;
	int ans =0;
	
	for(int i =0;i<205;i++)
	{
	int  p =0;int t =0;
		if(color[i] == 2)
		{
			q.push(i);
			color[i] =0;
			t++;
			bool bt = true;
			while(!q.empty())
			{
				int y =q.front();
				q.pop();
					for(int j =0;j<n;j++)
					{
						if(graph[y][j] == 1)
						{
							if(color[j] == 2)
							{
								color[j] = 1-color[y];
								p++;
								q.push(j);
							}
							else if(color[j] == color[y])
							{
							bt =false;
							}
						}
					}
			}
			if(!bt)
			{
				ans =-1;
				break;
			}
			else
			{
				if(t>0 && p>0)
					ans+=min(t,p);
				else
					ans+=max(t,p);
			}
		}
	}

	cout<<ans<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int m,k;
		memset(graph,0,sizeof(graph));
		cin>>m>>k;
			for(int i =0;i<205;i++)
		color[i] =3;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			graph[x][y] =1;
			graph[y][x] =1;
			color[y] =2;
			color[x] =2;
		}
		BFS(m);
	}
	return 0;
}