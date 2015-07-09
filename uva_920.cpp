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
	while(n--)
	{
		int sz =0;
		cin>>sz;
		vector<pair<int,int> >vec;
		for(int i =0;i<sz;i++)
		{
			int a,b;
			cin>>a>>b;
			vec.PB(make_pair(a,b));
		}
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		int max_height_till = 0;
		double ans =0;
		for(int i =1 ;i<vec.size();i++)
		{
			if(vec[i].second>max_height_till)
			{
				
				ans  = ans + sqrt((vec[i].second-vec[i-1].second)*(vec[i].second-vec[i-1].second) + (vec[i].first-vec[i-1].first)* (vec[i].first-vec[i-1].first))*(vec[i].second-max_height_till)/(vec[i].second-vec[i-1].second);
				max_height_till = vec[i].second;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}