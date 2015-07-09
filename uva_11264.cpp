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
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int x =0;
		cin>>x;
		vector<ull>arr(x);
		ull sum =0;
		map<ull,bool>mymap;
		for(int i =0;i<x;i++)
		{
			cin>>arr[i];
		}
		int c =0;
		int ans =1;
		for(int i =0;i<arr.size()-1;i++)
		{
			if(arr[i]+c<arr[i+1])
			{
				c+=arr[i];
				ans++;
			}
			
		}
		cout<<ans<<endl;
		n--;
	}
	return 0;
}