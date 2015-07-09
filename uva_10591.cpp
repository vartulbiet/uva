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
map<long long int,bool>mymap;
long long int squr(long long int c)
{
	vector<int>val;
	while(c!=0)
	{
		val.PB(c%10);
		c =c/10;
	}
	long long int sum =0;
	for(int i =0;i<val.size();i++)
	{
		sum +=(val[i]*val[i]);
	}
	return sum;
}
bool recurse(long long int x)
{
	if(x==1)
	return true;
	else if(mymap[x] == true)
	return false;
	else
	{
		mymap[x] = true;
		return recurse(squr(x));
	}
}
int main()
{
	long long int  z =0;int tt =1;
	int t =0;
	cin>>t;
	while(t>0)
	{
	scanf("%lld",&z);
		bool bt= recurse(z);
		mymap.erase(mymap.begin(),mymap.end());
		if(bt)
		{
			cout<<"Case #"<<tt++<<": "<<z<<" is a Happy number."<<endl;
		}
		else
			cout<<"Case #"<<tt++<<": "<<z<<" is an Unhappy number."<<endl;
			t--;
	}
	return 0;
}