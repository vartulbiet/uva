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
int do_check(map<char,int>mymap,vector<string>arr)
{
	int nas =0;
	for(int i =0;i<arr.size();i++)
	{
		string h =arr[i];
		map<char,int>mapp;
		for(int j = 0;j<h.size();j++)
		{
			mapp[h[j]]++;
		}
		int m =0;
		for(std::map<char,int>::iterator it =mapp.begin();it!=mapp.end();it++)
		{
			if(mymap.find(it->first)==mymap.end() || mymap[it->first]<it->second)
			break;
			m++;
		}
		if(m == mapp.size())
		nas++;
	}
	return nas;
}
int main()
{
	string s;
	getline(cin,s);
	vector<string>arr;
	while(s!="#")
	{
		arr.PB(s);
		getline(cin,s);
	}
	string f;
	getline(cin,f);
	while(f!="#")
	{
		map<char,int>mymap;
		int nas =0;
		for(int i =0;i<f.size();i++)
		{
			if(f[i]>='a' & f[i]<='z')
			mymap[f[i]]++;
		}
		nas =do_check(mymap,arr);
		cout<<nas<<endl;
		getline(cin,f);
	}
	return 0;
}