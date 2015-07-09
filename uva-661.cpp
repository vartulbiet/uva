#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int main()
{
	int a,b,c;
	int hh = 1;
	cin>>a>>b>>c;
	while(a!=0 ||b!=0 ||c!=0)
	{
	cout<<"Sequence "<<hh++<<endl;
	map<int,pair<int,bool> >mymap;
		for(int i =0;i<a;i++)
		{
		int x =0;
		cin>>x;
		mymap[i+1] =make_pair(x,false);
		}
		int sum =0;
		int j =0;int max_p =0;
		bool cc = true;
		for( j =0;j<b;j++)
		{
			int t =0;
			cin>>t;
			if(mymap[t].second== false)
			{
			mymap[t].second = true;
			sum +=mymap[t].first;
			}
			else
			{
				mymap[t].second = false;
			sum -=mymap[t].first;
			}
			if(sum>c)
			{
				cc= false;
			}
			if(max_p<sum)
			max_p= sum;
		}
		if(cc)
		{
		cout<<"Fuse was not blown."<<endl;
		cout<<"Maximal power consumption was "<<max_p<<" amperes.";
		}
		else
		cout<<"Fuse was blown.";

		cout<<endl;
		cout<<endl;
		cin>>a>>b>>c;
	}
	return 0;
}