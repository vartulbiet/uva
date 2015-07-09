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
map<vector<int>,bool>mymap;
void swap(int*x,int *y)
{
	int temp =*x;
	*x =*y;
	*y= temp;
}
void permute(vector <vector<int> >&arr,vector<int>x)
{
if(mymap.find(x)==mymap.end())
{
	arr.PB(x);
	mymap[x] = true;
	for(int i =0;i<x.size()-1;i++)
	{
		swap(&x[i],&x[i+1]);
		permute(arr,x);
		swap(&x[i],&x[i+1]);
	}
}
else
return;
}

vector<int>dp;
int lIS(vector <vector<int> >arr,int k)
{
	if( dp[k])
	{
	return dp[k];
	}
	vector<int>h;
	
	for(int i=0;i<arr.size();i++)
	{
			if(arr[i][0]<arr[k][0] && arr[i][1]<arr[k][1])
			{
				dp[k] = max(lIS(arr,i),dp[k]);
			}
	}
	
	return dp[k] = dp[k]+arr[k][2];
}
using namespace std;
int main()
{
	int n =0;
	cin>>n;int cse =1;
	while(n!=0)
	{
	vector<vector<int> >arr;
		while(n>0)
		{
			int a,b,c;
			cin>>a>>b>>c;
			vector<int>x;
			x.PB(a);x.PB(b);x.PB(c);
			sort(x.begin(),x.end());
			permute(arr,x);
			n--;
		}
		for(int i =0;i<arr.size();i++)
		dp.PB(0);
		int ans =0;
			//for(int i =0;i<arr.size();i++)
	//cout<<dp[i]<<" ";
		for(int i =0;i<arr.size();i++)
		{
			ans = max(ans,lIS(arr,i));
		}
		cout<<"Case "<<cse++<<": maximum height = ";
		cout<<ans<<endl;
		mymap.erase(mymap.begin(),mymap.end());
		dp.erase(dp.begin(),dp.end());
		scanf("%d",&n);
	}
	return 0;
}