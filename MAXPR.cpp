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
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define MP make_pair
#define ii pair<int,int>
using namespace std;
vector<vector<int> >arr;
#define MOD 1000000007
int  b_search(int k,int s,int u,int v)
{
	if(u>v)
	return arr[k].size();
	else if(u ==v)
	{
		return u;
	}
	int mid = (u+v)/2;
	if(arr[k][mid]>s && ((mid-1>=0 && arr[k][mid-1]<s)||(mid-1<0)))
	return mid;
	if(arr[k][mid]<s)
	{
		return b_search(k,s,mid+1,v);
	}
	else
		return b_search(k,s,u,mid-1);
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		for(int i =0;i<101;i++)
		{
			vector<int>temp;
			arr.PB(temp);
		}
		int c =0;
		cin>>c;
		int mac =0;//max_element in array
		for(int i =0;i<c;i++)
		{
			int y =0;
			cin>>y;
			arr[y].PB(i);
			mac = max(mac,y);
		}
		int ans =1;
		for(int  diff =1;diff<100;diff++)
		{
			for(int  i =0;i<=mac;i++)
			{
				int k =i;int s = -1;
				while(k<=mac)
				{
					int prev= b_search(k,s,0,arr[k].size()-1);// it gives index (just greater than s) of element K in arr[k];
					int sz = arr[k].size()-prev;
					cout<<sz<<endl;
					ans += (ans * sz)%MOD;
					ans %=MOD;
					k += diff;
					s = prev;
				}
			}
			cout<<"------"<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}