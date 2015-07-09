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
	string h;
	
	while(n>0)
	{
		
		string s;getline(cin,h);
		getline(cin,s);
		for(int i =0;i<s.size();i++)
		{if(s[i]>=97 && s[i]<=122)
		s[i]=s[i]-32;
		cout<<s[i];}cout<<endl;
		int a,b,c;
		cin>>a>>b>>c;//getline(cin,h);
		map<string,int>mymap;
		for(int i =0;i<a;i++)
		{
			string t;int r;
			cin>>t>>r;
			mymap[t] =r;
		}
		string t;
		//getline(cin,h);
		map<string,int>ans;
		for(int j =0;j<b;j++)
		{
			getline(cin,h);
			getline(cin,t);
			int y =0;
			//cout<<t<<"---";
			cin>>y;int cost =0;
			for(int i =0;i<y;i++)
			{
				string g;int u;
				cin>>g>>u;
				cost+=(mymap[g]*u);
			}
			if(cost<=c)
			ans[t]= cost;
		}
		vector<pair<int,string> >vec;
		for(std::map<string,int>::iterator it =ans.begin();it!=ans.end();it++)
		{
			vec.PB(make_pair(it->second,it->first));
		}
		sort(vec.begin(),vec.end());
		if(vec.size()==0)
		cout<<"Too expensive!"<<endl;
		for(int i =0;i<vec.size();i++)
		cout<<vec[i].second<<endl;
		cout<<endl;
		n--;
	}
	return 0;
}