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
pair<int,int>endd;
vector<pair<int,int> >given;
int n =0;
bool bt;
void recurse(vector<pair<int,int> >ans,vector<bool>visited)
{
	if(bt)
	return;
	if(ans.size()==n+1)
	{
		if(ans[n].second == endd.first)
		bt=true;
	}
	else
	{
		for(int i =0;i<given.size() && !bt;i++)
		{
			vector<pair<int,int> >tt = ans;
			vector<bool>visit = visited;
			if(ans[ans.size()-1].second == given[i].first && visited[i]==false)
			{
				tt.PB(given[i]);
				visit[i]= true;
				recurse(tt,visit);
			}
			else if(ans[ans.size()-1].second == given[i].second && visited[i]==false)
			{
				pair<int,int>temp;
				temp.first= given[i].second;
				temp.second = given[i].first;
				tt.PB(temp);
				visit[i]= true;
				recurse(tt,visit);
			}
		}
	}
}
int main()
{
	cin>>n;
	while(n!=0)
	{
		int t =0;cin>>t;pair<int,int>start;
		int a,b;
		cin>>a>>b;
		bt = false;
		start= make_pair(a,b);
		cin>>a>>b;
		endd= make_pair(a,b);
		for(int i =0;i<t;i++)
		{
			int x;int y;
			cin>>x>>y;
			given.PB(make_pair(x,y));
		}
		vector<pair<int,int> >ans;
		ans.PB(start);
		vector<bool>visited(t);
		fill(visited.begin(),visited.end(),false);
		recurse(ans,visited);
		if(bt)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		given.erase(given.begin(),given.end());
		cin>>n;
	}
	return  0;
}