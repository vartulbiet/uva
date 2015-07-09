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
using namespace std;
int limit,dest;
int max_cost;
vector< pair< pair<int,int>,int> >arr;
void recurse(int price,vector< pair< pair<int,int>,int> >temp,vector<bool>vec)
{
	if(max_cost<price)
	max_cost =price;
	for(int i =0;i<arr.size();i++)
	{
		pair< pair<int,int>,int>p= arr[i];
		int tempo =price;
		if(vec[i]== false)
		{
			vector<pair< pair<int,int>,int> >x= temp;
			bool bt =true;
			x.PB(p);
			vector<int>check(dest+1);
			for(int j =0;j<=dest;j++)
			check[j]= 0;
			tempo+=(p.second*(p.first.second-p.first.first));
			for(int j =0;j<=dest;j++)
			{
				for(int k =0 ;k<x.size();k++){
				if((x[j].first.first<=j && x[j].first.second>=j))
				{
					check[j]+=x[j].second;
				}
				}
			}
			for(int j =0;j<=dest;j++)
			if(check[j]>limit)
			bt = false;
			if(bt)
			{
					for(int j =0;j<x.size();j++)
			{
				cout<<x[j].first.first<<" "<<x[j].first.second<<" "<<x[j].second<<"  ----  ";
			}
			cout<<endl;
			for(int j =0;j<=dest;j++)
			cout<<check[j]<<" ";
			cout<<endl;
				vec[i] = true;
				recurse(tempo,x,vec);
				vec[i]=  false;
			}
		}
	}
}
int main()
{
		int loop;
		cin>>limit>>dest>>loop;
		while(limit!=0 && dest!=0 && loop!=0)
		{
			int a,b,c;
			//cout<<limit<<dest<<loop<<endl;
			for(int i =0;i<loop;i++)
			{
				cin>>a>>b>>c;
				//cout<<a<<b<<c<<endl;
				arr.PB(make_pair(make_pair(a,b),c));
				//cin>>a>>b>>c;
			}
			max_cost =0;
			int w =0,r =0;
			vector< pair< pair<int,int>,int> >temp;
			vector<bool>vec;
			for(int i =0;i<loop;i++)
			vec.PB(false);
			recurse(r,temp,vec);
			cout<<max_cost<<endl;
			max_cost =0;
			arr.erase(arr.begin(),arr.end());
			cin>>limit>>dest>>loop;
		}
		return 0;
}