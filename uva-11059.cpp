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
using namespace std;
vector<long long>arr;
long long calculate()
{
	long long h =arr.size();long long ans =-(1<<30);
	for(long long i =0;i<h;i++)
	{
		long long mult =1;
		for(long long j =i;j<h;j++)
		{
			mult *= arr[j];
			if(mult >ans)
			ans =mult;
		}
	}
	if(ans<0)
	ans =0;
	return ans;
}
int main()
{
	long long n=0;long long tt =1;
	while(scanf("%d",&n)!=EOF)
	{
		for(long long i =0;i<n;i++)
		{
			long long z =0;
			cin>>z;
			arr.PB(z);
		}
		cout<<"Case #"<<tt++<<": The maximum product is "<<calculate()<<"."<<endl;
		cout<<endl;
		arr.erase(arr.begin(),arr.end());
	}
	return 0;
}