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
vector<ll>primes;
bool arr[10000010];
void seive()
{
	ll n = 10000010;
	memset(arr,false,sizeof(arr));
	for(ll i = 2;i<=50000+1;i++)
	{
		if(arr[i] == false)
		{
			for(long long j = i * i; j <= 50000 + 1; j += i)
			arr[j] = true;
			primes.PB(i);
		}
	}
}
vector<ll> prime_factors(ll n) {
    vector<ll> factors;
    ll pf_index = 0;
    ll pf = primes[pf_index];
 
    while(pf * pf <= n) {
        while(n % pf == 0) {
            n /= pf;
            factors.push_back(pf);
        }
        pf = primes[++pf_index];
    }
    if(n != 1)
        factors.push_back(n);
 
    return factors;
}
 
int main()
{
	long long int  n =0;
	cin>>n;
	seive();
	while(n!=0)
	{
		long long int y = labs(n);
		vector<ll>factors = prime_factors(y);
		ll u = y;
		
		if(n != u)
		factors.insert(factors.begin(),-1);
		cout<<n<<" = ";
		for(int i =0;i<factors.size();i++)
		{
			if(i!=0)
			cout<<" x ";
			cout<<factors[i];
		}
		cout<<endl;
		cin>>n;	
	}
	return  0;
}