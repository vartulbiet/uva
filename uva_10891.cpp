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
#define INF 1<<30
using namespace std;
vector<int>ans;
int get_min()
{
	int max_sum =ans[0];
	int curr_sum =ans[0];
	int pos =0;
	for(int i =1;i<ans.size();i++)
	{
		curr_sum +=ans[i];
		if(curr_sum<max_sum)
		{
			max_sum = curr_sum;
			pos =i;
		}
	}
	vector<int>rev = ans;
	reverse(rev.begin(),rev.end());
	int max_sum2 =rev[0];
	int curr_sum2 =rev[0];
	int pos2 =0;
	for(int i =1;i<rev.size();i++)
	{
		curr_sum2 +=rev[i];
		if(curr_sum2<max_sum2)
		{
			max_sum2 = curr_sum2;
			pos2 =i;
		}
	}
	if(max_sum<max_sum2)
	{
		ans.erase(ans.begin(),ans.begin()+pos+1);
		return max_sum;
	}
	else
	{
		rev.erase(rev.begin(),rev.begin()+pos2+1);
		reverse(rev.begin(),rev.end());
		ans = rev;
		return max_sum2;
	}
	
}
int get_max()
{
	int max_sum =ans[0];
	int curr_sum =ans[0];
	int pos =0;
	for(int i =1;i<ans.size();i++)
	{
		curr_sum +=ans[i];
		if(curr_sum>max_sum)
		{
			max_sum = curr_sum;
			pos =i;
		}
	}
	vector<int>rev = ans;
	reverse(rev.begin(),rev.end());
	int max_sum2 =rev[0];
	int curr_sum2 =rev[0];
	int pos2 =0;
	for(int i =1;i<rev.size();i++)
	{
		curr_sum2 +=rev[i];
		if(curr_sum2>max_sum2)
		{
			max_sum2 = curr_sum2;
			pos2 =i;
		}
	}
	if(max_sum>max_sum2)
	{
		ans.erase(ans.begin(),ans.begin()+pos+1);
		return max_sum;
	}
	else
	{
		rev.erase(rev.begin(),rev.begin()+pos2+1);
		reverse(rev.begin(),rev.end());
		ans = rev;
		return max_sum2;
	}
	
}
int main()
{
	int n = 0;
	cin>>n;
	while(n!=0)
	{
		for(int i =0;i<n;i++)
		{
			int y =0;
			cin>>y;
			ans.PB(y);
		}
			int f = 0;
			int s =0;
			while(ans.size()!=0)
			{
				f+=get_max();
				if(ans.size()!=0)
				s+=get_max();
			}
			cout<<abs(f-s)<<endl;
		cin>>n;
	}
	return 0;
}