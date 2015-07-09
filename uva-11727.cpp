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
		int a,b,c;
		cin>>a>>b>>c;
		cout<<"Case "<<i++<<": ";
		if(a>b)
		{
			if(b>c)
			cout<<b<<endl;
			else
			{
				if(a>c)
				cout<<c<<endl;
				else
				cout<<a<<endl;
			}
		}
		else
		{
			if(a>c)
			cout<<a<<endl;
			else
			{
				if(b>c)
				cout<<c<<endl;
				else
				cout<<b<<endl;
			}
		}
		n--;
	}
	return 0;
}