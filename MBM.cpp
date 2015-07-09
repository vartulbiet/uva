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
int graph[105][105];
void init()
{
	for(int i =0;i<105;i++)
	{
		for(int j =0;j<105;j++)
			graph[i][j] = 0;
	}
}
bool bipartite_matching(vector<int>seen,int x,vector<int>match,int n)
{
	for(int j =0;j<n;j++)
	{
		if(graph[x][j] == 1 && !seen[j])
		{
			seen[j] = true;
			if(match[j]<0 || bipartit_matching(seen,match[j],match,n)){
			match[j] = x
			return true;}
		}
	}
	return false;
}
void MBM(int n)
{
	vector<int>seen(n);
	vector<int>match(n);
	fill(match.begin(),match.end(),-1);
	for(int i =0;i<n;i++)
	{
		fill(seen.begin(),seen.end(),0);
		if(bipartite_matching(seen,i,match,n))
			j++;
	}
	return j;
}
int main()
{
	int n =0;
	cin>>n;
	MBM(n);
}