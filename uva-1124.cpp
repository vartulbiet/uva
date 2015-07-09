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
	int k =1;
	while(n!=0)
	{
		int m =n;
		int x =0;
		for(int i =0;i<m;i++)
		{
			int a;
			cin>>a;
			if(a==0)
			x--;
			else
			x++;
		}
		cout<<"Case "<<k++<<": "<<x<<endl;
		cin>>n;
	}
	return 0;
}