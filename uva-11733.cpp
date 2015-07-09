#include <cmath>
#include<list>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int d;
int sum =0;
vector<int>arr;
int find_set(int n)
{
	if(arr[n] == n)
	return n;
	else
	{
		return arr[n] = find_set(arr[n]);
	}
}

void merge_set(int a,int b)
{
	arr[find_set(a)] = find_set(b);
}
int group_set()
{
	map<int,bool>mymap;
	mymap[find_set(0)] = true;
	for(int i =1;i<arr.size();i++)
	{
		if(mymap.find(find_set(i))==mymap.end())
		{
			mymap[find_set(i)] = true;
		}
	}
	return mymap.size();
}
void kruskals(priority_queue<pair<int,pair<int,int> > >q)
{
	int sum =0;
	while(q.size()!=0)
	{
		pair<int,pair<int,int> >p = q.top();
		q.pop();
		if(find_set(p.second.first)!= find_set(p.second.second) && (p.first>(-d)))
		{
			merge_set(p.second.first,p.second.second);
		//	cout<<p.second.first<<"  "<<p.second.second<<endl;
			sum +=abs(p.first);
		}
	}
	//cout<<sum;
	cout<<sum+group_set()*d<<" "<<group_set()<<endl;
}
int main()
{
	int x =0;
	cin>>x;
	int h =1;
	while(x>0)
	{
		int n,m ;
		cin>>n>>m>>d;
		for(int i =0;i<n;i++)
		arr.push_back(i);
		priority_queue<pair<int,pair<int,int> > >q;
		for(int i =0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			q.push(make_pair(-c,make_pair(a-1,b-1)));
		}
		cout<<"Case #"<<h++<<": ";
		kruskals(q);
		arr.erase(arr.begin(),arr.end());
		sum =0;
		x--;
	}
	return  0;
}