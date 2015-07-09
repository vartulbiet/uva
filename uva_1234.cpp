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
#define MP make_pair
#define INF 1<<30
using namespace std;

vector<pair<int,pair<int,int> > >pq;
vector<int>arr;
int find(int x)
{
	if(x == arr[x])
	return x;
	else
	return arr[x] = find(arr[x]);
}
void merge(int x,int y)
{
	arr[find(x)] = find(arr[y]);
}
void KRUSKAL(int cost)
{
	sort(pq.begin(),pq.end());
	reverse(pq.begin(),pq.end());
	for(int i =0;i<pq.size();i++)
	{
		pair<int,pair<int,int> > p = pq[i];
		if(find(p.second.second) != find(p.second.first))
		{
			merge(p.second.second,p.second.first);
			cost -= p.first;
		}
	}
	cout<<cost<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		int cost =0;
		for(int i =0;i<=x;i++)
		arr.PB(i);
		for(int i =0;i<y;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			pq.PB(MP(c,MP(a-1,b-1)));
			cost +=c;
		}
		KRUSKAL(cost);
		arr.clear();
		pq.clear();
	}
	return 0;
}
