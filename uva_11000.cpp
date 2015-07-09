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
#define MP make_pair
#define INF 1<<30
using namespace std;
pair<ull,ull> func(ull n)
{
	if(n==0)
	return MP(0,0);
	if(n == 1)
	return MP(1,0);
	else
	{
	pair<ull,ull>p =func(n-1);
	return MP(1+p.second+p.first,p.first);
	}
}
int main()
{
	ull n =0;
	cin>>n;
	while(n!=-1)
	{
		pair<ull,ull>p = func(n);
		cout<<p.first<<" "<<1+p.first+p.second<<endl;
		cin>>n;
	}
	return 0;
}