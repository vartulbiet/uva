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
using namespace std;
int a;
vector<int>arr;
double distance_d(pair<int,int>x,pair<int,int>y)
{
	return sqrt((x.first-y.first)*(x.first-y.first) +(x.second-y.second)*(x.second-y.second));
}

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

void kruskal(priority_queue< pair<double,pair<int,int> > >pq)
{
	double sum =0;
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
			//cout<<" yes";
		}
		//cout<<endl;
	}
	printf("%.2lf\n",sum);
}

int main()
{
	while(scanf("%d",&a)==1)
	{
		for(int i =0;i<a;i++)
		arr.push_back(i);
		
		vector<pair<int,int> >cood;
		
		for(int i =0;i<a;i++)
		{
			int x,y;
			cin>>x>>y;
			cood.push_back(make_pair(x,y));
		}
		
		priority_queue<pair<double,pair<int,int> > >pq;
		
		for(int i =0;i<cood.size();i++)
		{
			for(int j =i+1;j<cood.size();j++)
			pq.push(make_pair(-distance_d(cood[i],cood[j]),make_pair(i,j)));
		}
		int t =0;
		cin>>t;
		for(int i =0;i<t;i++)
		{
			int x,y;
			cin>>x>>y;
			merge(x-1,y-1);
		}
		kruskal(pq);
		arr.erase(arr.begin(),arr.end());
	}
	return 0;
}