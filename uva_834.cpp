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
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		int n = a/b;
		int rem = a%b;
		printf("[%d;",n);
		while(rem != 0)
		{
			a  =b;
			b = rem;
			rem = a%b;
			printf("%d",a/b);
			if(rem != 0)
			printf(",");
		}
		printf("]\n");
	}
	return 0;
}