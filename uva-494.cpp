#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30
using namespace std;
vector<string>x;
int create_vector(string s)
{
	string y;
	for(int i=0;i<s.size();i++)
	if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z') || (s[i] ==32));
	else
	s[i] = 32;
	//cout<<s<<endl;
	for(int i=0;i<s.size()-1;i++)
	{
		if((s[i] == s[i+1]) && (s[i] ==32))
		{s.erase(s.begin()+i+1);i=0;}
	}
	for(int i =0;i<s.size();i++)
	{
		if(s[i]!=32)
		{
			y.push_back(s[i]);
		}
		else
		{
			x.push_back(y);
		//	cout<<y<<endl;
			y.erase(y.begin(),y.end());
		}
	}
	//cout<<y<<endl;
	x.push_back(y);
	int ans =0;
	//cout<<x.size()<<" ";
	for(int i =0;i<x.size();i++)
	{
		string d = x[i];
		bool t = false;
		for(int j =0;j<d.size();j++)
		{
			if((d[j]>='a' && d[j]<='z') ||(d[j]>='A' && d[j]<='Z'))
			t =true;
		}
		if(t)
		ans++;
	}
	return ans;
}
int main()
{
	string s;
	//getline(cin,s);
	while(getline(cin,s))
	{
		if(s.size()==0)
		cout<<endl;
		else
		cout<<create_vector(s)<<endl;
		x.erase(x.begin(),x.end());
		//getline(cin,s);
	}
	return 0;
}