#include<iostream>
#include<queue>
#include<stdio.h>
#define INF 1<<30
using namespace std;
bool notTraversed(vector<int>x)
{
		for(int i=0;i<x.size();i++)
		{
				if(x[i]==0)
					return true;
		}
		return false;
}
int main()
{

	int count =0;
	cin>>count;
	while(count--)
	{
		int m,n =0;
		cin>>m>>n;
		int i,j,c =0;
		priority_queue<pair<int,pair<int,int> > >q;
		for(int k=0;k<n;k++)
		{
			cin>>i>>j>>c;
			pair< int,pair<int,int> >p;
			pair<int,int>x;
			x.first =i;
			x.second =j;
			p.first = c;
			p.second =x;
			q.push(p);
		}
		vector<int>visited(m);
		for(int i=0;i<m;i++)
			visited[i] =0;
		int ans =INF;
		while(notTraversed(visited))
		{
				pair< int,pair<int,int> >p;
				p =q.top();
				q.pop();
				pair<int,int>x;
				x= p.second;
				int capacity =p.first;
				if((visited[x.first]==0 || visited[x.second]==0) && x.first!=x.second)
				{
						if(ans>capacity)
							ans =capacity;
					visited[x.first] =1;
						visited[x.second] =1;
				}
		}
		cout<<"Case #"<<m+1<<": "<<ans<<endl;
	}
	return 0;
}