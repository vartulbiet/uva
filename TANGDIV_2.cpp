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

int main()
{
	int n = 0;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);

		vector<pair<int,int> >vec,dec;
		
		for(int i =0;i<b;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			vec.PB(make_pair(x,y));
		}
		for(int i =0;i<c;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			dec.PB(make_pair(x,y));
		}
		bool bt =true;

		for(int i =0;i<b && bt;i++)
		{
			bool ct =true;
			for(int j =0;j<c &&bt;j++)
			{
				int a = vec[i].first;
				int b =vec[i].second;
				int x = dec[j].first;
				int y =dec[j].second;
				cout<<a<<b<<" "<<x<<y<<endl;
				if(a<=b && x<=y)
				{
					if(!(a>=x && b<=y))
						ct =false;
					
				}
				else if(a<=b && x>y)
				{
					if(!(y<=a && a<=x && y<=b && b<=x) ||(!x<=a && x<=b) ||(a<=y && b<=y))
					ct =false;
				}
				else if(a>b && x>y)
				{
					if(!(a>=x && b<=y))
						ct =false;
				}
				else
				{
					if(!(b<x && y<a) ||!(a==y &&b<x)||!(b ==x &&y<a))
					ct =false;
				}
			}
			if(!ct)
				bt = false;
		}
		if(bt)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		vec.erase(vec.begin(),vec.end());
	}
	return 0;
}