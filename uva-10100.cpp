#include <vector>
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
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define INF 1<<30
using namespace std;
int LCS(vector<string >a,vector<string>b)
{
	int m = a.size();
	int n = b.size();
	int table[m+1][n+1];
//	for(int i =0;i<m;i++)
	//cout<<a[i]<<"--";

	for(int i =0;i<=m;i++)
	for(int j =0;j<=n;j++)
	table[i][j] = 0;
		//for(int i =0;i<n;i++)
	//cout<<b[i]<<"--";
	for(int i =1;i<=m;i++)
	{
	for(int j =1;j<=n;j++)
	{
		string x =a[i-1];
		string y =b[j-1];
		if(x==y)
		{
		table[i][j] = table[i-1][j-1]+1;
		//cout<<a[i-1];
		}
		else
		table[i][j] = max(table[i][j-1],table[i-1][j]);
	}
	}
	
	return table[m][n];
}
int main()
{
	string s;int kk=1;
	while(getline(cin,s))
	{
		string y;
		getline(cin,y);
		for(int i =0;i<s.size();i++)
		{
			if(!((s[i]>='a' && s[i]<='z')||((s[i]>='A' && s[i]<='Z')) ||(s[i] = ' ')||(s[i]>='0' && s[i]<='9')))
			s[i] = ' ';
		}
		for(int i =0;i<y.size();i++)
		{
			if(!((y[i]>='a' && y[i]<='z')||((y[i]>='A' && y[i]<='Z')) ||(y[i] = ' ')||(s[i]>='0' && s[i]<='9')))
			y[i] = ' ';
		}
		vector<string>vec1;
		vector<string>vec2;
		int last = 0;int len =0;
		for(int i =1;i<s.size();i++)
		{
			if(s[i]==' ')
			{
				 len = i -last;
				vec1.push_back(s.substr(last,len));
				last =i+1;
			}
		}
		vec1.push_back(s.substr(last,s.size()-last));
		last =0;len =0;
		for(int i =1;i<y.size();i++)
		{
			if(y[i]==' ')
			{
				len = i -last;
				vec2.push_back(y.substr(last,len));
				last =i+1;
			}
		}
			vec2.push_back(y.substr(last,y.size()-last));
		for(int i =0;i<vec1.size();)
		{
			string f =vec1[i];
			bool tt =true;
			for(int j =0;j<f.size();j++)
			{
			if(f[j]!=' ')
			tt =false;
			}
			if(tt)
			vec1.erase(vec1.begin()+i);
			else
			i++;
		}
		for(int i =0;i<vec2.size();)
		{
			string f =vec2[i];
			bool tt =true;
			for(int j =0;j<f.size();j++)
			{
			if(f[j]!=' ')
			tt =false;
			}
			if(tt)
			vec2.erase(vec2.begin()+i);
			else
			i++;
		}
			cout<<kk++;
			if(vec1.size()==0 ||vec2.size()==0)
			cout<<". Blank!"<<endl;
			else
			cout<<". Length of longest match: "<<LCS(vec1,vec2)<<endl;
	}
	return 0;
}