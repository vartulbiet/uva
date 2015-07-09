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
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define pi 3.141592653589793
using namespace std;
double dist(pair<double,double> x,pair<double,double> y)
{
	return sqrt((x.first -y.first)*(x.first -y.first)+(x.second -y.second)*(x.second -y.second));
}
int main()
{
	double x,y,z,m,n,p;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&z,&m,&n,&p)!=EOF)
	{
		double d1 =dist(make_pair(x,y),make_pair(z,m));
		double d2 =dist(make_pair(z,m),make_pair(n,p));
		double d3 =dist(make_pair(n,p),make_pair(x,y));
		if(d1==0 || d2==0 || d3==0)
			printf("0.00\n");
		else
		{
		double s = d1*d2*d3;
		double d =sqrt((d1+d2+d3)*(d1+d2-d3)*(d1+d3-d2)*(d2+d3-d1));
		double ans = 2*pi*s/d;
		printf("%.2lf\n",ans);
		}
	}
	return 0;
}