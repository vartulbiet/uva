#include <vector>
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
#define pi 3.141592653589793
using namespace std;
map<string,bool>mymap;
vector<string>vec;
string x;

void all_combinations(string y,long long int r)
{
	if(y.size()==r && mymap.find(y)==mymap.end())
	{
	mymap[y] = true;
	vec.push_back(y);
	return;
	}
	if(y.size()>=r)
	return;
	else
	{
		for(long long int i =0;i<x.size();i++)
		{
			y.push_back(x[i]);
			all_combinations(y,r);
			y.erase(y.begin()+y.size()-1);
		}
	}
}

int main()
{
	long long int t =0;
	cin>>t;
	while(t>0)
	{
		long long int y;
		cin>>x>>y;
		int n = x.size();
		long long int till =0;
		long long int r =1;
		while((till + pow((double)n,(double)r))<y)
		{
			till += pow((double)n,(double)r++);
		}
		long long int  ans= y -till;
		string a;
		all_combinations(a,r);
		sort(vec.begin(),vec.end());
		cout<<vec[ans-1]<<endl;
		vec.erase(vec.begin(),vec.end());
		mymap.erase(mymap.begin(),mymap.end());
		t--;
	}
	return 0;
}