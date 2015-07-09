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

void max_sum(int*arr,int n)
{
	int sum =0;int curr_sum =0;
	for(int i =0;i<n;i++)
	{
		curr_sum +=arr[i];
		if(curr_sum<0)
		curr_sum =0;
		if(sum<curr_sum)
		{
			sum =curr_sum;
		}
	}
	if(sum ==0)
	cout<<"Losing streak."<<endl;
	else
	cout<<"The maximum winning streak is "<<sum<<"."<<endl;
}

int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int arr[10000];
		for(int i =0;i<n;i++)
		scanf("%d",&arr[i]);
		
		max_sum(arr,n);
		
		cin>>n;
	}
	return 0;
}