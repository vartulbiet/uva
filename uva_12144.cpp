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
#define INF 1<<20
#define MP make_pair
#define ii pair<int,int>
using namespace std;
int arr[500+5][500+5];
bool visited[500+5][500+5];
void init()
{
	for(int i =0;i<505;i++)
	{
		for(int j =0;j<505;j++){
		arr[i][j] = INF;visited[i][j]=false;}
		arr[i][i] =0;
	}
}

int Djkstra(int n,int s,int d)
{
	vector<int>nodes(n);
	priority_queue< pair<int,int> >pq;
	vector<int>parent(n);	
	for(int i =0;i<n;i++){
	nodes[i] = INF;parent[i] =-1;}
	nodes[s] = 0;
	for(int i =0;i<n;i++)
	{
		pq.push(MP(-nodes[i],i));
	}
	bool bt =false;
	while(!pq.empty())
	{
		pair<int,int> elem = pq.top();
		//cout<<elem.second<<n<<endl;
		pq.pop();
		if(elem.second == d) 
		{
		bt =true;
		break;
		}
		for(int i =0;i<n;i++)
		{
			if(arr[elem.second][i] !=INF &&nodes[i] > (nodes[elem.second] + arr[elem.second][i]) && visited[elem.second][i] == false)
			{
				nodes[i] = nodes[elem.second]+arr[elem.second][i];
				pq.push(MP(-nodes[i],i));
				parent[i] = elem.second;
			}
		}
	}
	int x =d;
	int y =s;
	while(x!=y && bt && parent[x] !=-1)
	{
			
		visited[parent[x]][x] =true;
		//cout<<x<<" ";
		x= parent[x]; 
	}
	int ans;
	if(bt && nodes[d] != INF)
	ans = nodes[d];
	else
	ans = -1;
	return ans;
}

int main()
{
	int m,n;
	cin>>m>>n;
	while(m||n)
	{
		int s,d;
		cin>>s>>d;
		init();
		for(int i =0;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			arr[x][y] = z;
		}
		int u = Djkstra(m,s,d);
		int v = Djkstra(m,s,d);
		while(u==v)
		{
			v= Djkstra(m,s,d);
		}
		cout<<v<<endl;
		cin>>m>>n;
	}
	return 0;
}