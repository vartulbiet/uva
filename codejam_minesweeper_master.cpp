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
#include<assert.h>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<10
#define MP(x,y) make_pair(x,y)
using namespace std;
bool bt;
int arr[10][10];
bool visited[10][10];
void init(queue<pair<int,int> >&q,int i,int j)
{
	if(visited[i][j])
	return;
	if(arr[i][j]!=INF)
		q.push(MP(i,j));
	visited[i][j] =true;
}
void BFS_util(int x,int y,int R,int C)
{
	queue<pair<int,int> >q;
	q.push(MP(x,y));
	memset(visited,false,sizeof(visited));
	visited[x][y] = false;
	//cout<<R;
	while(!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
	if(i-1>=0 && j-1>=0)
		init(q,i-1,j-1);
	if(i-1>=0 && arr[i-1][j]!=INF)
		init(q,i-1,j);
	if(i-1>=0 && j+1<C && arr[i-1][j+1]!=INF)
		init(q,i-1,j+1);
	if(j-1>=0 && arr[i][j-1]!=INF)
		init(q,i,j-1);
	if(j+1<C && arr[i][j+1]!=INF)
		init(q,i,j+1);
	if(i+1<R && j-1>=0 && arr[i+1][j-1]!=INF)
		init(q,i+1,j-1);
	if(i+1<R && arr[i+1][j]!=INF)
		init(q,i+1,j);
	if(i+1<R && j+1<C && arr[i+1][j+1]!=INF)
		init(q,i+1,j+1);
	}
	bool ct =true;
	for(int i = 0;i<R &&ct;i++)
	{
		for(int j =0;j<C &&ct;j++)
		if(visited[i][j] == false)
		ct =false;
	}
	if(ct)
	bt =false;
}
void BFS(int R,int C)
{
	
	for(int i= 0;i<R && bt;i++)
	{
		for(int j =0;j<C && bt;j++)
		{
			BFS_util(i,j,R,C);
		}
	}
	
}
void upgrade(int R,int C,int i,int j)
{
	if(i-1>=0 && j-1>=0 && arr[i-1][j-1]!=INF)
		arr[i-1][j-1]++;
	if(i-1>=0 && arr[i-1][j]!=INF)
		arr[i-1][j]++;
	if(i-1>=0 && j+1<C && arr[i-1][j+1]!=INF)
		arr[i-1][j+1]++;
	if(j-1>=0 && arr[i][j-1]!=INF)
		arr[i][j-1]++;
	if(j+1<C && arr[i][j+1]!=INF)
		arr[i][j+1]++;
	if(i+1<R && j-1>=0 && arr[i+1][j-1]!=INF)
		arr[i+1][j-1]++;
	if(i+1<R && arr[i+1][j]!=INF)
		arr[i+1][j]++;
	if(i+1<R && j+1<C && arr[i+1][j+1]!=INF)
		arr[i+1][j+1]++;
}
void degrade(int R,int C,int i,int j)
{
	if(i-1>=0 && j-1>=0 && arr[i-1][j-1]!=INF)
		arr[i-1][j-1]--;
	if(i-1>=0 && arr[i-1][j]!=INF)
		arr[i-1][j]--;
	if(i-1>=0 && j+1<C && arr[i-1][j+1]!=INF)
		arr[i-1][j+1]--;
	if(j-1>=0 && arr[i][j-1]!=INF)
		arr[i][j-1]--;
	if(j+1<C && arr[i][j+1]!=INF)
		arr[i][j+1]--;
	if(i+1<R && j-1>=0 && arr[i+1][j-1]!=INF)
		arr[i+1][j-1]--;
	if(i+1<R && arr[i+1][j]!=INF)
		arr[i+1][j]--;
	if(i+1<R && j+1<C && arr[i+1][j+1]!=INF)
		arr[i+1][j+1]--;
}
void call(int R,int C,int k)
{
	if(k == 0 && bt)
	{
		BFS(R,C);
	}
	else if(bt && k>0)
	{
		for(int i =0;i<R && bt;i++)
			{
				for(int j =0;j<C && bt;j++)
				{
					if(arr[i][j] != INF)
					{
						int temp= arr[i][j];
						arr[i][j] = INF;
						upgrade(R,C,i,j);
						call(R,C,k-1);
						degrade(R,C,i,j);
						arr[i][j] = temp;
					}
				}
			}
	}
	else
	return;
}

int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int R,C,M;
		bt =true;
		cin>>R>>C>>M;
		cout<<R<<C<<M;
		memset(arr,0,sizeof(arr));
		call(R,C,M);
		if(bt)
		cout<<"Impossible"<<endl;
		else
		cout<<"Possible"<<endl;
	}
	return 0;
}