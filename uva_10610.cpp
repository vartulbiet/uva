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
double dist(pair<double,double>x,pair<double,double>y)
{
	return sqrt((x.first-y.first)*(x.first-y.first) + (x.second - y.second)*(x.second-y.second));
}

bool check(double dist,int m,int n)
{
	if((dist) > m*60*n)
	return false;
	else
	return true;
}

int BFS(vector<pair<double,double> >vec,int m,int n)
{
	int *dis = (int*)malloc(sizeof(int)*(vec.size()));
	memset(dis,0,vec.size()*sizeof(int));
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		int out = q.front();
		q.pop();
		if(out == vec.size()-1)
		{
			return dis[out]-1;
		}
		else
		{
			for(int i =0;i<vec.size();i++)
			{
				if(i != out && i !=0 && dis[i] == 0 && check(dist(vec[i],vec[out]),m,n))
				{
					dis[i] = dis[out]+1;
					q.push(i);
				}
			}
		}
	}
	return -1;
}
char Buffer[1005];
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)==2 && m+n>0)
	{
		double x1,y1,x2,y2;
		vector<pair<double,double> >vec;
		cin>>x1>>y1>>x2>>y2;
		vec.PB(make_pair(x1,y1));
		double x,y;
		getchar();
		while(gets(Buffer)) 
		{
			if(strcmp(Buffer, " ") == 0 || strcmp(Buffer, "") == 0) break;
			sscanf(Buffer, "%lf %lf", &x, &y);
			vec.PB(make_pair(x,y));
		}
		vec.PB(make_pair(x2,y2));
		int ans = BFS(vec,m,n);
		if(ans != -1)
		cout<<"Yes, visiting "<<ans<<" other holes."<<endl;
		else
		cout<<"No."<<endl;
	}
	return 0;
}