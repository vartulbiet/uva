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
	int k =1;
	while(n!=0)
	{
		int a,b;
		cin>>a>>b;
		int ans =0;
		for(int i =a;i<=b;i++)
		{
			if(i%2!=0)
			ans+=i;
		}
		cout<<"Case "<<k++<<": "<<ans<<endl;
		n--;
	}
	return 0;
}