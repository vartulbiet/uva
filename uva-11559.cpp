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
int main()
{
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
	{
		int ans =INF;
		for(int i =0;i<c;i++)
		{
			int x =0;
			cin>>x;
			for(int i=0;i<d;i++)
			{
				int h =0;
				cin>>h;
				if(h>=a)
				ans =min(ans,x*a);
			}
		}
		if(ans<=b)
		cout<<ans<<endl;
		else
		cout<<"stay home"<<endl;
	}
	return 0;
}