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
#define MP make_pair
#define INF 1<<30
using namespace std;
	vector<vector<int> >arr;
bool compare(pair<int,int>p,pair<int,int>q)
{
	if(p.first>q.first)
	return true;
	if(p.first == q.first)
	{
		if(q.second>p.second)
		return true;
	}
	return false;
}
void DFS(vector<bool>& visited,int m,int s,int k)
{
	for(int i =0;i<arr[s].size();i++)
	{
		if(visited[arr[s][i]] == false && arr[s][i] !=k)
		{
			visited[arr[s][i]] = true;
			DFS(visited,m,arr[s][i],k);
		}
	}
}
// IT WILL CAUSE TLE AS IT IS VERY BASIC APPROACH OR CAN SAY BRUTE FORCE... LOOK FOR SMARTER ONE... SAVED AS _2;;;;
int main()
{
	int m,n;
	cin>>m>>n;
	while(m || n)
	{
		int x,y;
		for(int i =0;i<m;i++)
		{
			vector<int>l;
			arr.PB(l);
		}
		cin>>x>>y;
		while(x!=-1 || y!=-1)
		{
			arr[x].PB(y);
			arr[y].PB(x);
			cin>>x>>y;
		}
		vector<pair<int,int> >ans;
		for(int k =0;k<m;k++)
		{
			vector<bool>visited;
			for(int i =0;i<m;i++)
				visited.PB(false);
			int g =0;
			for(int i =0;i<m;i++)
			{
				if(visited[i] == false && i!=k)
				{
					g++;
					visited[i] = true;
					DFS(visited,m,i,k);
				}
			}
			//cout<<g<<" "<<k<<endl;
			ans.PB(MP(g,k));
		}
		sort(ans.begin(),ans.end(),compare);
		for(int i =0;i<n;i++)
		{
			cout<<ans[i].second<<" "<<ans[i].first<<endl;
		}
		cout<<endl;
		arr.clear();
		cin>>m>>n;
	}
	return 0;
}