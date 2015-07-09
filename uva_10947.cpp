#include <iostream>
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
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
using namespace std;
#define INF 1<<20
double graph[200][200];
struct Point
{
	int x,y;
};
double distance( Point p1,Point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n) == 2)
	{
		Point start,end;
		int r1,int r2;
		cin>>start.x>>start.y>>r1;
		cin>>end.x>>end.y>>r1;
	}
	return 0;
}