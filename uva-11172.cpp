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
		int a,b;
		cin>>a>>b;
		if(a>b)
			cout<<">"<<endl;
		else if(a<b)
			cout<<"<"<<endl;
		else
			cout<<"="<<endl;
		n--;
	}
	return 0;
}