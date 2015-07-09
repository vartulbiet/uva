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
		map<char,int>mymap;
		for(int i =0;i<26;i++)
		{
		mymap['a'+i] = 0;
		}
		for(int i =0;i<26;i++)
		mymap['A'+i] = 0;
		
		vector<char>vec;
		int high =0;
		
		for(int i =0;i<s.size();i++)
		{
			
			if((s[i]>='a' && s[i]<='z' )|| (s[i]>='A' && s[i]<='Z' ))
			{
				mymap[s[i]]++;
				if(mymap[s[i]]==high)
				{
					vec.push_back(s[i]);
					high = mymap[s[i]];
				}
				else if(mymap[s[i]]>high)
				{
					vec.erase(vec.begin(),vec.end());
					high = mymap[s[i]];
					vec.PB(s[i]);
				}
			}
		}
		sort(vec.begin(),vec.end());
		for(int i =0;i<vec.size();i++)
		cout<<vec[i];
		cout<<" "<<high<<endl;
	}
	return 0;
}