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
	int i =1;
	while(n!=0)
	{
		int a,b;
		cin>>a>>b;
		a -=2;
		b-=2;
		if(a%3==0)
		a=a/3;
		else
		a=(a/3)+1;
		if(b%3==0)
		b=b/3;
		else
		b=(b/3)+1;
		cout<<a*b<<endl;
		n--;
	}
	return 0;
}