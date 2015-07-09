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
	string c;
	getline(cin,c);
	while(n!=0)
	{
		string s;
		getline(cin,s);
		if(s.size()>3)
		cout<<"3"<<endl;
		else if(s.size()==3 && compare1(s))
		cout<<"1"<<endl;
		else
		cout<<"2"<<endl;
		n--;
	}
	return 0;
}