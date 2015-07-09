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
	while(n>0)
	{
		int a =0;
		cin>>a;
		map<string,string>mymap;
		string x,y;
		getline(cin,x);
		while(a>0)
		{
			getline(cin,x);
			getline(cin,y);
			mymap[x] = y;
			a--;
		}
		int b =0;
		cin>>b;
		getline(cin,x);
		map<string,int>mapp;
		while(b>0)
		{
			getline(cin,x);
			if(mymap.find(x)!=mymap.end())
			mapp[x]++;
			b--;
		}
		int high =0;
		vector<string>ans;
		for(std::map<string,int>::iterator it= mapp.begin();it!=mapp.end();it++)
		{
			if(it->second>high)
			{
				ans.erase(ans.begin(),ans.end());
				ans.PB(it->first);
				high =it->second;
			}
			else if(it->second == high)
			{
				ans.PB(it->first);
			}
		}
		if(ans.size()!=1)
		cout<<"tie"<<endl;
		else
		cout<<mymap[ans[0]]<<endl;
		if(n!=1)
		cout<<endl;
		n--;
	}
	return 0;
}