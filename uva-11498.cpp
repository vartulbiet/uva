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
		int m =n;
		int a,b;
		cin>>a>>b;
		for(int i =0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			if(x==a || y==b)
			cout<<"divisa"<<endl;
			else if(x>a && y>b)
			cout<<"NE"<<endl;
			else if(x>a && y<b)
			cout<<"SE"<<endl;
			else if(x<a && y>b)
			cout<<"NO"<<endl;
			else
			cout<<"SO"<<endl;
		}
		cin>>n;
	}
	return 0;
}