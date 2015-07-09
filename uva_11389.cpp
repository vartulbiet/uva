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
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	while(a!=0 ||b!=0 ||c!=0)
	{
		vector<int>arr(a);
		vector<int>brr(a);
		for(int i =0;i<a;i++)
		{
			cin>>arr[i];
		}
		for(int i =0;i<a;i++)
		{
			cin>>brr[i];
		}
		sort(arr.begin(),arr.end());
		sort(brr.begin(),brr.end());
		reverse(arr.begin(),arr.end());
		int count  =0;
		for(int  i=0;i<a;i++)
		{
			arr[i] +=brr[i];
		}
		for(int i =0;i<a;i++)
		{
			if(arr[i]>b)
			count +=(arr[i]-b);
		}
		cout<<count*c<<endl;
		cin>>a>>b>>c;
	}
	return 0;
}