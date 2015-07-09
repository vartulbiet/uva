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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
int graph[105][105];
map<int,int>mymap;
void init()
{
	for(int i =0;i<105;i++)
	{
		for(int j =0;j<105;j++)
		graph[i][j] =0;
	}
}
int end,a;
int DFS(int k)
{
	int temp =0;bool bt = true;int t =0;
	for(int i =0;i<a;i++)
	{
		if(graph[k][i]==1)
		{	
			bt = false;
			if(temp<mymap[i])
			{
				t =i;
				temp = mymap[i];
			}
		}
	}
	if(bt)
	{
		end = k;
	return 0;
	}
	else
	return temp + DFS(t);
	
}
int main()
{
	int n =0;
	cin>>n;int tc =1;
	while(n>0)
	{
		int b;
		cin>>a>>b;
		init();
		for(int i =0;i<a;i++)
		{
			int x =0;
			cin>>x;
			mymap[i] =x;
		}
		end =0;
		for(int i =0;i<b;i++)
		{
			int u,v;
			cin>>u>>v;
			graph[u][v] = 1;
		}
		int ans = DFS(0);
		cout<<"Case "<<tc++<<": "<<ans<<" "<<end<<endl;;
		mymap.erase(mymap.begin(),mymap.end());
		n--;
	}
	return 0;
}