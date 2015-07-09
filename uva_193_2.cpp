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
int graph[105][105];
int ans =0;
bool visited[105];
char arr[105];
vector<int>llll;

void init()
{
	for(int i =0;i<=104;i++)
	{
		for(int j =0;j<=104;j++)
		graph[i][j] =0; 
	}
}

bool check(int last)
{
	for(int i =0;i<last;i++)
	if(visited[i]==false)
	return false;
	return true;
}

void recurse(int k,int last)
{
	if(check(last))
	{
		int c =0;
		for(int i =0;i<last;i++)
		if(arr[i] =='b')
		c++;
		if(c>ans)
		{
			ans = c;
			llll.erase(llll.begin(),llll.end());
			for(int kk =0;kk<last;kk++)
			{
			if(arr[kk]== 'b')
			llll.PB(kk);
			}
		}
	}
	else
	{
		int next =0;visited[k] =true;
		for(int j =0;j<last;j++)
		{
			if(graph[k][j] == 1 && arr[j]=='b' && arr[k]=='b')
			{
				arr[j]= 'a';
			}
		}
		for(int j =0;j<last;j++)
		{
			if(graph[k][j] == 1)
			{
				recurse(j,last);
			}
		}
	}
}
int main()
{
	int t =0;
	cin>>t;
	while(t>0)
	{
		int a,b;
		cin>>a>>b;
		init();
		ans =0;
		for(int i =0;i<b;i++)
		{
			int x,y;
			cin>>x>>y;
			graph[x-1][y-1]=1;
			graph[y-1][x-1] =1;
		}
		for(int kk =0;kk<a;kk++)
		{
			for(int i =0;i<a;i++)
				visited[i] = false;
			for(int i =0;i<a;i++)
				arr[i] ='b';
			recurse(kk,a);
		}
		cout<<ans<<endl;
		for(int uu=0;uu<llll.size();uu++)
		{
			if(uu!=0)
				cout<<" ";
			cout<<llll[uu]+1;
		}
		cout<<endl;
		t--;
	}
	return 0;
}