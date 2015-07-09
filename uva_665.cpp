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
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int a,b;
		cin>>a>>b;
		vector<int>arr(a);
		fill(arr.begin(),arr.end(),2);
		for(int i =0;i<b;i++)
		{
			vector<int>c;
			vector<int>d;
			int x =0;
			cin>>x;
			for(int j =0;j<x;j++)
			{
				int y = 0;
				cin>>y;
				c.PB(y-1);
			}
			for(int j =0;j<x;j++)
			{
				int y = 0;
				cin>>y;
				d.PB(y-1);
			}
			char z;
			cin>>z;
			if(z=='>')
			{
				for(int i =0;i<x;i++)
				{
				if(arr[c[i]]!=0)
					arr[c[i]] = 1;
					if(arr[d[i]]!=0)
					arr[d[i]] = -1;
				}
			}
			else if(z == '<')
			{
			for(int i =0;i<x;i++)
				{
				if(arr[c[i]]!=0)
				arr[c[i]] = -1;
				if(arr[d[i]]!=0)
				arr[d[i]] = 1;
				}
			}
			else if(z=='=')
			{
				for(int i =0;i<x;i++)
				{
					arr[c[i]] = 0;
					arr[d[i]] = 0;
				}
			}
		}
		vector<int>f;
		vector<int>g;
		bool bt = true;
		for(int i =0;i<a;i++)
		{
			if(arr[i] == 1)
			f.PB(i);
			else if(arr[i]==-1)
			g.PB(i);
			else if(arr[i]==2)
			bt =false;
		}
	if(bt)
	{
		if(f.size()==1 && g.size()!=1)
		cout<<f[0]+1<<endl;
		if(g.size()==1 && f.size()!=1)
		cout<<g[0]+1<<endl;
	}
	else
	cout<<"0"<<endl;
		if(n!=1)
		cout<<endl;
		n--;
	}
}