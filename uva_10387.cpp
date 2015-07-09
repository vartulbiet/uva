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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int main()
{
	double a,b,s,m,n;
	cin>>a>>b>>s>>m>>n;
	while(a!=0 && b!=0 && s!=0 && m!=0 && n!=0)
	{
		printf("%.2lf ",atan(n*b/(m*a))*180/pi);
		printf("%.2lf\n",sqrt(a*a*m*m+b*b*n*n)/s);
		cin>>a>>b>>s>>m>>n;
	}
	return 0;
}