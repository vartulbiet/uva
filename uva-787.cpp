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
void max_product(vector<int>arr)
{
	int sum =-INF;
	for(int i =0;i<arr.size();i++)
	{
		int curr_sum =1;
		for(int j =i;j<arr.size();j++)
		{
			curr_sum *=arr[j];
		}
		if(sum<curr_sum)
		sum =curr_sum;
	}
	cout<<sum<<endl;
}
int main()
{
	int n=0;
	vector<int>x;
	while(scanf("%d",&n)==1)
	{
		
		if(n!=-999999)
		{
			x.push_back(n);
		}
		else
		{
		max_product(x);
			x.erase(x.begin(),x.end());
		}
	}
	return  0;
}