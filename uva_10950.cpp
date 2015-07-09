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
#define INF 1<<30
using namespace std;
map<string,bool>ans;
void recurse(string s,map<string,string>mymap,int ind,string oup)
{
	if(ind == s.size())
	{
		ans[oup] = true;
	}
	else
	{
			int size = s.size();
			for(int j =1;j<=size-ind;j++)
			{
				string x = s.substr(ind,j);
				if(mymap.find(x)!= mymap.end())
				{
					string b = mymap[x];
					recurse(s,mymap,ind+x.size(),oup+b);
				}
			}
			if(s[ind] == '0')
				{
				recurse(s,mymap,ind+1,oup);
				}
	}
}
int main()
{
	int n =0;
	scanf("%d",&n);int tc =1;
	while(n!=0)
	{
		ans.erase(ans.begin(),ans.end());
		map<string,string>mymap;
		for(int i =0;i<n;i++)
		{
			string t;string y;
			cin>>t>>y;
			mymap[y] =t;
		}
		string s;
		cin>>s;string h;
		recurse(s,mymap,0,h);
		std::map<string,bool>::iterator it = ans.begin();
		int c =0;
		cout<<"Case #"<<tc++<<endl;
		while(it!=ans.end() && c<100)
		{
		cout<<(it)->first<<endl;
		c++;
		++it;
		}
		cout<<endl;
		scanf("%d",&n);
	}
	return 0;
}