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
	int kk;
	string s;
	while(scanf("%d",&kk)==1)
	{
		cin>>s;
		map<string,int>mymap;
		vector<string>vec;
		for(int j =0;j<s.size()-kk;j++)
			{
				string y = s.substr(j,kk);
				mymap[y]++;
			}
		
		int high =0;
		string ans;
		for(std::map<string,int>::iterator it = mymap.begin();it!=mymap.end();it++)
		{
			if(it->second>high)
			{
				high =it->second;ans = it->first;
			}	
		}
		cout<<ans<<endl;
	}
}