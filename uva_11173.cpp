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
#define INF 1<<10
using namespace std;
string s;
vector<string>vec;
void init()
{
	int n = vec.size();
	for(int i = n-1 ; i>=0 ; i--)
	{
		vec.PB(vec[i]);
	}
	for(int i =0;i<n;i++)
	{
		string x = vec[i];
		x.insert(x.begin(),'0');
		vec[i] =x;
	}
	for(int i =n;i<vec.size();i++)
	{
		string x = vec[i];
		x.insert(x.begin(),'1');
		vec[i] =x;
	}
}
long long int To_Decimal(string s)
{
	reverse(s.begin(),s.end());
	int tt =0;
	long long int ans =0;
	for(int i =0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			ans+=(pow(2,tt));
		}
		tt++;
	}
	return ans;
}
int main()
{
	vec.PB("0");
	vec.PB("1");
	int y =0;
	cin>>y;
	for(int i =0;i<y;i++)
	{
		init();
	}
	for(int i = 0;i<y;i++)
	{
		int a,b;
		cin>>a>>b;
		cout<<To_Decimal(vec[b])<<endl;
	}
	return 0;
}