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
	while(n>0)
	{
		int v =0;
		cin>>v;
		vector<int >y;
		for(int i =0;i<v;i++)
		{
			int a,b;
			cin>>b>>a;
			int diff = abs(b-a);
			y.push_back(diff);
		}
		bool t =true;
		for(int i =0;i<v-1;i++)
		{
		if(y[i]!=y[i+1])
		{
		t =false;
		break;
		}
		}
		if(t==false)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
			if(n>1)
			cout<<endl;
		n--;
	}
	return 0;
}