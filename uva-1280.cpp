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
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int m =n;
		for(int i =0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			int x =b%10;
			long long h =pow(a%c,x);
			//cout<<h;
			cout<< h%c<<endl;
		}
		cin>>n;
	}
	return 0;
}