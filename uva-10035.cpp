#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30

using namespace std;
vector<int> getInt(long long x)
{
	vector<int> c;
	while(x>=10)
	{
		c.push_back(x%10);
		x =x/10;
	}
	c.push_back(x);
	//reverse(c.begin(),c.end());
	return c;
}
int main()
{
	long long a,b;
	cin>>a>>b;
	while(a>0 || b>0)
	{
		vector<int> c =getInt(a);
		vector<int> d =getInt(b);
		int n = max(c.size(),d.size());
		int ans =0;
		int carry=0;
		for(int i =0;i<n;i++)
		{
			int t =0;
			if(i<c.size())
			t +=c[i];
			if(i<d.size())
			t +=d[i];
			if(t+carry>9)
			{
			ans++;
			carry =1;
			}
			else
			carry =0;
		}
			if(ans == 0)
			cout<<"No carry operation."<<endl;
			else
			{
			if(ans ==1)
			cout<<ans<<" carry operation."<<endl;
			else
			cout<<ans<<" carry operations."<<endl;
			}
			cin>>a>>b;
	}
	return 0;
}