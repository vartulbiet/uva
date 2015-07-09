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
bool comparefunc(pair<int,int>x,pair<int,int>y)
{
	if(x.first<y.first)
	return true;
	else if(x.first==y.first)
	{
		if(x.second<y.second)
		return true;
		else return false;
	}
	return false;
}
int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		vector<pair<double,double> >arr;
		bool bt= true;
		double f=0;
		f=c/2.0;
		for(int i =0;i<a;i++)
		{
			int x,y;
			cin>>x>>y;
			double dis = y*y - f*f;
			dis =sqrt(dis);
			if(y>=f)
			arr.PB(make_pair(x-dis,x+dis));
		}
		vector<pair<double,double> >ans;
		//vector<pair<int,int> >arr;
		if(arr.size()==0)
		bt=false;
		else{
		sort(arr.begin(),arr.end());
		double y=0;int used =0;
		for(int i= 0;i<arr.size();i++)
		{
			if(arr[i].first<=0)
			{
				if(arr[i].second>y)
				{
						used = i;
						y = arr[i].second;
				}
			}
			else break;
		}
		ans.PB(arr[used]);int last =0;
		double mac = ans[last].second;
		double tac =ans[last].first;
		for(int i =used+1;i<arr.size();)
		{
			vector<pair<double,double> >temp;bool bt = false;
			while(i<arr.size() && arr[i].first<=ans[last].second && arr[i].first>ans[last].first && arr[i].second>ans[last].second && ans[last].second<b && mac<arr[i].second)
			{
				 mac = arr[i].second;
				 tac = arr[i].first;
				i++;bt= true;
			}
			if(bt){
			ans.PB(make_pair(tac,mac));
			last++;}
			else
			i++;;
		}
		
		if(!(ans[0].first<=0 && ans[ans.size()-1].second>=b))
			bt= false;}
		if(bt)
		cout<<ans.size()<<endl;
		else
		cout<<"-1"<<endl;
	}
	return 0;
}