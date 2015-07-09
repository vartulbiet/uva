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
#define INF 1<<20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
void floyd_warshall(vector<vi >temp,int hops)
{
	int n = temp.size();
vector<vi>graph(n);
for(int i =0;i<n;i++)
	{
		for(int k =0;k<n;k++)
		graph[i].PB(temp[i][k]);
	}
	vector<vi>hopp(n);
	for(int i =0;i<n;i++)
	{
		for(int k =0;k<n;k++)
		hopp[i].PB(1);
	}
	
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
				if((hopp[j][i] + hopp[i][k]-1) <=hops && (graph[j][i]+ graph[i][k])<graph[j][k])
				{
				graph[j][k] = graph[j][i]+ graph[i][k];
				hopp[j][k] =(hopp[j][i] + hopp[i][k]);
				}
			}
		}
	}
	if(graph[0][graph.size()-1] == INF)
	cout<<"No satisfactory flights"<<endl;
	else
	cout<<"Total cost of flight(s) is $"<<graph[0][graph.size()-1]<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	int tc = 1;
	while(n--)
	{
		int c =0;
		cin>>c;
		map<string,int>mymap;
		for(int i =0;i<c;i++)
		{
			string s;
			cin>>s;
			mymap[s] = i;
		}
	
		vector< vi >graph(c);
		for(int i =0;i<c;i++)
		{
			for(int j =0;j<c;j++)
			{
				graph[i].PB(INF);
			}
			graph[i][i] =0;
		}
		int t =0;
		cin>>t;
		cout<<"Scenario #"<<tc++<<endl;
		for(int i =0;i<t;i++)
		{
			string x,y;
			int cost;
			cin>>x>>y>>cost;
			graph[mymap[x]][mymap[y]] = min(graph[mymap[x]][mymap[y]] , cost);
		}
		int q =0;
		cin>>q;
		for(int i  = 0;i<q;i++)
		{
			int e =0;
			cin>>e;
			floyd_warshall(graph,e);
		}
		if(n!=0)
		cout<<endl;
	}
	return 0;
}