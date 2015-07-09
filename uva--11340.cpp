#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<map>
#include<stack>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(int)
#define FEL(i,a,b) for(int i=a;i<b;i++)
#define INF 1<<30
using namespace std;
int main()
{

	int n =0;
	cin>>n;
	while(n>0)
	{
		int x;
		cin>>x;
		map<char,int>mymap;
		for(int i =0;i<x;i++)
		{
			char a;
			int b;
			cin>>a>>b;
			mymap[a] =b;
		}
		int z =0;
		cin>>z;
		string s;
		getline(cin,s);
		vector<string>vec;
		for(int i =0;i<z;i++)
		{
		getline(cin,s);
		vec.push_back(s);
		}
		int ans =0;
		for(int i =0;i<vec.size();i++)
		{
			for(int j =0;j<vec[i].size();j++)
			{
				if(mymap.find(vec[i][j])!=mymap.end())
				ans+=mymap[vec[i][j]];
			}
		}
		printf("%d.%.2d$\n",ans/100,ans%100);
		n--;
	}
	return 0;
}