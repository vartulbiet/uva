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
string intTostr(long long n)
{
	string s;
	while(n>9)
	{
		s.push_back(n%10);
		n=n/10;
	}
	s.push_back(n);
	reverse(s.begin(),s.end());
	return s;
}
bool isPresent(string a,string b)
{
	for(int i =0;i<a.size();i++)
	{
		if(a[i]!=b[i])
		return false;
	}
	return true;
}
int main()
{
	int n =0;
	vector<long long>store;
	store.push_back(1);
	store.push_back(2);
	for(long long i =2;i<1000000000;i++)
		store.push_back(store[i-1]*2);
		cin>>n;
	for(int i =7;i<100;i++)
	{
		if(isPresent(intTostr(n),intTostr(store[i])) && intTostr(store[i]).size()>intTostr(n).size()*2)
		{
		cout<<i<<endl;
		break;
		}
	}
	
	return 0;
}