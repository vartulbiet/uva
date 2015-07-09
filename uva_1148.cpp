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
struct node
{
	int x;
	vector<int>g;
};
int ans;
void BFS(int s,int d,struct node*arr,int nodes)
{
	queue<int>q;
	q.push(s);
	int *dis = (int*)malloc(sizeof(int)*nodes);
	memset(dis,0,sizeof(dis)*nodes);
	while(!q.empty())
	{
		int front = q.front();
		int gg = dis[front];
		q.pop();
		if(front == d)
		{
			ans = gg;
			break;
		}
		vector<int>l = arr[front].g;
		for(int i=0;i<l.size();i++)
		{
			if(dis[l[i]] == 0 && l[i] != front)
			{
				dis[l[i]] = dis[front] + 1;
				q.push(l[i]);
			}
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int nodes =0;
		cin>>nodes;
		struct node*arr = (struct node*)malloc(sizeof(struct node)*nodes);
		for(int i =0;i<nodes;i++)
		{
			int a,b;
			cin>>a>>b;
			arr[a].x = a;
			vector<int>xx;
			while(b--)
			{
				int t =0;
				cin>>t;
				xx.PB(t);
			//	arr[t].g.PB(a);
			}
			arr[a].g =xx;
		}
		ans = 0;
		int source,dest;
		cin>>source>>dest;
		//DFS(source,dest,arr,nodes,0,visited);
		BFS(source,dest,arr,nodes);
		cout<<source<<" "<<dest<<" "<<ans-1<<endl;
		if (n)
      puts("");
	}
	return 0;
}