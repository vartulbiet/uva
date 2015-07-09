#include<iostream>
#include<vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
vector<vector<int> >hold;
map<int,bool>rest;
int toNum(vector<int>x)
{
	int ans =0;int k =1;
	for(int i=x.size()-1;i>=0;i--)
	{
		ans+=(x[i]*k);
		k=k*10;
	}
	return ans;
}
void recurse(int*arr,int n,bool *brr,vector<int>keep)
{
	if(keep.size()==n)
	{
		vector<int>kep =keep;
		hold.PB(kep);
		rest[toNum(kep)]= true;
	}
	else
	{
		for(int j =0;j<10;j++)
		{
			vector<int>temp = keep;
			if(brr[j]==false)
			{
			temp.PB(arr[j]);
			brr[j] = true;
			recurse(arr,n,brr,temp);
			brr[j] = false;
			}
		}
	}
}
vector<int> tovec(int x)
{
	vector<int>vec;int a=5;
	while(a!=0)
	{
		vec.PB(x%10);
		x=x/10;
		a--;
	}
	return vec;
}
void pt(vector<int>x)
{
	for(int i =0;i<x.size();i++)
	cout<<x[i];
}
bool confirm(vector<int>x,int y)
{
	map<int,int>my;
	for(int i =0;i<x.size();i++)
	my[x[i]] = 100;
	vector<int>z =tovec(y);
	for(int i =0;i<z.size();i++)
	if(my[z[i]]==100)
	return false;
	return true;
}
int main()
{
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	bool brr[10];
	memset(brr,false,10);
	vector<int>keep;
	recurse(arr,5,brr,keep);
	int j =0;
	cin>>j;
	int tc=1;
	while(j!=0)
	{bool bt =false;
	if(tc!=1)
	cout<<endl;
	tc++;
		for(int i =0;i<hold.size();i++)
		{
				if(rest.find(toNum(hold[i])*j)!=rest.end() && confirm(hold[i],toNum(hold[i])*j))
				{
				cout<<toNum(hold[i])*j;cout<<" / ";pt(hold[i]);cout<<" = "<<j<<endl;bt= true;}
		}
		if(!bt)
		cout<<"There are no solutions for "<<j<<"."<<endl;
		cin>>j;
	}
	return 0;
}