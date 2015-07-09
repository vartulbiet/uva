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
	double a,b;
	cin>>a>>b;
	while(a!=0 || b!=0)
	{
		if(b>=a)
		cout<<"0"<<endl;
		else if(b==0)
			cout<<a<<endl;
		else
		{
		double  i =b;
		double maxy =0;int s =0;
		for( i = 1;i<=a/b;i++)
		{
			double x =i*0.3*sqrt(a/i-b);
			if(maxy<x)
			{
				s =i;
				maxy =x;
			}
		}
		int t=0;
		for( i = 1;i<=a/b;i++)
		{
			double x =i*0.3*sqrt(a/i-b);
			if(x==maxy)
			{ 
			t++;}
		}
		if(t>1)
		cout<<"0"<<endl;
		else
		cout<<s<<endl;
		}
		//cout<<endl;
		cin>>a>>b;
	}
	return 0;
}