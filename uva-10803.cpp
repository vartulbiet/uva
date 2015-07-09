#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<map>
#include<list>
#include<queue>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(long long)
#define FEL(i,a,b) for(long long i=a;i<b;i++)
#define INF 1<<30
using namespace std;
#define N 1025
double d[N][N];
int n;
void init()
{
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		d[i][j] = INF;
	}
}
double getmax()
{
	double ans =0;
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
			ans = max(d[i][j],ans);
	}
	return ans;
}
void floyd_warshall()
{
	for(int i =0;i< n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
				d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
}
double distancet(pair<int,int>x,pair<int,int>y)
{
	return sqrt(double((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second)));
}
int main()
{
	int x =0;
	cin>>x;
	int u =1;
	while(x>0)
	{
		//int n=0;
		cin>>n;
		init();
		vector<pair<int,int> >dist;
		for(int j =0;j<n;j++)
		{
			int a,b=0;
			cin>>a>>b;
			dist.push_back(make_pair(a,b));
		}
		for(int i =0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
			double f = distancet(dist[i],dist[j]);
			if(f<=10)
			d[i][j] = f;
			}
		}
		floyd_warshall();
		double ans =getmax();
		//double gg = fabs(ans*1e4 - floor(ans*1e4) - 0.5) > 1e-2;
		cout<<"Case #"<<u++<<":"<<endl;
		if(ans == INF)
		cout<<"Send Kurdy"<<endl;
		else
		printf("%.4f\n",ans);
		cout<<endl;
		x--;
	}
	return 0;
}