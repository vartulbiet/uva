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
		map<map<int,bool>,int>mymap;
		
		for(int i =0;i<n;i++)
		{
			map<int,bool>my;
			for(int i =0;i<5;i++)
			{
				int y =0;
				cin>>y;
				my[y]= true;
			}
			mymap[my]++;
		}int mm =0;
		for(std::map<map<int,bool>,int >::iterator it= mymap.begin();it!=mymap.end();it++)
		{
			if(it->second>mm)
			{
				mm=it->second;
			}
		}
		int m =0;
		for(std::map<map<int,bool>,int >::iterator it= mymap.begin();it!=mymap.end();it++)
		{
			if(it->second==mm)
			{
				m+=mm;
			}
		}
		
		cout<<m<<endl;
		cin>>n;
	}
	return 0;
}