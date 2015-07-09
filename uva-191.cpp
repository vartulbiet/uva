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
		int a,b,c,d,e,f,g,h;
		cin>>a>>b>>c>>d>>e>>f>>g>>h;
		double m = (b-d)/(a-c);
		double r = b-m*a;
		int i =0;
		bool bt =false;
		for(i = min(a,c);i<=max(a,c);i++)
		{
			int y = m*i + r;
			if((i>=e && i<=g) && (y>=h && y<=f))
			{
			bt =true;//cout<<i<<e<<g<<" "<<y<<h<<f<<endl;
			}
		}
		if(bt ==true)
		cout<<"T"<<endl;
		else
		cout<<"F"<<endl;
		n--;
	}
	return 0;
}