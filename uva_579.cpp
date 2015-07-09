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
	string s;
	getline(cin,s);
	while(s!="0:00")
	{
		string x,y;bool bt = true;
		for(int i =0;i<s.size();i++)
		{
			if(s[i]==':')
			bt= false;
			else
			{
			if(bt)
				x.PB(s[i]);
			else
				y.PB(s[i]);
			}
		}
		int t =0;int kk =1;
		for(int i =x.size()-1;i>=0;i--)
		{
			t +=((x[i]-'0')*kk);
			kk*=10;
		}
		int v =0;int kkk =1;
		for(int i =y.size()-1;i>=0;i--)
		{
			v +=((y[i]-'0')*kkk);
			kkk*=10;
		}
		if(t==12)
		t=0;
		double ttt = v*6.0;
		double r = v*0.5;
		double z = t*30;
		z=z+r;
	if(abs(z-ttt)>180)
		printf("%.3lf",360-abs(z-ttt));
		else
		printf("%.3lf",abs(z-ttt));
		cout<<endl;
		getline(cin,s);
	}
	return 0;
}