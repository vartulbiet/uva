#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int main()
{
	int a,b= 0;
	cin>>a>>b;
	int kk =1;
	while(a!=0 ||b!=0)
	{
		string x;
		if(kk!=1)
		cout<<endl;
		getline(cin,x);
		for(int i =0;i<a;i++)
		{
			string s;
			getline(cin,s);
		}vector<pair<int ,float> >vec;
		map<int,string>mymap;
		for(int i =0;i<b;i++)
		{
			string s;
			getline(cin,s);
			float f;int z;
			cin>>f>>z;
			string p;
			getline(cin,p);
			for(int j =0;j<z;j++)
			{
				string t;
			getline(cin,t);
			}
			vec.push_back(make_pair(z,f));
			mymap[i] = s;
		}
		//sort(vec.begin(),vec.end());
		pair<int,float>ans;
		ans.first =0;
		ans.second =0;
		int y =0;
		for(int i =vec.size()-1;i>=0;i--)
		{
		//cout<<vec[i].first<<" "<<vec[i].second<< " "<<ans.first<<" "<<ans.second<<endl;
			if(vec[i].first >ans.first)
			{
				ans = vec[i];
				y =i;
			}
			else if(vec[i].first == ans.first)
			{
				if(vec[i].second<=ans.second)
				{
					ans =vec[i];
					y =i;
				}
			}
		}
		cout<<"RFP #"<<kk++<<endl;
		cout<<mymap[y]<<endl;
		cin>>a>>b;
	}
	return 0;
}