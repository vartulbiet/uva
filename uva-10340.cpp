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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int LCS(string a,string b)
{
	int m =a.size();
	int n =b.size();
	int table[m+1][n+1];
	//cout<<a<<b;
	for(int i =0;i<m+1;i++)
	{
		for(int j =0;j<n+1;j++)
		table[i][j] = 0;
	}
	
	for(int i =1;i<m+1;i++)
	{
		for(int j =1;j<n+1;j++)
		{
			if(a[i-1]==b[j-1])
			table[i][j] = table[i-1][j-1]+1;
			else
			table[i][j] = max(table[i-1][j],table[i][j-1]);
		}
	}
	return table[m][n];
}
int main()
{	
	string s,t;
	while(cin>>s>>t)
	{
		if (LCS(s,t) == s.size())
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}