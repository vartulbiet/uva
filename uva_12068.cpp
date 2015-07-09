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
ll get_gcd(ll x,ll y)
{
	ll temp =x;
	while(y!=0)
	{
		temp =y;
		y =x%y;
		x =temp;
	}
	return x;
}
int main()
{
	int n =0;
	cin>>n;
	int tt=1;
	while(n--)
	{
		int y =0;
		cin>>y;
		int *arr = (int*)malloc(sizeof(int)*y);
		for(int i =0;i<y;i++)
		cin>>arr[i];
		ll *multiply = (ll*)malloc(sizeof(ll)*y);
		ll *mult = (ll*)malloc(sizeof(ll)*y);
		multiply[0]= 1;
		long long int mux =arr[0];
		mult[y-1] =1;
		for(int i =1;i<y;i++)
		{
			multiply[i] = multiply[i-1]*arr[i-1];
			mux *=arr[i];
		}
		for(int i = y-2;i>=0;i--)
		{
			mult[i] = mult[i+1]*arr[i+1];
		}
		
		ll sum =0;
		for(int i =0;i<y;i++)
		{
			sum+=(multiply[i]*mult[i]);
		}
		cout<<"Case "<<tt++<<": ";
		ll gcd = get_gcd(sum,y*mux);
		cout<<((y*mux)/gcd)<<"/"<<sum/gcd<<endl;
	}
	return 0;
}