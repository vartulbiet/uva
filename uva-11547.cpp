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
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int a;
		cin>>a;
		a *=567;
		a/=9;
		a+=7492;
		a*=235;
		a/=47;
		a-=498;
		a=a/10;
		a=a%10;
		cout<<abs(a)<<endl;
		n--;
	}
	return 0;
}