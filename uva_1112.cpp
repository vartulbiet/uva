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
#define INF 1<<20
using namespace std;
int arr[105][105];
void init()
{
	for(int i =0;i<105;i++)
	{
		for(int j =0;j<105;j++)
		arr[i][j] =INF;
		arr[i][i] =0;
	} 
}
priority_queue<pair<int,int> > make_pq(vector<int>v,vector<bool>q)
{
	priority_queue<pair<int,int> >pq;
	for(int i =0;i<v.size();i++)
	{
		if(!q[i])
		{
			pq.push(make_pair(-v[i],i));
		}
	}
	return pq;
}
void djkstra(int a,int b,int c)
{
	vector<int>vert(a);
	for(int i =0;i<a;i++)
	vert[i] = INF;
	vert[b] = 0;
	vector<bool>visited(a);
	fill(visited.begin(),visited.end(),false);
	priority_queue<pair<int,int> >pq = make_pq(vert,visited);
	while(!pq.empty())
	{
		pair<int,int>f =pq.top();
		pq.pop();
		visited[f.second] = true;
		for(int i =0;i<a;i++)
		{
			if(vert[i]>abs(f.first)+arr[f.second][i] && visited[i] ==false)
			{
				vert[i] = abs(f.first)+arr[f.second][i];
			}
		}
		pq = make_pq(vert,visited);
	}
	int ans =0;
	for(int i =0;i<a;i++)
	{
		if(vert[i] <= c)
		ans++;
	}
	cout<<ans<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int v,s,t,c;
		init();
		cin>>v>>s>>t>>c;
		for(int i =0;i<c;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			arr[a-1][b-1] =c;
		}
		//cout<<v<<s<<t;
		djkstra(v,s,t);
		if(n!=0)
		printf("\n");
	}
	return 0;
}
