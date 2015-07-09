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
int main()
{
	int t =0;
	while(scanf("%d",&t)==1)
	{
		vector<pair<int,int> >vec;
		for(int i =t+1;i<=2*t;i++)
		{
			double j  = (double)(t*i)/(double)(i-t);
			long long m =(t*i)/(i-t);
			if(j==double(m))
			{
				//cout<<j<<"   "<<m<<endl;
			vec.push_back(make_pair(i,m));
			}
			
		}
		cout<<vec.size()<<endl;
		for(int i =0;i<vec.size();i++)
		{
			cout<<"1"<<"/"<<t<<" = "<<"1/"<<vec[i].second<<" + "<<"1/"<<vec[i].first<<endl;
		}
	}
	return 0;
}