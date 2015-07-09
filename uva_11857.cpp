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
int arr[1000001];
int find_set(int j)
{
	if(arr[j] ==j)
	return j;
	else
	return arr[j] = find_set(arr[j]);
}
void merge(int i,int j)
{
	arr[find_set(i)] = find_set(j);
}
void kruskal(priority_queue<pair<int,pair<int,int> > >pq,int m)
{
	vector<int>ans;
	int h =0;
	while(!pq.empty())
	{
		pair<int,pair<int,int> >pp  = pq.top();
		pq.pop();
		if(find_set(pp.second.second)!=find_set(pp.second.first))
		{
			merge(pp.second.second,pp.second.first);
			ans.PB(abs(pp.first));
			h = max(abs(pp.first),h);
		}
	}
	if(ans.size()==m-1)
	cout<<h<<endl;
	else
	cout<<"IMPOSSIBLE"<<endl;
}
int main()
{
	int m,n;
	cin>>m>>n;
	while(m!=0 || n!=0)
	{
		int t =0;
		priority_queue<pair<int,pair<int,int> > >pq;
		for(int i =0;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			t = max(t,max(x,y));
			pq.push(make_pair(-z,make_pair(x,y)));
		}
		for(int i =0;i<1000001;i++)
		arr[i] =i;
		kruskal(pq,m);
		cin>>m>>n;
	}
	return 0;
}