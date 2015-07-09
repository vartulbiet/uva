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
int get_index(vector<int>arr,int t)
{
	for(int i =0;i<arr.size();i++)
	if(arr[i]==t)
	return i;
	return 0;
}
void flip(vector<int>&temp,int ind)
{
	vector<int>arr(temp.size());
	int n = temp.size()-1;
	for(int k = 0;k<temp.size();k++)
	{
		arr[k] = temp[k];
	}
	for(int i = ind;i<temp.size();i++)
	{
		temp[i]= arr[n--];
	}
}
int main()
{
	string s;
	while(getline(cin,s))
	{
		std::stringstream ss;
		ss.str(s);
		int x;
		vector<int>arr;
		while(ss>>x)
		{
			arr.PB(x);
		}
		vector<int>temp =arr,printt = arr;
		reverse(temp.begin(),temp.end());
		sort(arr.begin(),arr.end());
		int y =0;
		int sz = arr.size();
		vector<int>store;
		while(y<sz)
		{
			if(arr[sz-1-y] != temp[y])
			{
				if(temp[sz-1]!=arr[sz-1-y])
				{
					int h = get_index(temp,arr[sz-1-y]);
					flip(temp,h);
					store.PB(h);
				}
				flip(temp,y);
				store.PB(y);
			}
			y++;
		}
		for(int i =0;i<printt.size();i++)
		{
			if(i!=0)
			cout<<" ";
			cout<<printt[i];
		}
		cout<<endl;
		for(int i =0;i<store.size();i++)
		{
			cout<<store[i]+1<<" ";
		}
		cout<<'0'<<endl;
	}
	return  0;
}