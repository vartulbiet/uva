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
	int n;cin>>n;
	while(n>0)
	{
		int a;
		double b;
		int c;
		scanf("%d%lf%d",&a,&b,&c);
		double z;
		if(b>0)
		 z = b/(1-pow((1-b),a));
		else
		z =b;
		z = z*pow(1-b,c-1);
		printf("%.4lf\n",z);
		n--;
	}
	return 0;
}