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
			//arr[i][j] = ' ';
			}
	}
}

void call_func(int a,int b)
{
	if( a>=0 && a<p && b>=0 && b<m && arr[a][b]!='1' && visited[a][b] == false )
	{
		visited[a][b] =true;
		call_func(a-1,b);
		call_func(a-1,b-1);
		call_func(a-1,b+1);
		call_func(a+1,b+1);
		call_func(a+1,b);
		call_func(a+1,b-1);
		call_func(a,b-1);
		call_func(a,b+1);
	}
	else
	{
		return;
	}
}
int main()
{
	int n =0;int k =1;
	while(scanf("%d",&n)==1)
	{
		char s[25];
		getchar();
		m=n;
		p=n;
		for(int i =0;i<n;i++)
		{
			gets(s);
			strcpy(arr[i],s);
		}
		
		int sum =0;
		
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				if(visited[i][j]==false && arr[i][j]=='1')
				{
					sum++;
					call_func(i,j);
				}
			}
		}
		cout<<"Image number "<<k++<<" contains "<<sum<<" war eagles."<<endl; 
		init();
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				arr[i][j] = '-';
			}
		}
	}
	return 0;
}