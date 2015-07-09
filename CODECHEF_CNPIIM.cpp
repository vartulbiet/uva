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
long long int fun(long long int c)
{
	long long int cost =0;long long int sq=  sqrt(c);
for(long long int k =1;k<=sq;k++)
		{
			cost+=c/k;
		}
		cost = 2*cost - sq*sq;
		//cout<<c<<" "<<cost<<endl;
	return cost;
}
int main()
{
	int n =0;
	scanf("%d",&n);
	
	while(n--)
	{
			long long int x =0;
			scanf("%lld",&x);
			long long int ans =0;
			for(long long int i =1;i<=x/2;i++)
			{
				long long int j = x-i;
				long long int val =0 ;
				long long int yy =i*j-1;
					val+=fun(yy);
				if(i==j)
				ans+=val;
				else
				ans+=(val*2);
			}
			printf("%lld\n",ans);
	}
	return 0;
}