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
using namespace std;
	vector<int> arr(20);
	int h;
	int c;
	vector<vector<int> >mymap;
void init()
{
	for(int i =0;i<20;i++)
	{
		arr[i] = 0;
	}
}
bool check(vector<int>brr)
{
	if(mymap.empty())
	return true;
	for(int it =0;it<mymap.size();it++)
	{
		vector<int>crr = mymap[it];
		int i =0;
		for(i =0;i<c;i++)
		{
		if(brr[i] !=crr[i])
		break;
		}
		if(i==c)
		return false;
	}
	return true;
}
void recurse(int val,vector<int>brr)
{
	if(val == h && check(brr))
	{
		vector<int>x(c);
		for(int i =0;i<c;i++)
		x[i] = brr[i];
		mymap.PB(x);
		return;
	}
	else
	{
		for(int i = c-1;i>=0;i--)
		{
			if(brr[i] ==0)
			{
				brr[i ]= 1;
				recurse(val+1,brr);
				brr[i] = 0;
			}
		}
		return;
	}
}
int main()
{
	int tc = 0;
	scanf("%d",&tc);
	
	while(tc>0)
	{
		init();
		scanf("%d%d",&c,&h);
		recurse(0,arr);
		sort(mymap.begin(),mymap.end());
		for(int it =0;it<mymap.size();it++)
	{
		vector<int>crr = mymap[it];
		int i =0;
		for(i =0;i<c;i++)
		{
		cout<<crr[i];
		}
cout<<endl;
	}
		if(tc!=1)
		cout<<endl;
		mymap.erase(mymap.begin(),mymap.end());
		tc--;
	}
	return 0;
}