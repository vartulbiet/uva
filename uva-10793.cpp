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
int graph[101][101];
int n;
void init()
{
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
		if(i==j)
		graph[i][j] =0;
		else
		graph[i][j] = INF;
		}
	}
}
void get_print()
{
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		cout<<graph[i][j]<<" ";
	cout<<endl;
	}
}
void floyd_warshal()
{
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
				graph[j][k] = min(graph[j][k],graph[j][i]+graph[i][k]);
		}
	}
}
int main()
{
	int t =0;
	cin>>t;
	int kk =1;
	while(t>0)
	{
		int m;
		cin>>n>>m;
		init();
		for(int i =0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			//if(graph[a-1][b-1]==INF)
			//graph[a-1][b-1] = c;
			//if(a!=b && graph[a-1][b-1]!=INF)
			graph[a-1][b-1] = min(graph[a-1][b-1],c);
			graph[b-1][a-1] = graph[a-1][b-1];
		}
		floyd_warshal();
		//get_print();
		vector<int>ans;
		for(int i =5;i<n;i++)
		{
			bool tt =true;
			for(int k =0;k<4;k++)
			{
				if(graph[i][k] != graph[i][k+1] || graph[i][k]==INF)
					tt =false;
			}
			if(tt ==true)
			{
				ans.push_back(i);//cout<<i<<endl;
				}
		}
		
		
		int final_v =INF;
		for(int i =0;i<ans.size();i++)
		{
			int value = 0;
			for(int j =0;j<n;j++)
			value =max(graph[ans[i]][j],value);
			final_v= min(final_v,value);
		}
		if(final_v ==INF)
		cout<<"Map "<<kk++<<": "<<"-1"<<endl;
		else
		cout<<"Map "<<kk++<<": "<<final_v<<endl;
		
		t--;
	}
	return 0;
}