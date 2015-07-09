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

map<pair<int,int> ,int>mymap;
map<pair<int,int> ,int>grp;
map<int,pair<int,int> >rev_map;
vector<vector<double> >graph;
void djkstra(pair<int ,int>s,pair<int,int>end)
{
	priority_queue<pair<double,int >,vector< pair<double,int> >,greater< pair<double,int > > >pq;
	
	map<int,double>dist;
	for(int i =0;i<mymap.size();i++)
	{
		dist[i] = INF;
	}

	dist[mymap[s]] = graph[mymap[s]][mymap[s]];
		pq.push(make_pair(dist[mymap[s]] ,mymap[s]));
	while(!pq.empty())
	{
		pair<double,int > x = pq.top();
		pq.pop();
		if(x.first == dist[x.second] )
		for(int i =0;i<graph[x.second].size();i++)
		{
			if(x.first + graph[x.second][i] < dist[i])
			{
				dist[i] = x.first + graph[x.second][i];
				pq.push(make_pair(dist[i],i));
			}
		}
	}
	cout<<dist[mymap[end]]/60<<endl;
}

double dist(pair<int,int>a,pair<int,int>b)
{
	return  (double)sqrt((double)(a.first-b.first)*(a.first-b.first) + (double)(a.second-b.second)*(a.second-b.second));
}
void make_graph(vector<vector<pair<int,int> > >vec)
{
	for(std::map<pair<int,int>,int>::iterator it =mymap.begin();it!=mymap.end();it++)
	{
		vector<double>time;
		for(std::map<pair<int,int>,int >::iterator jt =mymap.begin();jt!=mymap.end();jt++)
		{
			if(grp[it->first] == grp[jt->first])
			{
				time.PB(dist(it->first,jt->first)*40000/3600);
			}
			else
				time.PB(dist(it->first,jt->first)*10000/3600);
		}
		graph.PB(time);
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int a1,b1,a2,b2;
		cin>>a1>>b1>>a2>>b2;
		int c =0;
		int gp =0;
		mymap[make_pair(a1,b1)] = c;
		rev_map[c++]= make_pair(a1,b1);
		grp[make_pair(a1,b1)] = gp++;
		vector<vector<pair<int,int> > >vec;
		vector<pair<int,int> >v;
		v.PB(make_pair(a1,b1));
		vec.PB(v);
		int x,y;
		while(scanf("%d",&x)!=EOF)
		{
			cin>>y;
			vector<pair<int,int> >v1;
			while(x !=-1 && y!=-1)
			{
				v1.PB(make_pair(x,y));
				mymap[make_pair(x,y)] = c;
				rev_map[c++]= make_pair(x,y);
				grp[make_pair(x,y)] = gp;
				cin>>x>>y;
			}
			gp++;
			vec.PB(v1);
		}
		mymap[make_pair(a2,b2)] = c;
		rev_map[c++]= make_pair(a2,b2);
		vector<pair<int,int> >v2;
		v2.PB(make_pair(a2,b2));
		grp[make_pair(a2,b2)] = gp;
		vec.PB(v2);
		make_graph(vec);
		djkstra(make_pair(a1,b1),make_pair(a2,b2));
	}
	return 0;
}