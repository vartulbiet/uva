#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(int)
#define FEL(i,a,b) for(int i=a;i<b;i++)
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;
	int m = 0;
	cin>>n>>m;
	while(n!=-1 || m !=-1)
	{
	
		int diff= abs(m-n);
		if(n>m)
		{
			int t = m;
			m =n;
			n= t;
		}
		int diff1 = n+ 100-m;
		cout<<min(diff,diff1)<<endl;
		cin>>n>>m;
	}
	return 0;
}