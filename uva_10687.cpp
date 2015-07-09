#include<iostream>
#include<vector>
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
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
double dist(int x,int y,int a,int b)
{
	return sqrt((x-a)*(x-a) + (y-b)*(y-b));
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		map<pair<int,int> ,bool>mymap;
		vector<pair<int,int> >vec;
		for(int i =0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			vec.PB(make_pair(x,y));
			mymap[make_pair(x,y)] =  false;
		}
		sort(vec.begin(),vec.end());
		for(int i =0;i<n;i++)
		{
			double d1 =INF,d2 =INF;int ind1 =INF;int ind2 =INF;
			for(int j =0;j<n;j++)
			{
				if(i!=j)
				{
					double x = dist(vec[i].first,vec[i].second,vec[j].first,vec[j].second);
					if(x<d1)
					{
						d2 =d1;
						d1 =x;
						ind2 =ind1;
						ind1 =j;
					}
					else if(x==d1 && d1!=d2)
					{
						d2 =x;
						ind2 =j;
					}
					else if(x<d2)
					{
						d2 = x;
						ind2 =j;
					}
				}
			}
			if(ind1!=INF)
			mymap[vec[ind1]] = true;
			if(ind2!=INF)
			mymap[vec[ind2]] = true;
		}
		bool bt =  true;
		for(std::map<pair<int,int> ,bool>::iterator it = mymap.begin();it!=mymap.end();it++)
		{
			if(it->second == false)
			bt = false;
		}
		if(bt)
		{
			cout<<"All stations are reachable."<<endl;
		}
		else
			cout<<"There are stations that are unreachable."<<endl;
			cin>>n;
	}
	return 0;
}