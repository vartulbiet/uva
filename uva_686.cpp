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
vector<int>primes(50000);
void g_primes()
{
	fill(primes.begin(),primes.end(),false);
	primes[2] = true;
	primes[3] = true;
	primes[5] = true;
	
	for(int i =6;i<50000;i++)
	{
		int y = sqrt(i);bool bt = true;
		for(int k = 2;k<=y+1 && bt;k++)
		{
			if(i%k == 0)
			bt = false;
		}
		if(bt)
		primes[i] = true;
	}
}
int main()
{
	g_primes();
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int c =0;
		for(int i =2;i<=n/2;i++ )
		{
			if(primes[i] && primes[n-i])
			c++;
		}
		cout<<c<<endl;
		cin>>n;
	}
	return 0;
}