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
int gg;
int main()
{
	int t =0;
	cin>>t;
	while(t>0)
	{
		int h =0;
		vector<pair<int,int> >vec;
		cin>>h;
		int x,y;
			cin>>x>>y;
		while(x!=0 || y!=0)
		{
			vec.push_back(make_pair(x,-y));
			cin>>x>>y;
		}
		sort(vec.begin(),vec.end());
		pair<int,int>toFind = make_pair(0,h);
		
		vector<pair<int,int> >ans;
		
		/*for(int i =0;i<vec.size();i++)
			cout<<vec[i].first<<" "<<vec[i].second<<endl;
			cout<<"-----------------"<<endl;*/
		for(int i =0;i<vec.size();)
		{
			if(vec[i].first<=toFind.first &&(-vec[i].second)>=toFind.second)
			{
				ans.push_back(vec[i]);
				break;
			}
				else if(vec[i].first<=toFind.first &&(-vec[i].second)<toFind.second && (-vec[i].second)>toFind.first)
				{
					ans.push_back(vec[i]);
					toFind.first = -vec[i].second;
					i++;
				}
				else
				i++;
		}
		cout<<ans.size()<<endl;
		for(int i =0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<-ans[i].second<<endl;
		if(t!=1)
		cout<<endl;
		t--;
	}
	return 0;
}