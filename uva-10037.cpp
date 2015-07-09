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
	int n =0;
	cin>>n;
	while(n>0)
	{
		int t =0;
		cin>>t;
		if(t>0)
		{
			if(t>1)
			{
				vector<int>vec(t);
				for(int i =0;i<t;i++)
				cin>>vec[i];
				
				sort(vec.begin(),vec.end());
				int x =vec[0];
				int y = vec[1];
				vector<pair<int,int> >p;
				vector<int >q;
				p.push_back(make_pair(y,x));
				vec.erase(vec.begin());
				vec.erase(vec.begin());
				q.push_back(x);
				reverse(vec.begin(),vec.end());
				for(int i =0;i<vec.size()-1;i=i+2)
				{
					p.push_back(make_pair(vec[i],vec[i+1]));
					p.push_back(make_pair(y,x));
				}
				for(int i =0;i<vec.size()-1;i++)
				{
					if(i%2==0)
					q.push_back(y);
					else
					q.push_back(x);
				
				}
				
				if(vec.size()%2!=0)
				p.push_back(make_pair(vec[vec.size()-1],x));
				
				int sum =0;
				for(int i =0;i<p.size();i++)
				{
				sum = sum+ p[i].first;
				if(i<q.size())
				sum += q[i];
				}
				cout<<sum<<endl;
				for(int i =0;i<p.size();i++)
				{
				cout<<p[i].second<<" "<<p[i].first<<endl;
				if(i<q.size())
				cout<<q[i]<<endl;
				}
			}
			else
			{
				int z;
				cin>>z;
				cout<<z<<endl;
				cout<<z<<endl;
			}
		}
		else
			cout<<t<<endl;
			if(n!=1)
			cout<<endl;
		n--;
	}
	return 0;
}