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
			if(a<=20 &&b<=20 &&c<=20)
			cout<<"Case "<<i++<<": "<<"good"<<endl;
			else
			cout<<"Case "<<i++<<": "<<"bad"<<endl;
		n--;
	}
	return 0;
}