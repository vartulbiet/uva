#include <vector>
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
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define INF 1<<30
using namespace std;
int a;
vector<int>arr;

int find_set(int a)
{
	if(arr[a] ==a)
	return a;
	else
	return arr[a] =find_set(arr[a]);
}

int merge(int x, int y)
{
	arr[find_set(x)] = find_set(y);
}

int kruskal(priority_queue< pair<int,pair<int,int> > >pq)
{
	double sum =0;
	int m =0;
	while(!pq.empty())
	{
		pair<double,pair<int,int> >p = pq.top();
		pair<int,int>q =p.second;
		//cout<<p.first;
		pq.pop();
		if(find_set(q.first)!=find_set(q.second))
		{
			sum +=(-p.first);
			merge(q.first,q.second);
			m++;
			//cout<<" yes";
		}
		//cout<<endl;
	}
	if(m==a-1)
	return sum;
	else
	return INF;
}
int kruskal1(priority_queue< pair<int,pair<int,int> > >pq,map<pair<int,pair<int,int> > ,bool>&mymap)
{
	double sum =0;
	int m =0;
	while(!pq.empty())
	{
		pair<double,pair<int,int> >p = pq.top();
		pair<int,int>q =p.second;
		//cout<<p.first;
		pq.pop();
		if(find_set(q.first)!=find_set(q.second))
		{
			sum +=(-p.first);
			merge(q.first,q.second);
			m++;
			mymap[p] = true;
			//cout<<" yes";
		}
		//cout<<endl;
	}
	if(m==a-1)
	return sum;
	else
	return INF;
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int b;
		cin>>a>>b;
		
		for(int i =0;i<a;i++)
		arr.push_back(i);

		priority_queue<pair<int,pair<int,int> > >pq;
		map<pair<int,pair<int,int> > ,bool>mymap;
		for(int i =0;i<b;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			pq.push(make_pair(-z,make_pair(x-1,y-1)));
			mymap[make_pair(-z,make_pair(x-1,y-1))]=false;
		}
		priority_queue<pair<int,pair<int,int> > >dq =pq;
		int r =kruskal1(pq,mymap);
		cout<<r<<" ";
		
		int nas =INF;int ppp =0;
		for(std::map<pair<int,pair<int,int> > ,bool>::iterator it =mymap.begin();it!=mymap.end();it++)
		{
			priority_queue<pair<int,pair<int,int> > >fuck;
			priority_queue<pair<int,pair<int,int> > >suck = dq;
			arr.erase(arr.begin(),arr.end());
			for(int h =0;h<a;h++)
				arr.push_back(h);
			int k =0;
			while(!suck.empty())
			{
				if((suck.top()==it->first && it->second == false) ||(suck.top()!=it->first))
				{
					fuck.push(suck.top());
				}
				suck.pop();
				k++;
			}
			int u =kruskal(fuck);
			//cout<<u<<"---"<<endl;
			if(u>r)
			{
				nas = min(nas,u);
			}
			if(u==r)
			ppp++;
			if(ppp>b-a+1)
			nas =r;
		}
		cout<<nas<<endl;
		arr.erase(arr.begin(),arr.end());
		n--;
	}
	return 0;
}