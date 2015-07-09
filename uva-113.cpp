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
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		double x = log(n);
		double y =log(m);
		cout<<x/y<<endl;
		cout<<m<<n;
	}
	return 0;
}