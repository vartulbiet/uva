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
	int h;
	char sex;
	string music;
	string  game;
};
int graph[505][505];
bool matching(bool*seen,int x,int n ,vector<int>&match)
{
	for(int i =0;i<n;i++)
	{
		if(graph[x][i] == 1 && seen[i] == false)
		{
			seen[i] =  true;
			if(match[i]<0 || matching(seen,match[i],n,match))
			{
			match[i] = x;
			return true;
			}
		}
	}
	return false;
}
void MBM(int n,int m,int t)
{

	vector<int>match(m);
	fill(match.begin(),match.end(),-1);
	int ans = 0 ;
	for(int j =0;j<n;j++)
	{
		bool seen[m];
		memset(seen,false,sizeof(seen));
		if(matching(seen,j,m,match))
			ans++;
	}

	cout<<t-ans<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int y =0;
		cin>>y;
		memset(graph,0,sizeof(graph));
		vector<struct node>vec,wom;
		for(int i =0;i<y;i++)
		{
			struct node z;
			cin>>z.h>>z.sex>>z.music>>z.game;
			if(z.sex == 'M')
			vec.PB(z);
			else
			wom.PB(z);
		}
		for(int i = 0;i<vec.size();i++)
		{
			for(int j = 0;j<wom.size();j++)
			{
				if(abs(vec[i].h-wom[j].h)<=40 && vec[i].sex != wom[j].sex && vec[i].music == wom[j].music && vec[i].game != wom[j].game)
				graph[i][j] = 1;
			
			}
	
		}
		MBM(vec.size(),wom.size(),y);
	}
	return 0;
}