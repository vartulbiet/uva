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
	char t;
	getchar();
	while(n>0)
	{
		string x,y;
		getline(cin,x);
		getline(cin,y);
		int sz =y.size();
		map<char,int>mymap;
		for(int i =0;i<sz;i++)
		{
			if((y[i]>='a' && y[i]<='z'))
			mymap[y[i]]++;
			else
			if((y[i]>='A' && y[i]<='Z'))
			mymap[y[i]+32]++;
		}
		vector<pair<int,char> >vec;
		for(std::map<char,int>::iterator it = mymap.begin();it!=mymap.end();it++)
		{
			vec.PB(make_pair(it->second,it->first));
		}

			sort(vec.begin(),vec.end());
			string z = x.substr(25-vec.size()+1,vec.size());
			string ans;
			map<char,char>hold;
			for(int i =0;i<vec.size();i++)
			{
				//cout<<vec[i].second <<z[i]<<endl;
				hold[vec[i].second] = z[i];
			}
			for(int i =0;i<sz;i++)
			{
				//cout<<hold[y[i]]<<endl;
				if((y[i]>='a' && y[i]<='z'))
				ans.PB(hold[y[i]]);
				else if((y[i]>='A' && y[i]<='Z'))
				ans.PB(hold[y[i]+32]-32);
				else
				ans.PB(y[i]);
			}
		cout<<ans<<endl;
		n--;
	}
	return 0;
}