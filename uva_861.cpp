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
int arr[10][10];
int a;
map<map<int,bool>,bool>mymap;
void init()
{
	int y =1;
	for(int i =0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		arr[i][j]= y++;
	}
}
bool isPresent(int x,map<int,bool>vec)
{
	if(vec.find(x)==vec.end())
	return false;
	else
	return true;
}
bool check(int x,int y,map<int,bool>vec)
{
	bool bt = false;
	for(int i =0;i<a;i++)
	{
		if(x-i>=0 && y-i>=0 && x-i<a && y-i<a)
		{
			bt =isPresent(arr[x-i][y-i],vec);
		}
		if(bt)
		return false;
		if(x+i>=0 && y-i>=0 && x+i<a && y-i<a)
		{
			bt =isPresent(arr[x+i][y-i],vec);
		}
		if(bt)
		return false;
		if(x-i>=0 && y+i>=0 && x-i<a && y+i<a)
		{
			bt =isPresent(arr[x-i][y+i],vec);
		}
		if(bt)
		return false;
		if(x+i>=0 && y+i>=0 && x+i<a && y+i<a)
		{
			bt =isPresent(arr[x+i][y+i],vec);
		}
		if(bt)
		return false;
	}
	return true;
}
void recurse(int n,map<int,bool>vec)
{
	if(n==0)
	{
		map<int,bool>temp = vec;
		if(mymap.find(temp)==mymap.end())
		{
			mymap[temp] = true;
		}
	}
	else
	{
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<a;j++)
			{
				if(vec.find(arr[i][j])==vec.end() && check(i,j,vec))
				{
					map<int,bool>temp =vec;
					temp[arr[i][j]] = true;
					recurse(n-1,temp);
				}
			}
		}
	}
}
int main()
{
	int b;
	cin>>a>>b;
	while(a!=0 && b!=0)
	{
		init();
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<a;j++)
			{
				map<int,bool>vec;
				vec[arr[i][j]]= true;
				recurse(b-1,vec);
			}
		}
		cout<<mymap.size()<<endl;
	/*	for(std::map<map<int,bool>,bool>::iterator it = mymap.begin();it!=mymap.end();it++)
		{
			map<int,bool>mm =it->first;
			for(std::map<int,bool>::iterator iit = mm.begin();iit!=mm.end();iit++)
			cout<<iit->first<<" ";
			cout<<endl;
		}*/
		mymap.erase(mymap.begin(),mymap.end());
		
		cin>>a>>b;
	}
	return 0;
}