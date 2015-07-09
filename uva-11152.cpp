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
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)==3)
	{
		double pi = acos(-1);
		double  s = (a+b+c)/2;
		double outc = pi*a*b*c*a*b*c/(16*s*(s-a)*(s-b)*(s-c));
		double tri = sqrt(s*(s-a)*(s-b)*(s-c));
		double innc =  pi*s*(s-a)*(s-b)*(s-c)/(s*s);;
		outc -=tri;
		tri= tri- innc;
		//cout<<outc<<" "<<tri<<" "<<innc<<endl;
		printf("%.4lf %.4lf %.4lf\n",outc,tri,innc);
	}
	return 0;
}