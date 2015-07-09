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
struct P
{
	double x,y;
} arr[10001];

bool compareX(P p,P q)
{
	if(p.x < q.x)
	return true;
	else
	return false;
}
double dist(P p,P q)
{
	double d =(p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
	return sqrt(d);
}

double solve(int n)
{
	double mint =dist(arr[0],arr[1]);
		for(int i =0;i<n;i++)
		{
			for(int j=i+1;j<n && (arr[j].x-arr[i].x)<mint ;j++)
			mint = min(mint,dist(arr[i],arr[j]));
		}
	return mint;
}
int main()
{
	int n =0;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i =0;i<n;i++)
		{
			double a,b;
			scanf("%lf%lf",&a,&b);
			arr[i].x =a;
			arr[i].y =b;
		}
		double ans =0;
		if(n>1)
		{
		sort(arr,arr+n,compareX);
		ans =solve(n);
		}
		if(ans>10000 || (fabs(ans - 10000.0) < 0.00001) ||n==1)
		cout<<"INFINITY"<<endl;
		else
		printf("%.4lf\n",ans);
		cin>>n;
	}
	return 0;
}