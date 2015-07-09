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
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int ans;
void calculate(int s,int e,int h,int req_h,int count,int m_c,vector<int>arr)
{
	if(h<0 ||s>e)
	return;
	if(s==e && h==0)
	{
		if(count == m_c)
		{
		ans++;
		for(int i =0;i<arr.size();i++)
		cout<<arr[i]<<" ";
		cout<<endl;
		}
	}
	else
	{
		if(h+1==req_h)
		{
			arr.PB(h+1);
			calculate(s+1,e,h+1,req_h,count+1,m_c,arr);
			arr.pop_back();
		}
		else
		{
		arr.PB(h+1);
		calculate(s+1,e,h+1,req_h,count,m_c,arr);
		arr.pop_back();
		}
		if(h-1==req_h && h-1>=0)
		{arr.PB(h-1);
		calculate(s+1,e,h-1,req_h,count+1,m_c,arr);arr.pop_back();
		}
		else if(h-1>=0)
		{arr.PB(h-1);
		calculate(s+1,e,h-1,req_h,count,m_c,arr);arr.pop_back();
		}
	}
}
int main()
{
	int n,r,k;
	while(scanf("%d%d%d",&n,&r,&k) == 3)
	{
		int s =0;
		int e = 2*n;
		int h =0;
		int req_h = k;
		int count  = 0;
		ans =0;
		vector<int>arr;
		arr.PB(0);
		calculate(s,e,h,req_h,count,r,arr);
		cout<<ans<<endl;
	}
	return 0;
}