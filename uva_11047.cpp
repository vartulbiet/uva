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
void floyd_warshall(int**table,int**source,int n)
{
	for(int k =0;k<n;k++)
	{
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				if(table[i][j]>table[i][k]+table[k][j])
				{
					source[i][j] = source[i][k];
					table[i][j] = table[i][k] + table[k][j];
				}
			}
		}
	}
}
int main()
{
	int c =0;
	cin>>c;
	while(c--)
	{
		int n =0;
		cin>>n;
		map<string,int>mymap;
		map<int,string>rev;
		for(int i =0;i<n;i++)
		{
			string s;
			cin>>s;
			mymap[s] =i;
			rev[i] = s; 
		}
			int **source = (int**)malloc(sizeof(int*)*n);
		for(int i =0;i<n;i++)
		source[i ] = (int*)malloc(sizeof(int)*n);
		int **table = (int**)malloc(sizeof(int*)*n);
		for(int i =0;i<n;i++)
		table[i ] = (int*)malloc(sizeof(int)*n);
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				int u =0;
				cin>>u;
				if(u ==-1)
				{
					table[i][j] = INF;
					source[i][j] = j;
				}
				else
				{
					table[i][j] = u;
					source[i][j] = j;
				}
			}
		}
		floyd_warshall(table,source,n);
		int r =0;
		cin>>r;
		while(r--)
		{
			string name,c1,c2;
			cin>>name>>c1>>c2;
			int cost = table[mymap[c1]][mymap[c2]];
			vector<string>path;
			path.PB(c1);
			if(cost == INF)
			{
				cout<<"Sorry Mr "<<name<<" you can not go from "<<c1<<" to "<<c2<<endl;
				continue;
			}
						cout<<"Mr "<<name<<" to go from "<<c1<<" to "<<c2<<", you will receive "<<cost<<" euros"<<endl;
cout<<"Path:";
			
			cout<<c1<<" ";
			for(c1 = rev[source[mymap[c1]][mymap[c2]]];c1 !=c2;c1 = rev[source[mymap[c1]][mymap[c2]]])
			cout<<c1<<" ";
			cout<<c2;
			cout<<endl;
		}
	}
	return 0;
}