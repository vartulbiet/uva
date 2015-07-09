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
#define INF 1<<20
using namespace std;
int arr[1005][1005];
bool visited[1005][1005];
int dist[1005][1005];
void init()
{
	for(int i =0;i<1005;i++)
	{
		for(int j =0;j<1005;j++)
		{
		arr[i][j] =1;visited[i][j] = false;dist[i][j] =0;
		}
	}
}
void BFS(int a,int b,int bc,int d,int r,int c)
{
	queue<pair<int,int> >q;
	q.push(make_pair(a,b));
	pair<int,int>rr =make_pair(bc,d);
	visited[a][b] = true;
	while(!q.empty())
	{
		if(q.front() == rr)
		break;

			pair<int,int>y =q.front();
			q.pop();
			if(y.first>=0 &&y.first<r && y.second-1>=0 && y.second-1<c && arr[y.first][y.second-1] !=INF  && visited[y.first][y.second-1]==false)
				{q.push(make_pair(y.first,y.second-1));visited[y.first][y.second-1] =true;dist[y.first][y.second-1]= dist[y.first][y.second]+1;}
			if(y.first>=0 &&y.first<r && y.second+1>=0 && y.second+1<c && arr[y.first][y.second+1] !=INF  && visited[y.first][y.second+1]==false)
				{q.push(make_pair(y.first,y.second+1));visited[y.first][y.second+1] =true;dist[y.first][y.second+1]= dist[y.first][y.second]+1;}
			if(y.first-1>=0 &&y.first-1<r && y.second>=0 && y.second<c && arr[y.first-1][y.second] !=INF && visited[y.first-1][y.second]==false)
				{q.push(make_pair(y.first-1,y.second));visited[y.first-1][y.second] =true;dist[y.first-1][y.second]= dist[y.first][y.second]+1;}
			if(y.first+1>=0 &&y.first+1<r && y.second>=0 && y.second<c && arr[y.first+1][y.second] !=INF  && visited[y.first+1][y.second]==false)
				{q.push(make_pair(y.first+1,y.second));visited[y.first+1][y.second] =true;dist[y.first+1][y.second]= dist[y.first][y.second]+1;}
		
	
	}
	cout<<dist[bc][d]<<endl;
}
int main()
{
	int r,c;
	while( scanf ("%d %d", &r, &c))
	{
		if(r==0 && c==0)
		break;
		init();
		int yy =0;
		cin>>yy;
		for(int i =0;i<yy;i++)
		{
			int h;
			cin>>h;
			int c =0;
			cin>>c;
			for(int i =0;i<c;i++)
			{
				int x =0;
				cin>>x;
				arr[h][x] =INF;
			}
		}
		int s1,s2,d1,d2;
			cin>>s1>>s2>>d1>>d2;
			BFS(s1,s2,d1,d2,r,c);
	}
	return 0;
}