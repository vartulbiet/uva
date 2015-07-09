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
void BELLMAN_FORD(vector< pair<pair<int,int>,int > >vec,int nodes,int s,int dd)
{
	vector<int>d(nodes);
	fill(d.begin(),d.end(),-INF);
	d[s] =100;
	for(int i =0;i<nodes-1;i++)
	{
		for(int j =0;j<vec.size();j++)
		{
			int u = vec[j].first.first;
			int v = vec[j].first.second;
			int cost = vec[j].second;
			if(d[u]+cost>d[v])
			d[v] = (d[u]+cost);
		}
	}
	bool bt =true;
		
		for(int i =0;i<nodes;i++)
		if(d[i]<=0)
		bt = false;
		//cout<<endl;
	if(!bt)
	cout<<"hopeless"<<endl;
	else
	cout<<"winnable"<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n != -1)
	{
		vector< pair<pair<int,int>,int > >vec;
		int s = -1,d =-1;
		for(int i =0;i<n;i++)
		{
			int cost;
			int m =0;
			cin>>cost>>m;
			if(cost ==0 && s==-1)
			s =i;
			else if(cost ==0 && s !=-1)
			d =i;
			for(int j =0;j<m;j++)
			{
				int t =0;
				cin>>t;
				vec.PB(MP(MP(i,t-1),cost));
			}
		}
		BELLMAN_FORD(vec,n,s,d);
		cin>>n;
	}
	return 0;
}