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
char arr[25][25];
bool visited[25][25];
int m,n;
void init()
{
			for(int i =0;i<25;i++)
		{
			for(int j =0;j<25;j++)
			visited[i][j]= false;
			}
}
int BFS(int p,int q,char ff)
{
	queue<pair<int,int> >r;
	r.push(make_pair(p,q));
	visited[p][q]=true;
	int ans =0;
	while(!r.empty())
	{
		pair<int,int>t =r.front();
		r.pop();ans++;
		int i = t.first;
		int j = t.second;
		if(i+1>=0 && i+1<m && j>=0 && j<n &&visited[i+1][j]==false && arr[i+1][j]==ff)
		{
			r.push(make_pair(i+1,j));visited[i+1][j] = true;
		}
		if(i-1>=0 && i-1<m && j>=0 && j<n &&visited[i-1][j]==false && arr[i-1][j]==ff)
		{r.push(make_pair(i-1,j));visited[i-1][j] = true;}
		if(i>=0 && i<m && j+1>=0 && j+1<n &&visited[i][j+1]==false && arr[i][j+1]==ff)
		{r.push(make_pair(i,j+1));visited[i][j+1] = true;}
		if(i>=0 && i<m && j-1>=0 && j-1<n &&visited[i][j-1]==false && arr[i][j-1]==ff)
		{r.push(make_pair(i,j-1));visited[i][j-1] = true;}
	}
	return ans;
}
int main()
{
	while(scanf("%d%d",&m,&n)==2)
	{
		for(int i =0;i<m;i++)
		scanf("%s",&arr[i]);
		int x,y;
		cin>>x>>y;
		char ff= arr[x][y];
		init();
		int f =BFS(x,y,ff);int temp =0;
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<n;j++)
			{
				if(visited[i][j]==false && arr[i][j]==ff)
				temp = max(temp,BFS(i,j,ff));
			}
		}
		cout<<temp<<endl;
	}
	return 0;
}