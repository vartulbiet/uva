#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include <limits.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(int)
#define FEL(i,a,b) for(int i=a;i<b;i++)
#define INF 1<<30
using namespace std;
#define V 6
   // Let us create a graph shown in the above example
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
int rGraph[V][V];
bool bfs(int s, int t, vector<int>parent)
{
   
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    return (visited[t] == true);
}		  
int fordFulkerson(int s,int t)
{
int u,v;
	for(int  i =0;i<V;i++)
	{
		for(int j =0;j<V;j++)
		rGraph[i][j] = graph[i][j];
	}
	int max_flow =0;
	vector<int>parent(V);
	while(bfs(s,t,parent))
	{
		int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
	}
	return max_flow;
}
int main()
{
 
 
    cout << "The maximum possible flow is " << fordFulkerson( 0, 5);
 
    return 0;
}