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
#define INF 1<<30
using namespace std;
string s;
void recurse(int x,int y,int a,int b, int m,int n,int p,int q)
{
	if(a!=p || b!=q)
	{
		if(double(a)/double(b)>double(p)/double(q))
		{
			s.PB('L');
		//	cout<<x+a<<" "<<y+b <<"  "<<endl;
			recurse(x,y,x+a,y+b,a,b,p,q);
		}
		else if(double(a)/double(b)<double(p)/double(q))
		{
			s.PB('R');
		//	cout<<m+a<<"-- "<<n+b <<"  "<<endl;
			recurse(a,b,m+a,n+b,m,n,p,q);
		}
	}
	else
	return;
}
int main()
{
	int a,b;
	cin>>a>>b;
	while(!(a==1 && b==1))
	{
		
		recurse(0,1,1,1,1,0,a,b);
		cout<<s<<endl;
		s.erase(s.begin(),s.end());
		cin>>a>>b;
	}
	return 0;
}