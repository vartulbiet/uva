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
int graph[505][505];
bool matching(bool *seen,int*match,int x,int m)
{
	//seen[x] = true;
	for(int i =1;i<=m;i++)
	{
		if(seen[i] == false && graph[x][i] == 1)
		{
			seen[i] = true;
			if(match[i]==-1 || matching(seen,match,match[i],m))
			{
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}
void MBM(int a,int b,int c)
{
	int match[b+1];int ans =0;
	memset(match,-1,sizeof(match));
	for(int i =1;i<=a;i++)
	{
		bool seen[b+1];
		memset(seen,false,sizeof(seen));
		if(matching(seen,match,i,b))
		ans++;
	}
	//cout<<ans<<endl;
	printf("%d\n",c-ans);
}
int main()
{
	int n =0;
		cin>>n;
		while(n>0)
		{
			//cout<<"k"<<endl;
			int a,b,c;
			 scanf("%d %d %d",&a,&b,&c);
			//cout<<a<<b<<c<<endl;
			int d =c;
			vector<pair<int,int> >cat(505);
			vector<pair<int,int> >dog(505);
			int ct = 0;
			memset(graph,0,sizeof(graph));
			int dt =0;
			while(c--)
			{
				char u,v;
				int w,x;
				cin>>u>>w>>v>>x;
				//cout<<u<<w<<v<<x<<endl;
				if(u == 'C')
				{
					cat[++ct].first = w;
					cat[ct].second = x;
				}
				else
				{
					dog[++dt].first = w;
					dog[dt].second = x;
				}
			}
			for(int i=1;i<=ct;i++)
			{
				for(int j=1;j<=dt;j++)
				{
					if(cat[i].first==dog[j].second||cat[i].second==dog[j].first)
					{
						graph[i][j] = 1;
					}
				}
			}
			MBM(ct,dt,d);n--;
			//cout<<"kk";
		}
		return 0;
}