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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<10
using namespace std;
void solve_knapsack(int m,int w,vector<pair<int,int> >yy)
{
	int n =  yy.size();
	int table[35][1005];
	char arr[35][1005];
	for(int i =0;i<=n;i++)
	{
		for(int j =0;j<=m;j++)
		{
		table[i][j] =0;arr[i][j]='0'; 
		}
	}
	vector<int>st;
	for(int i =1;i<=n;i++)
	{
		for(int j =1;j<=m;j++)
		{
			table[i][j] = table[i-1][j];
			arr[i][j] = 'U';
			if(yy[i-1].first<=j)
			{
				if(table[i][j-1] < yy[i-1].second + table[i-1][j-yy[i-1].first])
				{
					if(table[i][j]<yy[i-1].second + table[i-1][j-yy[i-1].first])
					{
						table[i][j] = yy[i-1].second + table[i-1][j-yy[i-1].first];
						arr[i][j] = 'C';
					}
				}
				else
				{
					if(table[i][j]<table[i][j-1] )
					{
						table[i][j] = table[i][j-1] ;
						arr[i][j] = 'L';
					}
				}
			}
		}
	}
	int p= n;
	int q= m;
	while(p>0 && q>0)
	{
		if(arr[p][q]=='C')
		{
			st.PB(p-1);
			q=q-yy[p-1].first;	p--;
		}
		else if(arr[p][q]=='L')
		{
			q--;
		}
		else if(arr[p][q]=='U')
		{
			p--;
		}
		else
		break;
	}
	
	cout<<table[n][m]<<endl;
	cout<<st.size()<<endl;;
	sort(st.begin(),st.end());
	for(int i =0;i<st.size();i++)
	{
		cout<<yy[st[i]].first/(3*w)<<" "<<yy[st[i]].second<<endl;
	}
}
int main()
{
	int m,w;int tc =0;
	while(scanf("%d%d",&m,&w)==2)
	{
		int x;
		cin>>x;
		if(tc!=0)
		cout<<endl;
		tc++;
		vector<pair<int,int> >yy;
		for(int i =0;i<x;i++)
		{
			int a,b;
			cin>>a>>b;
			a=3*w*a;
				yy.PB(make_pair(a,b));
		}
		//for(int i =0;i<yy.size();i++)
	//	cout<<yy[i].first/(3*w)<<" "<<yy[i].second<<endl;
			solve_knapsack(m,w,yy);
	}
	return 0;
}