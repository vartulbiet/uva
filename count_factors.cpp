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

const int max_n = 31625;
vector<ull> primes;
bool sieve[max_n];
ull get_max(int n,int m)
{
	if(n%m!=0)
	return 0;
	else
	return 1+get_max(n/m,m);
}
ull count(ull n)
{
	vector<ull>pp;
	for(int i =0;i<primes.size();i++)
	{
		if(n%primes[i] ==0)
		{
			pp.PB(primes[i]);
		}
	}
	ull c =1;
	for(int i =0;i<pp.size();i++)
	{
		c*=(get_max(n,pp[i])+1);
	}
	return c;
}
 
void sieveOfAtkin(){
   int N = sqrt(max_n);
   memset(sieve, 0, sizeof(sieve));
   for (int x = 1; x <= N; x++){
      for (int y = 1; y <= N; y++){
         int n = (4*x*x)+(y*y);
         if (n <= max_n && (n % 12 == 1 || n % 12 == 5))
            sieve[n] ^= true;
         n = (3*x*x)+(y*y);
         if (n <= max_n && n % 12 == 7)
            sieve[n] ^= true;
         n = (3*x*x)-(y*y);
         if (x > y && n <= max_n && n % 12 == 11)
            sieve[n] ^= true;
      }
   }
   sieve[2] = sieve[3] = true;
   primes.push_back(2);
   primes.push_back(3);
   int a;
   for (a = 5; a <= N; a+=2){
      if (sieve[a]){
         for (int i = a*a; i < max_n; i += a*a)
            sieve[i] = false;
         primes.push_back(a);
      }
   }
   for (; a < max_n; a+=2) if (sieve[a])
      primes.PB(a);
}
int arr[1570000];
int main()
{
	sieveOfAtkin();
	for(ull i=1;i<1570000;i++)
	{
		ull c=0;arr[i] = 0;
		arr[i]=count(i)+arr[i-1];
		cout<<i<<" ";
	}
	ull n =0;
	cin>>n;
	while(n--)
	{
			ull x =0;
			cin>>x;
			ull ans =0;
			for(ull i =1;i<=x/2;i++)
			{
				ull j = x-i;
				if(i!=j)
				{
					ans += 2*(arr[i*j-1]);
				}
				else
					ans +=arr[i*j-1];
			}
			printf("%u\n",ans);
	}
	return 0;
}