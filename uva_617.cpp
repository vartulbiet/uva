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
struct node
{
	double d,g,y,r;
};
int main()
{
	int n;
	cin>>n;
	int tt =1;
	while(n>=0)
	{
		vector<struct node>arr;
		for(int i =0;i<n;i++)
		{
			struct node a;
			cin>>a.d>>a.g>>a.y>>a.r;
			arr.PB(a);
		}
		vector<int>brr;
		for(int i=30;i<=60;i++)
		{
			bool bt= true;
			for(int j =0;j<arr.size();j++)
			{
				double t =  (arr[j].d*3600)/i;
				double rem =fmod(t,arr[j].g+arr[j].y+arr[j].r);
				//cout<<rem<<endl;
				if(rem>arr[j].g+arr[j].y)
					bt = false;
			}
			if(bt)
				brr.PB(i);
		}
		vector<pair<int,int> >vec;
		for(int i =0;i<brr.size();i++)
		{
			int j =i;
			for(j = i;j<brr.size();j++)
			{
				if(brr[j]+1 != brr[j+1])
				{
					break;
				}
			}
			vec.PB(make_pair(brr[i],brr[j]));
			i = j;
		}
		cout<<"Case "<<tt++<<":";
		if(vec.size() ==0 )
		{
			cout<<" No acceptable speeds.";
		}
		for(int i =0;i<vec.size();i++)
		{
		if(i!=0)
		cout<<",";
			if(vec[i].first == vec[i].second)
				cout<<" "<<vec[i].first;
			else
				cout<<" "<<vec[i].first<<"-"<<vec[i].second;
		}
		cout<<endl;
		cin>>n;
	}
	return 0;
}