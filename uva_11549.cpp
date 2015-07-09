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
int len(unsigned long long n) {
  return log10(n) + 1;
}
ull stringTo(ull num,int n)
{
	int l = len(num);
	while(l>n)
	{
	num/=10;
	l--;
	}
	return num;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		ull n,k;
		cin>>n>>k;
		map<ull,bool>mymap;
		ull maxt =k;
		while(mymap[k] != true)
		{
			mymap[k] = true;
			k*=k;//cout<<k<<"   ";
			k = stringTo(k,n);//cout<<k<<endl;
			maxt= max(maxt,k);
		}
		cout<<maxt<<endl;
	}
	return 0;
}