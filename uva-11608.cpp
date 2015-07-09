#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<map>
#include<stack>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(int)
#define FEL(i,a,b) for(int i=a;i<b;i++)
#define INF 1<<30
using namespace std;
int main()
{

	int n =0;
	cin>>n;
	int m =1;
	while(n>=0)
	{
		vector<int>arr(12);
		vector<int>brr(12);
		for(int i =0;i<12;i++)
		cin>>arr[i];
		for(int i =0;i<12;i++)
		cin>>brr[i];
		int toreduce =0;
		cout<<"Case "<<m++<<":"<<endl;
		for(int i =0;i<12;i++)
		{
			int g =brr[i];
			int sum =n;
			for(int j =0;j<i;j++)
			{
				sum +=arr[j];
			}
			sum = sum-toreduce;
			if(sum>=g)
			{
				toreduce +=g;
				cout<<"No problem! :D"<<endl;
			}
			else
			cout<<"No problem. :("<<endl;
		}
		cin>>n;
	}
	return 0;
}