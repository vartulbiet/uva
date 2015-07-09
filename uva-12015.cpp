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
	cin>>n;
	int k =1;
	while(n>0)
	{
		vector<pair<int,string> >p;
		cout<<"Case #"<<k++<<":"<<endl;
		int mat =0;
		for(int i =0;i<10;i++)
		{
		int a;
		string b;
		//getline(b);
		cin>>b>>a;
		mat =max(mat,a);
		p.push_back(make_pair(a,b));
		}
		for(int i =0;i<p.size();i++)
		if(p[i].first == mat)
		cout<<p[i].second<<endl;
		n--;
	}
	return 0;
}