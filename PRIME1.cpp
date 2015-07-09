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


void seiveOFAtkin(ull start,ull end)
{
	bool* isPrime= (bool*)malloc(sizeof(bool)*(end-start+1));
	for(int i =0;i<=end-start;i++)
	{
		isPrime[i] = false;
	}
	ull sqrtEnd= sqrt(end);
	ull sqrtStart = sqrt(start);
	for (ull x = sqrtStart; x <= sqrtEnd; x++)
	{
        for (ull y = sqrtStart; y <= sqrtEnd; y++)
        {
            ull n = 4 * x * x + y * y;
 
                    if (n <= end && n >= start && (n % 12 == 1 || n % 12 == 5))
                    {
                        isPrime[n-start] = !isPrime[n-start];
                    }
 
                    n = 3 * x * x + y * y;
 
                    if (n <= end && n >= start && (n % 12 == 7))
                    {
                        isPrime[n-start] = !isPrime[n-start];
                    }
 
                    if (x > y)
                    {
                        n = 3 * x * x - y * y;
 
                            if (n <= end && n >= start && n % 12 == 11)
                            {
                                isPrime[n-start] = !isPrime[n-start];
                            }
                    }
        }
	}
	for (ull n = start; n <= end; n++)
{
        if (isPrime[n-start])
        {
            ull omit = n * n;
 
                    for (ull k = omit; k <=end; k +=omit)
                    {
                        isPrime[k-start] = false;
                    }
        }
}
	ull count =0;
	if(start<5)
	count+=2;
	for(ull i =start;i<=	end;i++)
	{
		if(isPrime[i-start]){cout<<i<<" ";
			count++;}
	}
	cout<<endl;
	cout<<count<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		ull x,y;
		cin>>x>>y;
		seiveOFAtkin(x,y);
	}
	return 0;
}