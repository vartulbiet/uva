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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
void max_sum(int sum,vector<int>arr)
{
	int dp[arr.size()+1][20000+1];
	int n = arr.size();
	for(int i =0;i<n+1;i++)
	{
		for(int j =0;j<20001;j++)
		{
			dp[i][j] =INF;
		}
	}
	for(int i =1;i<n+1;i++)
	{
		for(int j =0;j<20001;j++)
		{
			if(arr[i-1]>j)
			dp[i][j]= dp[i-1][j];
			if(arr[i-1]==j)
			dp[i][j]= 1;
			if(arr[i-1]<j )
			{
				dp[i][j]= min(dp[i-1][j],dp[i-1][j-arr[i-1]]+1);
			}
		}
	}

	int ans =0;int c =0;
	for(int i=sum;i<20001;i++)
	{
		if(dp[n][i]!=INF)
		{
			ans=i;
			c=dp[n][i];
			break;
		}
	}
	cout<<ans<<" "<<c<<endl;
	
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int sum =0;
		cin>>sum;
		int count =0;
		cin>>count;
		vector<int>arr(count);
		for(int i =0;i<count;i++)
		{
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		max_sum(sum,arr);
		n--;
	}
	return 0;
}