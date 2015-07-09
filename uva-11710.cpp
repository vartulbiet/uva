#include <cmath>
#include<list>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
string f;
map<string,int >mymap;
vector<int>vec;
int n =0;
int find_set(int x)
{
	if(vec[x] == x)
		return x;
		else
		{
		return vec[x]=find_set(vec[x]); 
		}
}

void merge_set(int a,int b)
{
	vec[find_set(a)] = find_set(b);
}


void kruskals(priority_queue<pair<int,pair<string,string> > >q)
{
	int sum =0;
	int t =0;
	while(!q.empty())
	{
		pair<int,pair<string,string> > p = q.top();
		q.pop();
		pair<string,string>x = p.second;
		if(find_set(mymap[x.first])!=find_set(mymap[x.second]))
		{
			merge_set(mymap[x.first],mymap[x.second]);
			sum += abs(p.first);
			t++;
		}
	}
	if(t != n-1)
	cout<<"Impossible"<<endl;
	else
	cout<<sum<<endl;
}
int main()
{
	int m;
	cin>>n>>m;
	while(n!=0 || m!=0)
	{
		for(int i =0;i<n;i++)
		{
			string s;
			cin>>s;
			mymap[s] = i;
		}
		for(int i =0;i<n;i++)
		vec.push_back(i);
		priority_queue<pair<int ,pair<string,string> > >q;
		for(int i =0;i<m;i++)
		{
			string a,b;
			int c;
			cin>>a>>b>>c;
			q.push(make_pair(-c,make_pair(a,b)));
		}
		cin>>f;
		kruskals(q);
		vec.erase(vec.begin(),vec.end());
		mymap.erase(mymap.begin(),mymap.end());
		cin>>n>>m;
	}
	return 0;
}