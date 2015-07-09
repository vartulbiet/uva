#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<math.h>
#include<cstdio>
#define INF 1<<20
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	float x,y;
	string z;
	while(scanf("%f%f",&x,&y)==2)
	{
		cin>>z;
		x=x+6440.00;
		float ans =0;
		float ang;
		float PI =4*atan(1);
		if(z=="min")
		ang = 4*atan(1)*y/(180*60);
		else
		ang  = 4*atan(1)*y/180;
		ans =x*ang;
		float ans2;
		ans2 = 2*x*sin(ang/2);
		printf("%.6f %.6f\n",ans,ans2);
	}
	return 0;
}