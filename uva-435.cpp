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

map<vector<int>,bool>mymap;
void combinations(vector<int> x)
{
	if(mymap.find(x) ==mymap.end())
	{
		mymap[x] =true;
	for(int i =0;i<x.size();i++)
	{
		vector<int> y = x;
		y.erase(y.begin()+i);
		combinations(y);
	}
	}else
	return;
}
bool find_value(int a,vector<int>arr)
{
	for(int i =0;i<arr.size();i++)
	{
		if(a == arr[i])
		return true;
	}
	return false;
}
int sum_value(vector<int>arr)
{
	int fucker =0;
	for(int i =0;i<arr.size();i++)
	{
		fucker+=arr[i];
	}
	return fucker;
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int h =0;
		cin>>h;
		vector<int>arr;
		int total =0;
		for(int i =0;i<h;i++)
		{
			int g =0;
			cin>>g;
			total+=g;
			arr.PB(g);
		}
		total =total/2;
		total++;
		combinations(arr);
		/*for(std::map<vector<int>,bool>::iterator it =mymap.begin();it!=mymap.end();it++)
		{
			vector<int>x = it->first;
			for(int i =0;i<x.size();i++)
			cout<<x[i]<<" ";
			cout<<endl;
		}*/
		for(int i =0;i<h;i++)
		{
			int ans =0;
			for(std::map<vector<int>,bool>::iterator it =mymap.begin();it!=mymap.end();it++)
			{
				vector<int>x = it->first;
				if(find_value(arr[i],x)==false &&sum_value(x)<total && sum_value(x)+arr[i]>=total)
				{
					ans++;for(int i =0;i<x.size();i++)
			cout<<x[i]<<" ";
			cout<<endl;
				}
 			}
			cout<<ans<<"----"<<endl;
		}
		n--;
		mymap.erase(mymap.begin(),mymap.end());
	}
	return 0;
}