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
#define INF 1<<20
using namespace std;
int arr[105][105];
void init()
{
	for(int i =0;i<105;i++)
	{
		for(int j =0;j<105;j++)
		arr[i][j] =1;
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		init();
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x =0;
		cin>>x;
		for(int i =0;i<x;i++)
		{
			int u,v;
			cin>>u>>v;
			arr[u][v] =0;
		}
		bool visited[105][105]={{false}};
		int graph[105][105] ={{0}};
		queue<pair<int,int> >q;
		q.push(make_pair(0,0));
		visited[0][0] = false;int a1=0,a2=0;
		while(!q.empty())
		{
				pair<int ,int >p = q.front();
				q.pop();
				int i =p.first;
				int j= p.second;
					if(i-c>=0 && i-c<a && j-d>=0 && j-d<b && arr[i-c][j-d]==1 && visited[i-c][j-d]==false)
					{
						graph[i][j]++;
						q.push(make_pair(i-c,j-d));
						visited[i-c][j-d] = true;
					}
					if(i+c>=0 && i+c<a && j-d>=0 && j-d<b && arr[i+c][j-d]==1&& visited[i+c][j-d]==false)
					{
						graph[i][j]++;
						q.push(make_pair(i+c,j-d));visited[i+c][j-d] = true;
					}
					if(i+c>=0 && i+c<a && j+d>=0 && j+d<b && arr[i+c][j+d]==1&& visited[i+c][j+d]==false)
					{
						graph[i][j]++;
						q.push(make_pair(i+c,j+d));visited[i+c][j+d] = true;
					}
					if(i-c>=0 && i-c<a && j+d>=0 && j+d<b && arr[i-c][j+d]==1&& visited[i-c][j+d]==false)
					{
						graph[i][j]++;
						q.push(make_pair(i-c,j+d));visited[i-c][j+d] = true;
					}
					if(i-d>=0 && i-d<a && j-c>=0 && j-c<b && arr[i-d][j-c]==1&& visited[i-d][j-c]==false)
					{
						graph[i][j]++;
						q.push(make_pair(i-d,j-c));visited[i-d][j-c] = true;
					}
					if(i+d>=0 && i+d<a && j+c>=0 && j+c<b && arr[i+d][j+c]==1&& visited[i+d][j+c]==false)
					{
						graph[i][j]++;
						q.push(make_pair(i+d,j+c));visited[i+d][j+c] = true;
					}
					if(i-d>=0 && i-d<a && j+c>=0 && j+c<b && arr[i-d][j+c]==1&& visited[i-d][j+c]==false)
					{
						graph[i][j]++;
						q.push(make_pair(i-d,j+c));visited[i-d][j+c] = true;
					}
					if(i+d>=0 && i+d<a && j-c>=0 && j-c<b && arr[i+d][j-c]==1&& visited[i+d][j-c]==false)
					{
						graph[i][j]++;
						q.push(make_pair(i+d,j-c));visited[i+d][j-c] = true;
					}
		}
		for(int i =0;i<a;i++)
	{
		for(int j =0;j<b;j++)
		if(graph[i][j]%2==0)
		a1++;
		else
		a2++;
	}
		cout<<a1<<" "<<a2<<endl;
		n--;
	}
	return 0;
}