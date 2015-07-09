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
using namespace std;
int main()
{
	int n =0;
	scanf("%d",&n);
	while(n>0)
	{
		unsigned long long a,b,c,d;
		scanf("%llu%llu%llu%llu",&a,&b,&c,&d);
		bool bt = false;
		unsigned long long temp = c+d*c;
		unsigned long long val = 1+d;
		if(c>=a && b==1)
		bt = true;
		else if(c<a && b==1)
		bt = false;
		else
		{
		while(b>1)
		{
		if(a<=temp)
			{
			//cout<<temp<<endl;
			bt = true;
			break;
			}
			temp = temp*val;
			b--;
			
		}
		}
		if(bt)
		printf("ALIVE AND KICKING\n");
		else
		printf("DEAD AND ROTTING\n");
		n--;
	}
	return  0;
}