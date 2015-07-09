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
vector<pair<int,int> >vec;
int table[1001][31];
void knapsack(int wt)
{
	int n = vec.size();
	for(int i =0;i<n+1;i++)
	{
		for(int j =0;j<wt+1;j++)
		table[i][j] = 0;
	}
	for(int i =1;i<n+1;i++)
	{
		for(int j =1;j<wt+1;j++)
		{
			 int temp =  table[i][j];
			if(vec[i-1].first<=j && temp<(table[i-1][j-vec[i-1].first]+vec[i-1].second))
			{
				temp = table[i-1][j-vec[i-1].first]+vec[i-1].second;
			}
			table[i][j] =  max(table[i-1][j],table[i][j-1]);
			table[i][j]= max(table[i][j],temp);
		}
	}
	/*for(int i =0;i<n+1;i++)
	{
		for(int j =0;j<wt+1;j++)
		cout<<table[i][j]<<" ";
		cout<<endl;
	}*/
	//cout<<table[n][wt]<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int x =0;
		cin>>x;
		for(int i =0;i<x;i++)
		{
			int a,b;
			cin>>a>>b;
			vec.PB(make_pair(b,a));
		}
		sort(vec.begin(),vec.end());
		int num =0;
		cin>>num;int ans =0;
		int mat =0;
		vector<int >keep;
		while(num>0)
		{
			int wt =0;
			cin>>wt;
			keep.PB(wt);
			mat = max(mat,wt);
			num--;	
		}
		knapsack(mat);
		for(int i  =0;i<keep.size();i++)
		{
			ans+=table[x-1][keep[i]];
		}
		cout<<ans<<endl;
		n--;
		vec.erase(vec.begin(),vec.end());
	}
	return 0;
}