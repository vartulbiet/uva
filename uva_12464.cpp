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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
int main()
{
	ull a,b,uu;
	cin>>a>>b>>uu;
	while(a!=0 || b!=0 || uu!=0)
	{
		vector<ull>p;
		ull c = (1+b)/a;
		ull d = (b+a+1)/(a*b);
		ull e = (a+1)/b;
		//cout<<a<<b<<c<<d<<e<<endl;
		p.PB(a);p.PB(b);p.PB(c);p.PB(d);p.PB(e);
		ull h = uu%5;
		//cout<<h<<" ";
		cout<<p[h]<<endl;
		cin>>a>>b>>uu;
		//cout<<a<<b<<uu<<endl;
	}
	return 0;
}