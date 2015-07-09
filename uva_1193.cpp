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
double get_val(pair<int,int>p,int n)
{
	int x = p.first;
	int y = p.second;
	double f;
	f= sqrt(double(n*n)-(y*y));
	return f;
}

int main()
{
	int m,n;
	cin>>m>>n;
	int tt =1;
	while(m!=0 || n!=0)
	{
		bool bt = true;
		vector<pair<int,int> >vec;
		for(int i =0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			if(y>n)
			bt = false;
			vec.PB(make_pair(x,y));
		}
		sort(vec.begin(),vec.end());
		cout<<"Case "<<tt++<<": ";
		if(bt)
		{	
			int c =1;
			double f =0;
			f = get_val(vec[0],n);
			double lx = vec[0].first - f;
			double rx = vec[0].first + f;
			for(int i =0;i<vec.size();i++)
			{
				double g = get_val(vec[i],n);
				double llx = vec[i].first - f ;
				double rrx = vec[i].first + f;
				if (llx <= rx && rrx >= lx) 
                { 
					lx = (lx < llx) ? llx : lx; 
                    rx = (rx > rrx) ? rrx : rx; 
                } 
                else
				{ 
                    c++; 
                    lx = llx; 
                    rx = rrx; 
                }  
			}
			cout<<c<<endl;
		}
		else
		cout<<"-1"<<endl;
		cin>>m>>n;
	}
	return 0;
}