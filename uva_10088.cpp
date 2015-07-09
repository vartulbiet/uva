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
ll gcd(ll x,ll y)
{
	ll temp =x;
	while(y!=0)
	{
		temp = y;
		y =x%y;
		x = temp;
	}
	return x;
}
ll get_area(ll*arr,ll*brr,ll n)
{
	ll area = 0;
	for(ll i =0;i<=n-1;i++)
	{
		area += (arr[i]*brr[(i+1)%n] - arr[(i+1)%n]*brr[i]);
	}
	return labs(area);
}
ll getpoints(ll*arr,ll*brr,ll x,ll y,ll n)
{
	ll a = labs(arr[x] -arr[y]);
	ll b = labs(brr[x] -brr[y]);
	//cout<<gcd(a,b)<<endl;
	if(a == 0 )
	return b-1;
	if(b ==0 )
	return a-1;
	else return gcd(a,b)-1;
}
int main()
{
	ll b =0;
	scanf("%lld",&b);
	while(b!=0)
	{
		ll*arr = (ll*)malloc(sizeof(ll)*b);
		ll*brr = (ll*)malloc(sizeof(ll)*b);
		for(ll i =0;i < b;i++)
		{
			scanf("%lld%lld",&arr[i],&brr[i]);
		}
		ll A = get_area(arr,brr,b);
		//cout<<A<<endl;
		ll x =b;
		
		for(ll i = 0;i < b;i++)
		{
			x+=getpoints(arr,brr,i,(i+1)%b,b);
		}
		//cout<<x<<endl;
		printf("%lld\n",(A+2-x)>>1);
		scanf("%lld",&b);
	}
	return  0;
}