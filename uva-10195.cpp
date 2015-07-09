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
using namespace std;
int main()
{
	double x,y,z;
	while(scanf("%lf%lf%lf",&x,&y,&z)!=EOF)
	{
	if(x==0 || y==0 || z==0)
    printf("The radius of the round table is: 0.000\n");
	else
	{
		double s =(x+y+z)/2;
		double ans = sqrt(s*(s-x)*(s-y)*(s-z));
		ans =ans/s;
		printf("The radius of the round table is: %.3lf\n",ans);
		}
	}
	return 0;
}