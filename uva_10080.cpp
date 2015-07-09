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
#define INF 1<<20
using namespace std;
double arr[105][105];
void init()
{
	for(int i =0;i<105;i++)
	{
		for(int j =0;j<105;j++)
		arr[i][j] =INF;
	} 
}
int n,m,s,v;
double dist(pair<double,double> a , pair<double,double>b)
{
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
bool do_matching(int *match, bool*seen,int j)
{
	for(int i =0;i<m;i++)
	{
		if(arr[j][i]<=v*s && !seen[i])
		{
			seen[i]= 1;
			if(match[i]<0 || do_matching(match,seen,match[i]))
			{
			match[i] = j;
			return true;
			}
		}
	}
	return false;
}
void maximum_matching()
{
	int match[105];
	memset(match,-1,sizeof(match));
	int result =0;
	for(int i =0;i<n;i++)
	{
		bool seen[105];
		memset(seen,0,sizeof(seen));
		
		if(do_matching(match,seen,i))
		result++;
	}
	cout<<n-result<<endl;
}
int main()
{
	while(scanf("%d%d%d%d",&n,&m,&s,&v)==4)
	{
		init();
		vector<pair<double,double> >a,b;
		for(int i =0;i<n;i++)
		{
			double p,q;
			cin>>p>>q;
			a.PB(make_pair(p,q));
		}
		for(int i =0;i<m;i++)
		{
			double p,q;
			cin>>p>>q;
			b.PB(make_pair(p,q));
		}
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<m;j++)
			arr[i][j] = dist(a[i],b[j]);
		}
		maximum_matching();
	}
	return 0;
}
