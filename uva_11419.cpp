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
using namespace std;
int arr[1005][1005];
bool best_matched(vector<int >&match,vector<bool>&seen,int j,int x,int y)
{
	for(int i =0;i<y;i++)
	{
		if(arr[j][i] && !seen[i])
		{
			seen[i] = true;
			if(best_matched(match,seen,match[i],x,y) || match[i]<0 )
			{
				match[i] = j;
				return true;
			}
		}
	}
	return false;
}
void bipartite(int x,int y)
{
	vector<int>match(y);
	int ans =0;
	fill(match.begin(),match.end(),-1);
	for(int i =0;i<x;i++)
	{
		vector<bool>seen(y);
		fill(seen.begin(),seen.end(),false);
		if(best_matched(match,seen,i,x,y))
		ans++;
	}
	cout<<ans<<" ";
	for(int i =0;i<y;i++)
	{
		if(match[i]>=0)
		cout<<"r "<<i+1<<" ";
	}
	cout<<endl;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	while(a!=0 && b!=0 && c!=0)
	{
		memset(arr,0,sizeof(arr));
		for(int i =0;i<c;i++)
		{
			int x,y;
			cin>>x>>y;
			arr[x-1][y-1] = 1;
		}
		bipartite(a,b);
		cin>>a>>b>>c;
	}
	return 0;
}