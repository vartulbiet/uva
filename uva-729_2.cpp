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

void init()
{
	for(int i =0;i<20;i++)
	{
		arr[i] = 0;
	}
}
bool check(vector<vector<int> > mymap,vector<int>brr)
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
void BFS()
{
	queue<pair< vector<int>, int> >q;
	vector<vector<int> >mymap;
	q.push(make_pair(arr,0));
	while(!q.empty())
	{
		vector<int>x = q.front().first;
		int z =q.front().second;
		q.pop();
		if(z == h && check(mymap,x))
		{
			mymap.PB(x);
			//for(int i =0;i<c;i++)
			//cout<<x[i];
			//cout<<endl;
		}
		else if(z<h)
		{
			for(int i = c-1;i>=0;i--)
			{
				if(x[i] ==0)
				{
					x[i ]= 1;
					q.push(make_pair(x,z+1));
					x[i] = 0;
				}
			}
		}
	}
	//sort(mymap.begin(),mymap.end());
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
}
int main()
{
	int tc = 0;
	scanf("%d",&tc);
	
	while(tc>0)
	{
		init();
		scanf("%d%d",&c,&h);
		BFS();
		
		if(tc!=1)
		cout<<endl;
		tc--;
	}
	return 0;
}