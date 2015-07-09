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
int arr[8]={-1,0,1,-1,1,-1,0,1};
int brr[8]={-1,-1,-1,0,0,1,1,1};
bool valid(int x,int y,vector<string>rr,int m,int n)
{
	for(int i =0;i<8;i++)
	if(x-arr[i]>=0 && x-arr[i]<m && y-brr[i]>=0 && y-brr[i]<n && rr[x-arr[i]][y-brr[i]] == '*')
		return false;
	return true;
}
int find_star(vector<string>arr,int x,int y)
{
	int ans =0;
	for(int i =0;i<x;i++)
	{
		for(int j =0;j<y;j++)
		{
			if(arr[i][j] == '*' && valid(i,j,arr,x,y))
			{
				ans++;
			}
		}
	}
	return ans;
}
int main()
{
	int x,y;
	cin>>x>>y;
	while(x||y)
	{
		vector<string>arr;
		for(int i =0;i<x;i++)
		{
			string s;
			cin>>s;
			arr.PB(s);
			//cout<<s<<endl;
		}
		cout<<find_star(arr,x,y)<<endl;
		cin>>x>>y;
	}
	return 0;
}