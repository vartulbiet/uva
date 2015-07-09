#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
char graph[25][25];
bool visited[25][25];
int m,n;
char toFind;
void init()
{
	for(int i =0;i<25;i++)
		for(int j =0;j<25;j++)
		{
			graph[i][j] = '-';
			visited[i][j] = false;
		}
}
ii check(int x,int y)
{
	int a =x;
	int b =y;
	if(x<0)
	a =  m-1;
	if(x>=m)
	a = 0;
	if(y<0)
	b =  n-1;
	if(y>=n)
	b = 0;
	return MP(a,b);
}

int BFS(int x,int y)
{
	int ans = 1;
	queue< ii >q;
	q.push(MP(x,y));
	visited[x][y] = true;
	while(!q.empty())
	{
		ii pp= q.front();
		q.pop();
		int r,s;
		ii u = check(pp.first-1,pp.second);
		if(visited[u.first][u.second] == false && graph[u.first][u.second] == toFind )
		{
			q.push(MP(u.first,u.second));
			ans++;
			visited[u.first][u.second] = true;
		}
		u = check(pp.first+1,pp.second);
		if(visited[u.first][u.second] == false && graph[u.first][u.second] == toFind )
		{
			q.push(MP(u.first,u.second));
			ans++;
			visited[u.first][u.second] = true;
		}
		u = check(pp.first,pp.second+1);
		if( visited[u.first][u.second] == false && graph[u.first][u.second] == toFind )
		{
			q.push(MP(u.first,u.second));
			ans++;
			visited[u.first][u.second] = true;
		}
		u = check(pp.first,pp.second-1);
		if(visited[u.first][u.second] == false && graph[u.first][u.second] == toFind )
		{
			q.push(MP(u.first,u.second));
			ans++;
			visited[u.first][u.second] = true;
		}
	}
	return ans;
}
int main()
{
	while(scanf("%d%d",&m,&n) == 2)
	{
		init();
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<n;j++)
			{
			cin>>graph[i][j];
			}
		}
		int x,y;
		cin>>x>>y;
		int ans = 0;
		toFind = graph[x][y];
		int t = BFS(x,y);
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<n;j++)
			{
				if(graph[i][j] == toFind && visited[i][j] == false)
				ans = max(ans,BFS(i,j));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}