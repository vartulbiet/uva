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
#define INF 1<<10
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int **matrix= (int**)malloc(sizeof(int*)*m);
	for(int i =0;i<m;i++)
	matrix[i] = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<m;i++)
	{
		for(int j =0;j<n;j++)
		{
			int h =0;
			cin>>h;
			if(h == 0)
			 h = -1;
			matrix[i][j] = h;
		}
	}
	
	int **sum= (int**)malloc(sizeof(int*)*m);
	for(int i =0;i<m;i++)
	sum[i] = (int*)malloc(sizeof(int)*n);
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<n;j++)
		{
			sum[i][j] = matrix[i][j];
			if(i>0)
			{
				sum[i][j] +=sum[i-1][j];
			}
			if(j>0)
			{
				sum[i][j] +=sum[i][j-1];
			}
			if(i>0 && j>0)
			{
				sum[i][j] -=sum[i-1][j-1];
			}
		}
	}
		for(int i =0;i<m;i++)
		{
		for(int j =0;j<n;j++)
		{
		cout<<matrix[i][j]<<" ";	
		}
		cout<<endl;
		}
		cout<<endl;
		for(int i =0;i<m;i++)
		{
		for(int j =0;j<n;j++)
		{
		cout<<sum[i][j]<<" ";	
		}
		cout<<endl;
		}
	int ans = -INF;
	int val =-INF;
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =i;k<m;k++)
			{
				for(int l =j;l<n;l++)
				{
					int val = sum[k][l];
					if(i-1>=0)
					val -=sum[i-1][l];
					if(j-1>=0)
					val -=sum[k][j-1];
					if(i-1>=0 && j-1>=0)
					val+=sum[i-1][j-1];
					ans = max(val,ans);
					val = max(val,ans);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}