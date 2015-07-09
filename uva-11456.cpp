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
int LIS(vector<int>arr,vector<int>&lis)
{
	for(int i =0;i<arr.size();i++)
	{
		for(int j =0;j<i;j++)
		{
		if(arr[j]<arr[i])
		lis[i] =max(lis[i],lis[j]+1);
		}
	}
}
int LDS(vector<int>arr,vector<int>&lds)
{
	for(int i =0;i<arr.size();i++)
	{
		for(int j =0;j<i;j++)
		{
		if(arr[j]>arr[i])
		lds[i] =max(lds[i],lds[j]+1);
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int m ;
		cin>>m;
		vector<int>arr(m);
		vector<int>lis(m);
		vector<int>lds(m);
		for(int i =0;i<m;i++)
		{
			lis[i] =0;
			lds[i] = 0;
		}
		for(int i =0;i<m;i++)
		{
			cin>>arr[i];
		}
		int ans =0;
		LIS(arr,lis);
		LDS(arr,lds);
		for(int i =0;i<m;i++)
		{
			cout<<lis[i]<<" "<<lds[i]<<" ";
			ans =max(lis[i]+lds[i]-1,ans);
		}
		cout<<ans<<endl;
		n--;
	}
	return 0;
}