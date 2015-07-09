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

void collation(vector<int>arr, int g)
{
	int table[arr.size()+1][10000+5];
	memset(table,0,sizeof(table));
	for(int i =0;i<arr.size()+1;i++)
		table[i][0] = 1;
	for(int k = 1;k <arr.size()+1;k++)
	{
		for(int j = 0;j<10005;j++)
		{
			table[k][j] = table[k-1][j];
			if((arr[k-1])<=j && table[k-1][(j-(arr[k-1]))] == 1)
			table[k][j] = 1;
		}
	}
	int min_required = 5001-g;
	//cout<<min_required<<endl;
	if(g>5001)
	cout<<"100.00"<<endl;
	else
	{
		for(int k = min_required;k<=10000;k++)
		{
			//cout<<"   "<<k<<endl;
			if(table[arr.size()][k] == 1)
			{
				//cout<<g<<"  "<<k<<endl;
				double i = g/(double)(g+k)*100;
				printf("%.2lf\n",i);
				break;
			}
		}
	}
}
int main()
{
	int m,n;
	cin>>m>>n;
	while(m || n)
	{
		n--;
		vector<int>arr;
		int set =0;
		for(int i =0;i<m;i++)
		{
			int r,s = 0;
			scanf("%d.%d",&r,&s);
			r = r*100+s;
			//cout<<r<<endl;
			if( i == n)
			set = r;
			else
			arr.PB(r);
		}
		collation(arr,set);
		cin>>m>>n;
	}
	return  0;
}