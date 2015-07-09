#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
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
char arr[50][50];
bool visited[50][50];
int m,p;

void init()
{
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<p;j++)
		{
			visited[i][j] = false;
		}
	}
}
int sum =0;
void call_func(int a,int b,char val)
{
	if( a>=0 && a<m && b>=0 && b<p && arr[a][b]==val && visited[a][b] == false )
	{
		sum++;
		visited[a][b] =true;
		call_func(a-1,b,val);
		//call_func(a-1,b-1,val);
	//	call_func(a-1,b+1,val);
		//call_func(a+1,b+1,val);
		call_func(a+1,b,val);
		//call_func(a+1,b-1,val);
		call_func(a,b-1,val);
		call_func(a,b+1,val);
	}
	else
	{
		return;
	}
}
bool comf(pair<int,char>x,pair<int,char>y)
{
	if(x.first>y.first)
	return true;
	else if(x.first==y.first)
	{
		if(x.second<y.second)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main()
{
	int k =1;
	cin>>m>>p;
	while(m!=0 && p!=0)
	{
		char s[50];
		getchar();

		for(int i =0;i<m;i++)
		{
			gets(s);
			strcpy(arr[i],s);
		}
		vector<pair<int,char> >f;
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<p;j++)
			{
				if(visited[i][j]==false && arr[i][j]!='.')
				{
					call_func(i,j,arr[i][j]);
					f.push_back(make_pair(sum,arr[i][j]));
					sum =0;
				}
			}
		}
		cout<<"Problem "<<k++<<":"<<endl;
		sort(f.begin(),f.end(),comf);
		for(int k =0;k<f.size();k++)
		{
			cout<<f[k].second<<" "<<f[k].first<<endl;
		}
		init();
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<p;j++)
			{
				arr[i][j] = '-';
			}
		}
		cin>>m>>p;
	}
	return 0;
}