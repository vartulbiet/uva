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

bool isConvex(vector<pair<int,int> >arr)
{
	int n = arr.size();
	int a=0;
	int b =0;
	double pv = (arr[1].second-arr[0].second)*(arr[n-1].first-arr[0].first) -(arr[1].first-arr[0].first)*(arr[n-1].second-arr[0].second);
		if(pv>1)
		a++;
		if(pv<1)
		b++;
	for(int i =1;i<n-1;i++)
	{
		double pv = (arr[i+1].second-arr[i].second)*(arr[i-1].first-arr[i].first) -(arr[i+1].first-arr[i].first)*(arr[i-1].second-arr[i].second);
		if(pv>1)
		a++;
		if(pv<1)
		b++;
	}
	double dv = (arr[0].second-arr[n-1].second)*(arr[n-2].first-arr[n-1].first) -(arr[0].first-arr[n-1].first)*(arr[n-2].second-arr[n-1].second);
		if(dv>1)
		a++;
		if(dv<1)
		b++;
	if(a==0 ||b==0)
	return false;
	else return true;
	
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		vector<pair<int,int> >vec;
		for(int i =0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			vec.PB(make_pair(x,y));
		}
		if(isConvex(vec))
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		cin>>n;
	}
	return 0;
}