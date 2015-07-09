#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<map>
#include<list>
#include<queue>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(long long)
#define FEL(i,a,b) for(long long i=a;i<b;i++)
#define INF 1<<30
using namespace std;
#define V 5
int graph[V][V]  = {
					0,5,0,35,0,
					5,0,10,30,0,
					0,10,0,25,15,
					35,30,25,0,20,
					0,0,15,20,0
					};
void getMST()
{
	int arr[V];
	for(int i =0;i<V;i++)
		arr[i] = INF;
	arr[0] = 0;
	vector< pair<int,int> >q;
	for(int i =0;i<V;i++)
	q.push_back(make_pair(arr[i],i));
	sort(q.begin(),q.end());
	while(q.empty())
	{
		int u = q.front().second;
		q.erase(q.begin());
		for(int i =0;i<V;i++)
		{
			if(graph[u][i] > 0 && arr[i]>graph[u][i])
			arr[i] = graph[u][i];
		}
	}
	int sum =0;
	for(int i =0;i<V;i++)
		sum += arr[i];
	cout<<sum;
}
int main()
{
	getMST();
	return 0;
}