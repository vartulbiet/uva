#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<pair<int,int> >ans;
 vector< list<int> >graph;
void APUtil(int u, bool visited[], int disc[],int low[], int parent[])
{
    
    static int time = 0;  
    visited[u] = true;
	
    disc[u] = low[u] = ++time;
	
    list<int>::iterator i;
	
    for (i = graph[u].begin(); i != graph[u].end(); ++i)
    {
        int v = *i;
        if (!visited[v])
        {
            parent[v] = u;
            APUtil(v, visited, disc, low, parent);

            low[u]  = min(low[u], low[v]);
 
             if (low[v] > disc[u])
              ans.PB(MP(min(u,v),max(u,v)));
        }

        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 

void AP(int V)
{
 
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        visited[i] = false;
     
    }
 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent);
 
 cout<<ans.size()<<" critical links"<<endl;
 sort(ans.begin(),ans.end());
	for(int i =0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" - "<<ans[i].second<<endl;
	}
	cout<<endl;
}
int main()
{
	int m =0;
	while(scanf("%d",&m)!=EOF)
	{
		for(int i =0;i<m;i++)
		{
			list<int>g;
			graph.PB(g);
		}
		for(int  i=0;i<m;i++)
		{
			int x =0;
			cin>>x;
			char a;
			int b;
			char c;
			cin>>a>>b>>c;
			for(int i =0;i<b;i++)
			{
				int uu =0;
				cin>>uu;
				graph[x].PB(uu);
			}
			//cout<<x<<" "<<a<<b<<c;
		}
		AP(m);
		ans.clear();
		graph.clear();
	}
	return 0;
}