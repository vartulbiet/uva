#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<cstdio>
#define INF 1<<30
#include<algorithm>
using namespace std;

int main()
{
	int n =0;string dummy;
	cin>>n;
	while(n>0)
	{
		getline(cin,dummy);
		vector<string>vec;
		for(int i =0;i<n;i++)
		{
			string s;
			getline(cin,s);
			vec.push_back(s);
		}
		vector<int>c;int mint = INF;
		for(int i =0;i<n;i++)
		{
		string s = vec[i];int sum =0;
		for(int j =0;j<s.size();j++)
		{
			if(s[j]=='B')
			sum++;
		}
		c.push_back(sum);
		mint  = min(mint,sum);
		}
		int ans =0;
		for(int i =0;i<c.size();i++)
		{
		ans+=(c[i]-mint);
		}
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}