#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30
using namespace std;
int graph[105][105];
vector<int>arr;

int find_set(int x)
{
	if(x == arr[x])
	return x;
	else
	{
		return arr[x] = find_set(arr[x]);
	}
}

void merge(int a,int b)
{
	arr[find_set(a)] = find_set(b);
}

void kruskal(priority_queue<pair<int,pair<int,int> > >pq)
{
	vector<int >vec;
	while(!pq.empty())
	{
		pair<int,pair<int,int> >p = pq.top();
		if(find_set(p.second.first) != find_set(p.second.second))
		{
			merge(p.second.first,p.second.second);
		}
		else
		{
			vec.push_back(abs(p.first));
		}
		pq.pop();
	}
	if(vec.size()==0)
	{
		cout<<"forest"<<endl;
	}
	else
	{
	sort(vec.begin(),vec.end());
	for(int i =0;i<vec.size()-1;i++)
	cout<<vec[i]<<" ";
	cout<<vec[vec.size()-1];
	cout<<endl;
	}
}

int main()
{
	int a,b;
	cin>>a>>b;
	while(a>0 ||b>0)
	{
		for(int i =0;i<a;i++)
		arr.push_back(i);
		priority_queue<pair<int,pair<int,int> > >pq;
	//	vector<pair<int,pair<int,int> > >vec;
		for(int j =0;j<b;j++)
		{
			int m,n,p;
			cin>>m>>n>>p;
			//vec.push_back(make_pair(p,make_pair(m,n)));
			pq.push(make_pair(-p,make_pair(m,n)));
		}
		kruskal(pq);
		arr.erase(arr.begin(),arr.end());
		cin>>a>>b;
	}
	
   return 0;
}