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
	string s;
	getline(cin,s);
	while(n>0)
	{
		getline(cin,s);
		map<char,int>mymap;
		for(int i =0;i<s.size();i++)
		{
			if(s[i]>='A' && s[i]<='Z')
			s[i] = 32+s[i];
			if(s[i]>='a' && s[i]<='z')
			{
				mymap[s[i]]++;
			}
		}
		string ans;
		int high = 0;
		for(std::map<char,int>::iterator it= mymap.begin();it!=mymap.end();it++)
		{
			if(it->second ==high)
			{
				high = it->second;
				ans.PB(it->first);
			}
			else if(it->second>high)
			{
				high = it->second;
				ans.erase(ans.begin(),ans.end());
				ans.PB(it->first);
			}
		}
		cout<<ans<<endl;
		n--;
	}
	return 0;
}