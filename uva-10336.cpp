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
char arr[10000][10000];
bool visited[10000][10000];
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

void call_func(int a,int b,char val)
{
	if( a>=0 && a<m && b>=0 && b<p && arr[a][b]==val && visited[a][b] == false )
	{
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
	if(x.second>y.second)
	return true;
	else if(x.second==y.second)
	{
		if(x.first<y.first)
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
	int n =0;
	cin>>n;
	while(n>0)
	{
	scanf("%d%d",&m,&p);
		getchar();
		char s[10000];

		for(int i =0;i<m;i++)
		{
			gets(s);
			strcpy(arr[i],s);
		}
		map<char,int>hold;
		
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<p;j++)
			{
				if(visited[i][j]==false && arr[i][j]!='.')
				{
					call_func(i,j,arr[i][j]);
					hold[arr[i][j]] ++;
				}
			}
		}
		
		vector< pair<char,int>  >f;
		
		for(std::map<char,int>::iterator it= hold.begin();it!=hold.end();it++)
		{
			if(it->second>0 && it->first>='a' && it->first<='z')
			{
			f.push_back(make_pair(it->first,it->second));
			}
		}
		cout<<"World #"<<k++<<endl;
		
		sort(f.begin(),f.end(),comf);
		for(int k =0;k<f.size();k++)
		{
			cout<<f[k].first<<": "<<f[k].second<<endl;
		}
		init();
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<p;j++)
			{
				arr[i][j] = '-';
			}
		}
		n--;
	}
	return 0;
}