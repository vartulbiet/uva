#include <iostream>
#include <vector>
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
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
using namespace std;
int graph[201][201];
void init()
{
	for(int i =0;i<=200;i++)
	{
		for(int j =0;j<=200;j++)
		graph[i][j] =0; 
	}
}
int ans =0;
bool check(bool*visited,int last)
{
	for(int i =0;i<last;i++)
	if(visited[i]==false)
	return false;
	return true;
}
vector<int>llll;
void recurse(bool *arr,int k,int last,bool ret,bool *visited)
{
	if(check(visited,last))
	{
		int c =0;
		for(int i =0;i<last;i++)
		if(arr[i] ==false)
		c++;
		if(c>ans)
		{
			ans = c;
			llll.erase(llll.begin(),llll.end());
			for(int kk =0;kk<last;kk++)
			{
			if(arr[kk]== false)
			llll.PB(kk);
			}
		}
	}
	else
	{
		int next =0;visited[k] = true;
		for(int j =0;j<last;j++)
		{
			if(graph[k][j] == 1)
			{
				if(arr[j]==false)
				{
				arr[j]= !ret;
				}
				if(visited[j]==false)
				{
				recurse(arr,j,last,!arr[k],visited);
				}
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
		bool arr[201];
		init();
		ans =0;
	
		for(int i =0;i<b;i++)
		{
			int x,y;
			cin>>x>>y;
			graph[x-1][y-1]=1;
			graph[y-1][x-1] =1;
		}
		bool visited[201];
		for(int kk =0;kk<a;kk++)
		{
			for(int i =0;i<a;i++)
				visited[i] = false;
			for(int i =0;i<a;i++)
				arr[i] =false;
			recurse(arr,kk,a,false,visited);
		}
		cout<<ans<<endl;
		for(int uu=0;uu<llll.size();uu++){
		if(uu!=0)
		cout<<" ";
		cout<<llll[uu]+1;}
		cout<<endl;
		t--;
	}
	return 0;
}