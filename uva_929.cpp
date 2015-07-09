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
int crr[4]={-1,0,1,0};
int brr[4] ={0,1,0,-1};

void djkstra(vector< vector<int> >matrix,int x,int y,int m, int n)
{
	priority_queue<pair<int,pair<int,int> >,vector< pair<int,pair<int,int> > >,greater< pair<int,pair<int,int> > > > pq;
	pq.push(make_pair(matrix[x][y],make_pair(x,y)));

	vector< vector<int> >arr;
		for(int i =0;i<m;i++)
		{
		vector<int>g;
			for(int j =0;j<n;j++)
			g.PB(INF);
			arr.PB(g);
		}
		arr[x][y] = matrix[x][y];
	while(!pq.empty())
	{
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int c = pq.top().first;
		pq.pop();
		if(c == arr[a][b])
		for(int i =0;i<4;i++)
		{
			int new_a = a +crr[i];
			int new_b = b +brr[i];
			if(new_a>=0 &&new_b>=0 && new_a<m && new_b<n &&  arr[a][b]+ matrix[new_a][new_b]< arr[new_a][new_b])
			{
				arr[new_a][new_b] =arr[a][b]+ matrix[new_a][new_b];
				pq.push(make_pair(arr[new_a][new_b],make_pair(new_a,new_b)));
			}
		}
	}
	printf("%d\n",arr[m-1][n-1]);
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		vector< vector<int> >vec;
		for(int i =0;i<a;i++)
		{
			vector<int>f;
			for(int j =0;j<b;j++)
			{
				int y =0;
				cin>>y;
				f.PB(y);
			}
			vec.PB(f);
		}
		djkstra(vec,0,0,a,b);
	}
	return 0;
}