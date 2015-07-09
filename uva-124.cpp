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
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define pi 3.141592653589793
using namespace std;
int arr[101][101];
int a;

bool visited[101];
void init()
{
	for(int i =0;i<101;i++)
	{
		for(int j =0;j<101;j++)
		arr[i][j] = 0;
	}
}
void topo(int v,stack<int>&st)
{
	visited[v] = true;
	for(int j =0;j<a;j++)
	{
		if(arr[v][j]==1 && visited[j] == false)
		topo(j,st);
		for(int i =0;i<a;i++)
		{
		if(arr[v][i]==1 && visited[i] == false)
		topo(i,st);
		}
	}
	st.push(v);
}
void topological_sort()
{

	vector<stack<int> >vec;
	for(int j =0;j<a;j++)
	{
	stack<int>st;
	for(int i =0;i<101;i++)
	visited[i] = false;
	if(visited[j] ==  false)
		topo(j,st);
	for(int i =0;i<a;i++)
	{
		if(visited[i] ==  false)
		topo(i,st);
	}
	vec.push_back(st);
	while(!st.empty())
	{
		int z =st.top();
		st.pop();
		cout<<z+1<<" ";
	}
	cout<<endl;
	}
}
int main()
{
	int b;
	cin>>a>>b;
	while(a!=0 || b!=0)
	{
		init();
		for(int i =0;i<b;i++)
		{
			int x,y;
			cin>>x>>y;
			arr[x-1][y-1]=1;
		}
		topological_sort();
		cin>>a>>b;
	}
	return 0;
}