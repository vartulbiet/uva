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
void BFS(vector<vector<int> >graph,map<string ,int>mymap,string s,string d,vector<string >vec)
{
	int n = mymap.size();
	int x = mymap[s];
	int y = mymap[d];
	queue<int>q;
	q.push(x);
	vector<bool>visited(n);
	for(int i =0;i<n;i++)
	visited[i ] = false;
	visited[x] = true;
	vector<int>par(n);
	for(int i =0;i< n;i++)
	{
		par[i] = -1;
	}
	bool bt =true;
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		if(t == y)
		{
			bt = false;
			break;
		}
		for(int i =0;i<graph[t].size();i++)
		{
			if(visited[graph[t][i]] == false)
			{
				//cout<<t<<" "<<graph[t][i]<<endl;
				visited[graph[t][i]] = true;
				q.push(graph[t][i]);
				par[graph[t][i]]=t;
			}
		}
	}
	if(bt)
	{
		cout<<"No route"<<endl;
	}
	else
	{
		vector<pair<string,string> >ans;
		for(int i = y; i!= x;i = par[i])
		{
			//cout<<vec[par[i]]<<" "<<vec[i]<<endl;
			ans.PB(MP(vec[par[i]],vec[i]));
		}
		
		reverse(ans.begin(),ans.end());
		for(int i =0;i<ans.size();i++)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
}

int main()
{
	int n =0;
	scanf("%d",&n);
	bool bt =true;
	while(bt)
	{
		map<string,int>mymap;
		vector<string>vec;
		vector<pair<int,int> >edges;
		int j =0;
		for(int i =0;i<n;i++)
		{
			string a,b;
			cin>>a>>b;
			if(mymap.find(a) ==mymap.end())
			{
				mymap[a] =j++;
				vec.PB(a);
			}
			if(mymap.find(b) ==mymap.end())
			{
				mymap[b] =j++;
				vec.PB(b);
			}
			edges.PB(MP(mymap[a],mymap[b]));
		}
		string a,b;
		cin>>a>>b;
		if(mymap.find(a) ==mymap.end())
		{
			mymap[a] =j++;
			vec.PB(a);
		}
		if(mymap.find(b) ==mymap.end())
		{
			mymap[b] =j++;
			vec.PB(b);
		}
		vector<vector<int> >graph(mymap.size());
		for(int i =0;i<edges.size();i++)
		{
			pair<int,int>g = edges[i];
			graph[g.first].PB(g.second);
			graph[g.second].PB(g.first);
		}
		BFS(graph,mymap,a,b,vec);
		if(scanf("%d",&n) !=EOF)
		{
			cout<<endl;
		}
		else
		bt = false;
	}
	return 0;
}