#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(int)
#define FEL(i,a,b) for(int i=a;i<b;i++)
#define INF 1<<30
using namespace std;


int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		vector<int>arr(m);
		for(int i =0;i<m;i++)
		cin>>arr[i];
		int start =0;
		int last =0;
		int sum =0;
		int ans =INF;
		for(int i =0;i<m;)
		{
			while(sum<n && i<m)
			{
				sum +=arr[i];
				last++;
				i++;
			}
			if(sum>=n)
			{
				while(sum>=n)
				{
					sum -=arr[start];
					start++;
					//cout<<sum<<endl;
				}
				ans =min(ans,last-start+1);
			}
		}
		if(ans==INF)
		cout<<"0"<<endl;
		else
		cout<<ans<<endl;
	}
	return 0;
}