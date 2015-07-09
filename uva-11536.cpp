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

int check(vector<int>arr)
{
	int mint =INF;
	int maxt =0;
	for(int i =0;i<arr.size();i++)
	{
		if(arr[i] == -1)
		return INF;
		mint = min(mint,arr[i]);
		maxt = max(maxt,arr[i]);
	}
	return maxt-mint+1;
}

int main()
{
	int n =0;
	cin>>n;
	int m =1;
	while(n>0)
	{
		int a,b,c;
		cin>>a>>b>>c;
		vector<int>x(a);
		x[0]=1;x[1]=2;x[2]=3;
		
		for(int i = 3;i<a;i++)
			x[i] = (x[i-1]+x[i-2]+x[i-3])%b+1;
			
		vector<int>arr(c);
		for(int i =0;i<c;i++)
		arr[i] = -1;
		
		int ans =INF;
		for(int i =0;i<a;i++)
		{
			if(x[i]>0 && x[i]<=c)
			{
				arr[x[i]-1] = i;
				ans = min(ans,check(arr));
			}
		}
		cout<<"Case "<<m++<<": ";
		if(ans!=INF)
		cout<<ans<<endl;
		else
		cout<<"sequence nai"<<endl;
		n--;
	}
	return 0;
}