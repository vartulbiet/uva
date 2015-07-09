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
int graph[1005][1005];
int calculate(int s,bool*temp,int n)
{
		int c =0;
		temp[s] = true;
		for(int i =0;i<n;i++)
		{
			if(graph[s][i] == 1)
			{
				int x =0;
				for(int j =0;j<n;j++)
				{
					if(graph[i][j] == 1)
					{
						
					}
				}
			}
		}
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int nodes;
		cin>>nodes;
		memset(graph,0,sizeof(graph));
		for(int i =0;i<nodes-1;i++)
		{
			int a,b;
			cin>>a>>b;
			graph[a-1][b-1] = 1;
			graph[b-1][a-1] = 1;
		}
		int mint =INF;
		for(int i =0;i<nodes;i++)
		{
			bool *visited = (bool*)malloc((sizeof(bool))*nodes);
			memset(visited,false,sizeof(visited));
			mint =min(mint,calculate(i,visited,nodes));
		}
	}
	return 0;
}