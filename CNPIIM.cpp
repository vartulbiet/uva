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
	ull n =0;
	scanf("%d",&n);
	
	while(n--)
	{
			ull x =0;
			scanf("%d",&x);
			ull ans =0;
			for(ull i =1;i<=x/2;i++)
			{
				ull j = x-i;
				for(ull r = 1;r<=max(i,j);r++)
				{
					for(ull s =1;s<=max(i,j);s++)
					{
					int c =0;	
						if(r*s<i*j)
						{
							if(i==j)
							c++;
							else
							c=c+2;
						}
						ans+=c;
					}
				}
			}
			printf("%u\n",ans);
	}
	return 0;
}