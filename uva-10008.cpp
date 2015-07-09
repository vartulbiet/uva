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
bool compart(pair<int,char>a,pair<int,char>b)
{
	if(a.first>b.first)
	return true;
	else if(a.first == b.first)
	{
		if(a.second<b.second)
		return true;
		else return false;
	}
	else
	return false;
}
int main()
{
	int n =0;
	cin>>n;
	vector<pair< int,char> >vec;
	string s;
	map<char,int>mymap;
		for(int i =0;i<26;i++)
		{
		mymap['A'+i] = 0;
		}
		getline(cin,s);
	while(n>0)
	{
	getline(cin,s);
		for(int i =0;i<s.size();i++)
		{
			
			if((s[i]>='a' && s[i]<='z' )|| (s[i]>='A' && s[i]<='Z' ))
			{
				if(s[i]>='a' && s[i]<='z' )
				s[i] = s[i]-32;
				mymap[s[i]]++;
			}
		}
		
		n--;
	}
	for(std::map<char,int>::iterator it =mymap.begin();it!=mymap.end();it++)
		{
			vec.PB(make_pair(it->second,it->first));
		}
		sort(vec.begin(),vec.end(),compart);
		for(int i =0;i<vec.size();i++)
		{
			if(vec[i].first!=0)
			cout<<vec[i].second <<" "<<vec[i].first<<endl;
		}
	return 0;
}