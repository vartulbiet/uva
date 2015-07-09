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
void BFS(int s,int d,vector<int>arr)
{
	queue<int>q;
	q.push(s);
	map<int,bool>mymap;
	mymap[s] = true;
	bool bt = true;
	int hold[10000];
	for(int i =0;i<10000;i++)
	hold[i] = 0;
	while(!q.empty() && bt)
	{
		int z = q.front();
		q.pop();
		if(z == d)
		bt =false;
		for(int i =0;i<arr.size();i++)
		{
			int temp = z+arr[i];
			temp %=10000;
			if(mymap.find(temp ) ==mymap.end())
			{
				q.push(temp);
				mymap[temp ] = true;
				hold[temp ] = hold[z] +1;
				if(temp == d)
					bt = false;
			}
		}
	}
	if(bt)
	cout<<"Permanently Locked"<<endl;
	else
	{
		cout<<hold[d]<<endl;
	}
}
int main()
{
	int x,y,z;
	int tc =0;
	cin>>x>>y>>z;
	while(x || y || z)
	{
		vector<int>arr(z);
		for(int i =0;i<z;i++)
		cin>>arr[i];
		cout<<"Case "<<++tc<<": ";
		BFS(x,y,arr);
		cin>>x>>y>>z;
	}
	return 0;
}