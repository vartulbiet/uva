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
	string s;
	while(getline(cin,s))
	{
		string r;
		map<char,int>mymap,mymap2;
		for(int i =0;i<26;i++)
		{
		mymap['a'+i] = 0;
		mymap2['a'+i] = 0;
		}
		for(int i =0;i<s.size();i++)
		{
			mymap[s[i]]++;
		}
		getline(cin,r);
		for(int i =0;i<r.size();i++)
		{
			mymap2[r[i]]++;
		}
		string ans;
		for(int i =0;i<26;i++)
		{
			if(mymap[i+'a']>0 && mymap2[i+'a']>0)
			{
				for(int j =0;j<min(mymap[i+'a'],mymap2[i+'a']);j++)
				ans.PB(i+'a');
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}