#include <cmath>
#include<list>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
vector<int>arr;

int find_set(int n)
{
	if(arr[n] == n)
	return n;
	else
	return arr[n] = find_set(arr[n]);
}

int merge_set(int m,int n)
{
	arr[find_set(m)] = find_set(n);
}

void kruskals(priority_queue<pair<int,pair<int,int> > >q)
{
	int sum =0;
	while(q.size()!=0)
	{
		if(find_set(q.top().second.first) !=find_set(q.top().second.second))
		{
			sum += abs(q.top().first);
			//cout<<q.top().second.first<<"  "<<q.top().second.second<<endl;
			merge_set(q.top().second.first,q.top().second.second);
		}
		q.pop();
	}
	cout<<sum<<endl;
}

int main()
{
	int n ;
	int x =0;
	while(scanf("%d",&n)==1)
	{
		if(x!=0)
		cout<<endl;
		x++;
		for(int i =0;i<n;i++)
		arr.push_back(i);
		int sum =0;
		for(int k =0;k<n-1;k++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			sum +=c;
		}
		cout<<sum<<endl;;
		priority_queue<pair<int,pair<int,int> > >q;
		int m =0;
		cin>>m;
		for(int i =0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			q.push(make_pair(-c,make_pair(a-1,b-1)));
		}
		int p =0;
		cin>>p;
		for(int i =0;i<p;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			q.push(make_pair(-c,make_pair(a-1,b-1)));
		}
		kruskals(q);
		arr.erase(arr.begin(),arr.end());
	}
	return 0;
}