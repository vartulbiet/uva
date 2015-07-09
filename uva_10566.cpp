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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
double func(double x,double y,double a)
{
	return (1/sqrt(x*x-a*a))+(1/sqrt(y*y-a*a));
}
int main()
{
	double x,y,c;
	while(scanf("%lf%lf%lf",&x,&y,&c)==3)
	{
		double init =0;
		double last =min(x,y);
		double a =0;
		double h =0;
		while(last-init>1e-4)
		{
			a = (init+last)/2;
			h= func(x,y,a);
			if(h>1/c)
			{
				last =a;
			}
			else
			{
				init =a;
			}
		}
		printf("%.3lf\n",a);
	}
	return 0;
}