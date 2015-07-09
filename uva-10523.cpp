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
#define INF 1<<10
using namespace std;
int main()
{
	int a,b;
	while(scanf("%d%d",&b,&a)==2)
	{
		vector<long long>x;
		x.push_back(1);
		x.push_back(a);
		for(int i =2;i<=b;i++)
		{
			x.push_back(x[i/2]*x[i-(i/2)]);
		}
		long long ans = 0;
		for(int i =1;i<=b;i++)
		{
			ans+=(i*x[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}