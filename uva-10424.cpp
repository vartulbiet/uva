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
int getd(int num)
{
	if(num<10)
	return num;
	else
	{
	int x = 0;
	while(num>0)
	{
		x = x+(num%10);
		num =num/10;
	}
	return getd(x);
	}
}
int get_value(string s)
{
	vector<int>val;
	string x;
	for(int i =0;i<s.size();i++)
	{
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
		x.push_back(s[i]);
	}
	for(int p =0;p<x.size();p++)
	{
		if(x[p]>='a' && x[p]<='z')
		val.push_back(x[p]-'a'+1);
		else if(x[p]>='A' && x[p]<='Z')
		val.push_back(x[p]-'A'+1);
	}
	int ans =0;
	for(int i =0;i<val.size();i++)
	ans+=val[i];
	return getd(ans);
}

int main()
{
	string a, b;
	while(getline(cin,a) && getline(cin,b))
	{
		int cal = get_value(a);
		int dal = get_value(b);
		if(cal>dal)
		swap(cal,dal);
		double ans = (double)(cal/(double)dal)*100;
		printf("%2.2lf",ans);
		cout<<" %"<<endl;
	}
	return 0;
}