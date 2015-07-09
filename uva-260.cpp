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
char arr[205][205];
bool visited[205][205];
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

bool call_func(int a,int b,char val)
{
	if((b==m-1 && arr[a][b]=='w'))
	{
		return true;
	}
	if( a>=0 && a<m && b>=0 && b<p && arr[a][b]==val && visited[a][b] == false )
	{
		visited[a][b] =true;
		return (call_func(a-1,b,val) || call_func(a-1,b-1,val) || call_func(a+1,b+1,val) || call_func(a+1,b,val) || call_func(a,b-1,val) || call_func(a,b+1,val));
	}
	else
	return false;
}

int main()
{
	int n =0;
	cin>>n;
	int u =1;
	while(n!=0)
	{
		m =n;
		p =n;
		getchar();
		char s[205];

		for(int i =0;i<m;i++)
		{
			gets(s);
			strcpy(arr[i],s);
		}
		
		bool k = true;
		for(int i =0;i<m;i++)
		{
			if(visited[i][0]==false && arr[i][0]=='w')
				{
					if (call_func(i,0,'w'))
					{
						k = false;
						break;
					}
				}
		}
		if(k)
		cout<<u++<<" B"<<endl;
		else
		cout<<u++<<" W"<<endl;
		init();
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<p;j++)
			{
				arr[i][j] = '-';
			}
		}
		cin>>n;
	}
	return 0;
}