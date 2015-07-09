#include<iostream>
#include<vector>
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
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
void DP(vector<pair<int,ull> > vec,int count,int must)
{
	ull cost[count+1][count+1];
	ull times[count+1][count+1];
	memset(cost,0,sizeof(cost));
	memset(times,0,sizeof(times));
	for(int i =1;i<count+1;i++)
	{
		times[i][0] = 1;
	}
	times[0][0] =1;
	for(int i =1;i<count+1;i++)
	{
		for(int j =1;j<count+1;j++)
		{
			times[i][j] = times[i-1][j-1]+times[i-1][j];
			cost[i][j] = cost[i-1][j];
			if(times[i-1][j-1]>0)
			cost[i][j] += cost[i-1][j-1]+times[i-1][j-1]*vec[i-1].second ;
		}
	}
	ull total =0;ull costing =0;
	for(int k = must;k<count+1;k++)
	{
	total +=times[count][k];
	costing +=cost[count][k];
	}/*
	for(int i =0;i<count+1;i++)
	{
		for(int j =0;j<count+1;j++)
		{
			cout<<times[i][j]<<" ";
			//cost[i][j] = cost[i-1][j-1] + vec[i-1].second + cost[i-1][j];
		}
		cout<<endl;
	}
	for(int i =0;i<count+1;i++)
	{
		for(int j =0;j<count+1;j++)
		{
			cout<<cost[i][j]<<" ";
			//cost[i][j] = cost[i-1][j-1] + vec[i-1].second + cost[i-1][j];
		}
		cout<<endl;
	}
	cout<<total<<" "<<costing<<endl;*/
	double c = costing/(double)total;
	printf("%.9lf\n",c);
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		vector<pair<int,ull> >vec;
		for(int i =0;i<x;i++)
		{
			int a; ull b;
			cin>>a>>b;
			vec.PB(make_pair(a,b));
		}
		DP(vec,x,y);
	}
	return 0;
}