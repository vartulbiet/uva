#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n =0;
	cin>>n;
	string s;
	int index =0;
	string value;
	getline(cin,s);
	while(n>0)
	{
		getline(cin,s);
		string line1,line2;
		
		getline(cin, line1);
        getline(cin, line2);
		stringstream ss1(line1);
		stringstream ss2(line2);
			vector<pair<int,string> >vec;
		while(ss1>>index)
		{
			ss2>>value;
			vec.push_back(make_pair(index,value));
		}
		sort(vec.begin(),vec.end());
		for(int i =0;i<vec.size();i++)
		{
		cout<<vec[i].second<<endl;
		}
		if(n!=1)
		cout<<endl;
		n--;
	}
	return 0;
}