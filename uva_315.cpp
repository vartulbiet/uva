#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define NIL -1
using namespace std;
 
class Graph
{
    int V;   
    list<int> *adj; 
    void APUtil(int v, bool visited[], int disc[], int low[],
                int parent[], bool ap[]);
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void AP();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::APUtil(int u, bool visited[], int disc[],int low[], int parent[], bool ap[])
{
    
    static int time = 0;  
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);

            low[u]  = min(low[u], low[v]);
 
            if (parent[u] == NIL && children > 1)
               ap[u] = true;
			   
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }

        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 

void Graph::AP()
{
 
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V]; 

    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }
 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
 
	int nas =0;
    for (int i = 0; i < V; i++)
	{
        if (ap[i] == true)
            nas++;
	}
	cout<<nas<<endl;
}
int main()
{
	int m =0;
	cin>>m;
	while(m !=0)
	{
	 Graph g1(m);
   
		getchar ();
        char input [10000];
 
 
        while ( gets (input) && strcmp (input, "0")) {
            char *pch;
            pch = strtok (input, " ");
 
            int node = atoi (pch);
            pch = strtok (NULL, " ");
 
            while ( pch != NULL ) {
                int conn = atoi (pch);
                g1.addEdge(conn-1,node-1);
               g1.addEdge(node-1,conn-1);
                pch = strtok (NULL, " ");
            }
        }
 
        if ( m == 1 ) { printf ("0\n"); continue; }
		 g1.AP();
		cin>>m;
	}
	return 0;
}