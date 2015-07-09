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
int graph[105][105];
int w[105][105];


int max_length(int i,int j,int x,int y)
{
	if(w[i][j] != -1)
	return w[i][j];
	else
	{
		int a=0,b=0,c=0,d=0;
		if(i-1>=0 && graph[i][j]>graph[i-1][j])
			a = max_length(i-1,j,x,y)+1;
		if(i+1<x && graph[i][j]>graph[i+1][j])
			b = max_length(i+1,j,x,y)+1;
		if(j-1>=0 && graph[i][j]>graph[i][j-1])
			c = max_length(i,j-1,x,y)+1;
		if(j+1<y && graph[i][j]>graph[i][j+1])
			d = max_length(i,j+1,x,y)+1;
		return w[i][j] = max(a,max(b,max(c,d)));
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		string s;
		int x,y;
		cin>>s>>x>>y;
		memset(graph,0,sizeof(graph));
		memset(w,-1,sizeof(w));
		//memset(visited,false,sizeof(visited));
		for(int i =0;i<x;i++)
		{
			for(int j =0;j<y;j++)
			scanf("%d",&graph[i][j]);
		}
		int  length =0;
		for(int i =0 ;i<x;i++)
		{
			for(int j =0;j<y;j++)
			{
				length =max(length,max_length(i,j,x,y));
			}
		}
		cout<<s<<": "<<length+1<<endl;
	}
	return 0;
}