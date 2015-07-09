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
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;

int BFS(int**graph,int s,int d,int x)
{
	queue<int>q;
	q.push(s);
	vector<int>arr;
	for(int i =0;i<x;i++)
		arr.PB(INF);
	arr[s] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i =0;i<x;i++)
		{
			if(graph[u][i] == 1 && u!=i && (arr[i]>arr[u]+1))
			{
				arr[i] = arr[u]+1;
				q.push(i);
			}
		}
	}
	return arr[d];
}

int main()
{
	int n =0;
	cin>>n;
	cout<<"SHIPPING ROUTES OUTPUT"<<endl;int tc =1;
	cout<<endl;
	while(n--)
	{
		cout<<"DATA SET  "<<tc++<<endl;
		int x,y,z;
		cin>>x>>y>>z;
		//cout<<x<<y<<z;
		map<string,int>mymap;
		int**graph= (int**)malloc(sizeof(int*)*x);
		for(int i =0;i<x;i++)
			graph[i] = (int*)malloc(sizeof(int)*x);
		for(int i =0;i<x;i++)
			for(int j =0;j<x;j++)
				graph[i][j] =0;
		for(int i =0;i<x;i++)
		{
			string a;
			cin>>a;
			//cout<<a<<" ";
			mymap[a] = i;
		}
		cout<<endl;
		for(int i =0;i<y;i++)
		{
			string a,b;
			cin>>a>>b;//cout<<a<<b<<endl;
			graph[mymap[a]][mymap[b]] = 1;
			graph[mymap[b]][mymap[a]] = 1;
		}
		for(int i =0;i<z;i++)
		{
			int aa;
			string a,b;
			cin>>aa>>a>>b;
			//cout<<aa<<a<<b<<endl;
			int r = BFS(graph,mymap[a],mymap[b],x);
			if(r == INF )
				cout<<"NO SHIPMENT POSSIBLE"<<endl;
			else
				cout<<"$"<<r*aa*100<<endl;
		}
		cout<<endl;
 	}
 	cout<<"END OF OUTPUT"<<endl;
 	return 0;
}