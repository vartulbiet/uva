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
int dep[105];
int len[105];
int calculate(int s,int n)
{
	if(len[s] != -1)
	return len[s];
	len[s] = 0;
	for(int j =0;j<n;j++)
	{
		if(graph[s][j] == 1)
			len[s] = max(len[s],1+calculate(j,n)); 
	}
	return len[s];
}
int main()
{
	int n =0;
	cin>>n;
	while(n)
	{
		memset(graph,0,sizeof(graph));
		memset(len,-1,sizeof(len));
		for(int i =0;i<n;i++)
		{
			int y =0;
			cin>>y;
			while(y--)
			{
				int j =0;
				cin>>j;
				graph[i][j-1] =1;
			}
		}
		int l=0;
		for(int i =0;i<n;i++)
		l =max(l,calculate(i,n));
		int ans=0;
		for(int i=0 ;i<n;i++)
		if(len[i]==l){
		ans = i;
		break;}
		cout<<ans+1<<endl;
		cin>>n;
	}
	return 0;
}