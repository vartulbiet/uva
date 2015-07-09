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
int solve(vector<int>vec,int sum)
{
	int toret = INF;int ans =0;
	int i =0;
	int j =vec.size()-1;
	while(i<j)
	{
		if(vec[i]+vec[j]>sum)
		{
			int y = vec[i]+vec[j]-sum;
			if(y<toret)
			{
			toret = vec[i]+vec[j]-sum;
			ans = vec[i]+vec[j];
			}
			j =j-1;
		}
		else if(vec[i]+vec[j] ==sum)
		return sum;
		else if(vec[i]+vec[j]<sum)
		{
				int y = sum -vec[i]-vec[j];
			if(y<toret)
			{
			ans = vec[i]+vec[j];
			toret = sum -vec[i]-vec[j];
			}
			i=i+1;
		}
	}
	return ans;
}
int main()
{
	int n =0;
	cin>>n;
	int tt =1;
	while(n!=0)
	{
		vector<int>vec;
		for(int i =0;i<n;i++)
		{
			int x =0;
			cin>>x;
			vec.PB(x);
		}
		sort(vec.begin(),vec.end());
		int t =0;
		cin>>t;
		cout<<"Case "<<tt++<<":"<<endl;
		for(int i =0;i<t;i++)
		{
			int sum =0;
			cin>>sum;
			cout<<"Closest sum to "<<sum<<" is "<<solve(vec,sum)<<"."<<endl;
		}
		cin>>n;
	}
	return 0;
}