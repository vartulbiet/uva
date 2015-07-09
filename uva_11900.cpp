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
	int n =0;
	cin>>n;
	int tt =1;
	while(n--)
	{
		int a,p,q;
		cin>>a>>p>>q;
		vector<int>arr(a);
		for(int i =0;i<a;i++)
		cin>>arr[i];
		//cout<<a<<p<<q<<endl;
		int sum =0;int ct =0;
		int k =0;
		while(sum+arr[k]<=q && p>0 && a>0)
		{
			sum +=arr[k];
			k++;
			p--;
			ct++;
			a--;
		}
		cout<<"Case "<<tt++<<": "<<ct<<endl;
	}
	return 0;
}