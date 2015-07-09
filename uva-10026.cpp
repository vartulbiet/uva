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
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int t = 0;
		cin>>t;
		vector<pair<double,int> >ans;
		for(int i =0;i<t;i++)
		{
			double a,b;
			cin>>a>>b;
			double z = a/b;
			//cout<<z<<" ";
			ans.push_back(make_pair(z,i+1));
		}
		
		sort(ans.begin(),ans.end());
		for(int i =0;i<ans.size();i++)
		{
		cout<<ans[i].second;
		if(i !=ans.size()-1)
			cout<<" ";
		}
		cout<<endl;
		if(n!=1)
		cout<<endl;
		n--;
	}
	return 0;
}