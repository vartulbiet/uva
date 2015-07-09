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
#define INF 1<<30
#define MP make_pair
using namespace std;
int rr[4] = {-1,1,0,0};
int ss[4] = {0,0,1,-1};
bool valid(pair<int,int>v,vector<string>arr,vector<vector<bool> >visit,int xx,int yy)
{
for(int i =0;i<4;i++)
{
if(v.first+rr[i]>=0 && v.first+rr[i]<xx && v.second+ss[i]>=0 && v.second+ss[i]<yy && arr[v.first+rr[i]][v.second+ss[i]] == 'T')
					{
						return false;
					}
					
				}
				return true;
}
int BFS(vector<string>arr)
{
	pair<int,int>s;
	int xx = arr.size();
	int yy= arr[0].size();
	vector<vector<bool> >visit;
	for(int i =0;i<arr.size();i++)
	{
		int g = arr[i].size();
		vector<bool>aa;
		for(int j =0;j<g;j++)
		{
			if(arr[i][j] == 'P')
			{
				s.first = i;
				s.second = j;
			}
			aa.PB(false);
		}
		visit.PB(aa);
	}
	queue<pair<int,int> >q;
	q.push(s);
	visit[s.first][s.second] = true;
	int ans =0;
	while(!q.empty())
	{
		pair<int,int>v = q.front();
		q.pop();
		if(arr[v.first][v.second] == 'G')
		ans++;
		if(arr[v.first][v.second] == 'G' || arr[v.first][v.second] == '.' || arr[v.first][v.second] == 'P')
		{
			if(valid(v,arr,visit,xx,yy))
			{
				for(int i =0;i<4;i++)
				{
					if(v.first+rr[i]>=0 && v.first+rr[i]<xx && v.second+ss[i]>=0 && v.second+ss[i]<yy && arr[v.first+rr[i]][v.second+ss[i]] != 'T' && arr[v.first+rr[i]][v.second+ss[i]] !='#' && visit[v.first+rr[i]][v.second+ss[i]]==false)
					{
						visit[v.first+rr[i]][v.second+ss[i]] = true;
						q.push(MP(v.first+rr[i],v.second+ss[i]));
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)==2)
	{
		vector<string>arr;
		string s;
		for(int i =0;i<n;i++)
		{
			string s;
			cin>>s;
			arr.PB(s);
		}
		cout<<BFS(arr)<<endl;
	}
	return 0;
}