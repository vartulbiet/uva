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
void LIS(vector<pair<int,int> >vec)
{
	vector<int>arr(vec.size());
	fill(arr.begin(),arr.end(),1);
	for(int i =1;i<vec.size();i++)
	{
		for(int j =0;j<i;j++)
		{
			if(vec[j].first<=vec[i].first && vec[j].second<=vec[i].second)
			arr[i]= max(arr[i],arr[j]+1);
		}
	}
	int ans =0;
	for(int i =0;i<vec.size();i++)
	ans = max(arr[i],ans);
	cout<<ans<<endl;
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
		sort(vec.begin(),vec.end());
		LIS(vec);
		cin>>n;
	}
	cout<<"*"<<endl;
	return 0;
}