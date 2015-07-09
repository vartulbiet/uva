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
char arr[105][100];
bool visited[100][100];
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
int sum =0;
void call_func(int a,int b)
{
	if( a>=0 &&a<p &&b>=0 &&b<m && arr[a][b]=='W' && visited[a][b] == false )
	{
		visited[a][b] =true;
		sum++;
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
	int n =0;
	cin>>n;
	getchar();
		getchar();
	while(n>0)
	{
		int i =0;
		char s[100];
		//string s;
		
		while(gets(s) && s[0])
		{
			if(s[0]=='L' || s[0]=='W')
			{
			strcpy(arr[i],s);
			m =strlen(s);
			i++;
			}
			else
			{
			int a,b;
			p =i;
			sscanf(s,"%d%d",&a,&b);
			sum =0;
			init();
			call_func(a-1,b-1);
			cout<<sum<<endl;
			}
		}
		for(int i =0;i<p;i++)
		{
			for(int j =0;j<m;j++)
			{
				arr[i][j] = '0';
			}
		}
		m =0;p=0;
		if(n>1)
		cout<<endl;
		n--;
	}
	return 0;
}