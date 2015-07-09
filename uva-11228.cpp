#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<queue>
#include <algorithm>
#include<map>
using namespace std;
map<pair<int,int>,int>mymap;
vector<int>vec;
int a,b;
int find_set(int x)
{
	if(vec[x]==x)
	return x;
	else
	return vec[x] = find_set(vec[x]);
}
void merge_set(int a,int b)
{
	vec[find_set(a)] =find_set(b);
}
double dist(pair<int,int>x,pair<int,int>y)
{
	return sqrt(double((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second)));
}
void kruskals(priority_queue<pair<double,pair<int,int> > >q)
{
	double sum1 =0;
	double sum2 =0;
	int pp=1;
	while(!q.empty())
	{
		pair<double,pair<int,int> >p =q.top();q.pop();
	//	cout<<p.first<<" ";
		pair<int,int>x =p.second;
		if(find_set(x.first)!=find_set(x.second))
		{
			merge_set(x.first,x.second);
			if(p.first>=-b)
			{
			sum1 +=abs(p.first);}
			else
			{sum2 +=abs(p.first);pp++;}
			//cout<<x.first<<"--"<<x.second<<endl;
		}
	}
	cout<<pp<<" "<<floor(sum1+0.5)<<" "<<floor(sum2+0.5)<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	int k =1;
	while(n>0)
	{
		cin>>a>>b;
		vector<pair<int,int> >arr;
		for(int i =0;i<a;i++)
		{
			int x,y;
			cin>>x>>y;
			arr.push_back(make_pair(x,y));
			mymap[make_pair(x,y)] = i;
		}
		for(int i =0;i<a;i++)
		vec.push_back(i);
		priority_queue<pair<double,pair<int,int> > >q;
		for(int i =0;i<a;i++)
		{
			for(int j =i+1;j<a;j++)
			{
				q.push(make_pair(-dist(arr[i],arr[j]),make_pair(mymap[arr[i]],mymap[arr[j]])));
			}
		}
		cout<<"Case #"<<k++<<": ";
		kruskals(q);
		mymap.erase(mymap.begin(),mymap.end());
		vec.erase(vec.begin(),vec.end());
		n--;
	}
	return 0;
}