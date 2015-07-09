#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<string>
using namespace std;
int main()
{
	int n =0;
	int k =0;
	while(scanf("%d",&n)!=EOF)
	{
	if(k!=0)
	{
		cout<<endl;
	}
	k++;
		 std::map<string,int> mymap;
		 vector<string>dd;
		for(int  i=0;i<n;i++)
		{
			string s;
			cin>>s;
			dd.push_back(s);
			mymap[s] =0;
		}
		for(int i =0;i<n;i++)
		{
			string x;
			cin>>x;
			int money;
			cin>>money;
			int g =0;
			cin>>g;
			if(g>0)
			{
			int kep = money-(g*int(money/g));
			mymap[x] -=money;
			mymap[x] +=kep;
			}
			for(int i =0;i<g;i++)
			{
				string d;
				cin>>d;
				mymap[d] +=(money/g);
				
			}
		}
		for(int i =0;i<dd.size();i++)
		{
			cout<<dd[i]<<" "<<mymap[dd[i]]<<endl;
		}
	}
	return 0;
}