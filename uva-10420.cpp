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
	map<string,int>mymap;
	while(n>0)
	{
		getline(cin,s);
		string sub;
		for(int i =0;i<s.size();i++)
		{
			if(s[i]!=' ')
			sub.PB(s[i]);
			else
			break;
		}
		mymap[sub]++;
		n--;
	}
	for(std::map<string,int>::iterator it= mymap.begin();it!=mymap.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}