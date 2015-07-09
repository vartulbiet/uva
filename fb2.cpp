#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<math.h>
#include<cstdio>
#define INF 1<<20
#include<queue>
#include<algorithm>
using namespace std;
void update_queues(	priority_queue<pair<int,int> >&field_1,	priority_queue<pair<int,int> >&field_2)
{
	priority_queue<pair<int,int> >temp1;
	while(!field_1.empty())
	{
		temp1.push(make_pair(field_1.top().first+1,field_1.top().second));
		field_1.pop();
	}
	priority_queue<pair<int,int> >temp2;
	while(!field_2.empty())
	{
		temp2.push(make_pair(field_2.top().first+1,field_2.top().second));
		field_2.pop();
	}
	field_1= temp1;
	field_2 =temp2;
}
int main()
{
	int t =0;
	cin>>t; int kase =1;
	while(t>0)
	{
		int a,b,c;
		cin>>a>>b>>c;
		vector<pair<pair<int,int>,string> >vec;
		string x;
		for(int i =0;i<a;i++)
		{
			 int m,n;
			 getline(cin,x);
			cin>>x>>m>>n;
			vec.push_back(make_pair(make_pair(m,n),x));
		}
		sort(vec.begin(),vec.end());
		map<int,string>players;
		for(int i =0;i<a;i++)
		{
			players[i] = vec[a-1-i].second;
		}
		priority_queue< pair<int,int> >pq1;
		priority_queue< pair<int,int> >pq2;
		for(int i =0;i<a;i++)
		{
			if(i%2==0)
			pq1.push(make_pair(-0,-i));
			else
			pq2.push(make_pair(-0,-i));
		}
		priority_queue<pair<int,int> >field_1;
		priority_queue<pair<int,int> >field_2;
		for(int j =0;j<c;j++)
		{
			pair<int,int>pt = pq1.top();
			pq1.pop();
			//cout<<players[abs(pt.second)]<<endl;
			field_1.push(make_pair(abs(pt.first)+1,abs(pt.second)));	
			pt = pq2.top();
			pq2.pop();
			//cout<<"  "<<players[abs(pt.second)]<<endl;
			field_2.push(make_pair(abs(pt.first)+1,abs(pt.second)));	
		}
		for(int i =0;i<b;i++)
		{
			//for(int j =0;j<c;j++)
			//{
				if(!pq1.empty())
				{
				pair<int,int>field_pop = field_1.top();
				field_1.pop();
				pair<int,int>pt = pq1.top();
				pq1.pop();
				field_1.push(make_pair(abs(pt.first),abs(pt.second)));	
				pq1.push(make_pair(-field_pop.first,-field_pop.second));
				}
				
				if(!pq2.empty())
				{
				pair<int,int>field_pop = field_2.top();
				field_2.pop();
				pair<int,int>pt = pq2.top();
				pq2.pop();
				field_2.push(make_pair(abs(pt.first),abs(pt.second)));
				pq2.push(make_pair(-field_pop.first,-field_pop.second));
				}
			//}
			update_queues(field_1,field_2);
			
		}
		vector<string>ans;
		while(!field_1.empty())
		{
			pair<int,int>pt = field_1.top();
			field_1.pop();
			ans.push_back(players[pt.second]);
		}
		while(!field_2.empty())
		{
			pair<int,int>pt = field_2.top();
			field_2.pop();
			ans.push_back(players[pt.second]);
		}
		sort(ans.begin(),ans.end());
		cout<<"Case #"<<kase++<<":" ;
		for(int i =0;i<ans.size();i++)
		cout<<" "<<ans[i];
		cout<<endl;
		t--;
	}
	return 0;
}