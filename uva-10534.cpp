#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(int)
#define FEL(i,a,b) for(int i=a;i<b;i++)
#define INF 1<<30
#define INF 1<<30
using namespace std;
int hold[10000];
int rev_hold[10000];
void do_lis(int*arr,int n)
{
	for(int i =0;i<n;i++)
	hold[i] = 1;
	for(int i =1;i<n;i++)
	{
		for(int j =0;j<i;j++)
		{
			if(arr[j]<arr[i])
			hold[i] = max(hold[i],hold[j]+1);
		}
	}
}

void do_lis_rev(int*arr,int n)
{
	for(int i =0;i<n;i++)
	rev_hold[i] = 1;
	for(int i =1;i<n;i++)
	{
		for(int j =0;j<i;j++)
		{
			if(arr[j]>arr[i])
			rev_hold[i] = max(rev_hold[i],rev_hold[j]+1);
		}
	}
}
void LIS(int*x,int n)
{
	do_lis(x,n);
	do_lis_rev(x,n);
	int ans  =1;
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
				if(x[i]<x[j] && x[j]>x[k] && hold[i]==rev_hold[k])
				ans =max(ans,2*hold[i]+1);
			}
		}
	}
	cout<<ans<<endl;
}

int main()
{
	int n=0;
	while(scanf("%d",&n)==1)
	{
		int x[10000];
		for(int i =0;i<n;i++)
		cin>>x[i];
		LIS(x,n);
		for(int i =0;i<n;i++)
		hold[i] = 1;
		for(int i =0;i<n;i++)
		rev_hold[i] = 1;
	}
	return 0;
}