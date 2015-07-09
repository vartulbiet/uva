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
bool compare1(string s)
{
	int t =0;
	string x ="one";
	for(int i =0;i<s.size();i++)
	{
		if(s[i]==x[i])
		t++;
	}
	if(t>1)
	return true;
	else
	return false;
}
int main()
{
	int n =0;
	cin>>n;
	
	while(n!=0)
	{
		int m =0;
		cin>>m;
		int mint =INF;int mant = 0;
		for(int i =0;i<m;i++)
		{
			int a;
			cin>>a;
			if(a<mint)
			mint =a;
			if(a>mant)
			mant =a;
		}
		cout<<(mant-mint)*2<<endl;
		n--;
	}
	return 0;
}