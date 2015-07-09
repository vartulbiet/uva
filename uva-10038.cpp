#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n =0;
	while(scanf("%d",&n)==1)
	{
		vector<int>arr(n);
		for(int i =0;i<n;i++)
		{
		int x;
		cin>>x;
		arr[i] = x;
		}
		if(n==1)
		{
	cout<<"Jolly"<<endl;
	}
	else
	{
		vector<int>diff;
		for(int i=0;i<n-1;i++)
		{
			diff.push_back(abs(arr[i]-arr[i+1]));
		}
		map<int,bool>mymap;
		for(int i=1;i<n;i++)
		{
			mymap[i] = false;
		}
		for(int i =0;i<diff.size();i++)
		mymap[diff[i]] = true;
		std::map<int,bool>::iterator it;
		for( it=mymap.begin();it!=mymap.end();it++)
		{
			if(it->second == false)
			{
				cout<<"Not jolly"<<endl;
				//cout<<it->first;
				break;
			}
		}
		if(it==mymap.end())
		cout<<"Jolly"<<endl;
		}
	}
	return 0;
}