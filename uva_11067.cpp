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
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int graph[105][105];
int calculate(int i,int j,int m,int n)
{
	if(i==0 && j==0)
	return 1;
	
	if(graph[i][j] != 0)
		return graph[i][j];
	else
	{
		if(i-1>=0 && graph[i-1][j] != INF)
		graph[i][j] = calculate(i-1,j,m,n);
		if(j-1>=0 && graph[i][j-1] != INF)
		graph[i][j] += calculate(i,j-1,m,n);
	}
	return graph[i][j];
}
int main()
{
	int m,n;
	cin>>m>>n;
	while(m || n)
	{
		memset(graph,0,sizeof(graph));
		
		int v =0;
		cin>>v;
		for(int i =0;i<v;i++)
		{
			int x,y;
			cin>>x>>y;
			graph[x][y] = INF;
		}
		int y = calculate(m,n,m,n);
		if(y ==0 )
		cout<<"There is no path."<<endl;
		else if(y ==1)
		cout<<"There is one path from Little Red Riding Hood's house to her grandmother's house."<<endl;
		else
		cout<<"There are "<<y<<" paths from Little Red Riding Hood's house to her grandmother's house."<<endl;
		cin>>m>>n;
	}
	return 0;
}