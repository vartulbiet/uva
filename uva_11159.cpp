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
bool check(int i,int *match,bool *seen,int b)
{
	if(match)
	for(int j =0;j<b;j++)
	{
		if(!seen[j] && graph[i][j] ==1)
		{
		seen[j]=  true;
		if(match[j]<0 || check(match[j],match,seen,b))
		{
			match[j] = i;
			return true;
		}
		}
	}
	return false;
}
void MBM(int a,int b)
{
	int match[105];
	memset(match,-1,sizeof(match));
	int ans =0;
	for(int i =0;i<a;i++)
	{
		bool seen[105];
		memset(seen,false,sizeof(seen));
		if(check(i,match,seen,b))
		ans++;
	}
	cout<<ans<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	int tc =1;
	while(n--)
	{
		int a;
		cin>>a;
		vector<int>vec(a);
		for(int i =0;i<a;i++)
		cin>>vec[i];
		int b;
		cin>>b;
		vector<int>sec(b);
		for(int j =0;j<b;j++)
		cin>>sec[j];
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<b;j++)
			{
				if((vec[i]==0 && sec[j]==0))
				graph[i][j] =1;
				else if(vec[i] !=0 && (sec[j]==0 || sec[j]%vec[i]==0))
				graph[i][j] =1;
				else
				graph[i][j] =0;
			}
		}
		cout<<"Case "<<tc++<<": ";
		MBM(a,b);
	}
	return 0;
}