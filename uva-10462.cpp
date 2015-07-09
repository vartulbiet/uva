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
int arr[500];int uu[500];
	vector<pair<int,pair<int,int> > >all;
	int set_ind(pair<int,pair<int,int> >pp)
	{
		for(int i =0;i<all.size();i++)
		if(pp==all[i])
		return i;
		return -1;
	}
int find_set(int a)
{
	if(arr[a] ==a)
	return a;
	else
	return arr[a] = find_set(arr[a]);
}
void merge(int a,int b)
{
	arr[find_set(a)] = arr[find_set(b)];
}
int bb=1;
int kruskal(priority_queue<pair<int,pair<int,int> > >pq,int a)
{
	int sum =0;
		for(int i =0;i<=a;i++)
		arr[i]= i;
		int sz =0;
	while(!pq.empty())
	{
		pair<int,pair<int,int> >pp = pq.top();
		if(find_set(pp.second.first)!=find_set(pp.second.second))
		{
			sum =sum-pp.first;sz++;
			merge(pp.second.first,pp.second.second);
			if(bb==1)
			uu[set_ind(pp)]=1;
		}
		pq.pop();
	}
	bb++;
	if(sz==a-1)
	return sum;
	else
	return INF;
}

priority_queue<pair<int,pair<int,int> > > vectoq(vector<pair<int,pair<int,int> > >all,int t)
{
	priority_queue<pair<int,pair<int,int> > >pq;
	for(int i =0;i<all.size();i++)
	if(i!=t)
	pq.push(all[i]);
	return pq;
}

int main()
{
	int t =0;
	cin>>t;int gg =1;
	while(t>0)
	{
		int a,b;
		cin>>a>>b;
		priority_queue<pair<int,pair<int,int> > >pq;
		for(int i =0;i<b;i++)
		uu[i]= 0;
		for(int i =0;i<b;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			all.PB(make_pair(-z,make_pair(x,y)));
		}
		int y =0;
		y =kruskal(vectoq(all,-1),a);
		//cout<<y<<" ";
		int x =INF;
		
		for(int i =0;i<b;i++)
		{
			if(uu[i]==1)
			{
				int u =(kruskal(vectoq(all,i),a));
				//cout<<u<<" ";
				x = min(x,u);
			}
		}
all.erase(all.begin(),all.end());
bb=1;
		cout<<"Case #"<<gg++<<" : ";
		if(x!=INF && y!=INF)
		cout<<x<<endl;
		else if(x==INF && y==INF)
		cout<<"No way"<<endl;
		else
		cout<<"No second way"<<endl;
		t--;
	}
	return 0;
}