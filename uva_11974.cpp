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
int value;
long long int req;
long long int toNum(string s)
{
	vector<int>num;
	for(int i =0;i<s.size();i++)
	{
		if(s[i]=='0')
		num.PB(0);
		else if(s[i]=='1')
		num.PB(1);
	}
	long long int ans =0;
	reverse(num.begin(),num.end());
	for(int j =0;j<num.size();j++)
	ans+=(num[j]*pow((double)2,j));
	return ans;
}
int dist[1<<16];
void BFS(vector<long long int>arr,int a)
{
	queue<long long int>q;
	
	memset(dist,-1,sizeof(dist));
		q.push(~-(1 << a));
		dist[~-(1 << a)] =0;
		//cout<<~-(1<<a);
	while(!q.empty())
	{
		long long int  t =q.front();
		q.pop();
		if(t)
		{
			for(int u =0;u<arr.size();u++)
			{
				if(dist[t^arr[u]]==-1)
				{
					q.push(t^arr[u]);
					dist[t^arr[u]] = dist[t]+1;
				}
			}
		}
		else
		{
			value = dist[t];
			return;
		}
	}
	return;
}
int main()
{
	int n =0;
	cin>>n;int tc =1;
	while(n-->0)
	{
		int a,b;
		value =INF;
		cin>>a>>b;
		for(int i =0;i<a;i++)
		{
			req+=pow(double(2),i);
		}
		vector<long long int>arr;
		string s;
			getline(cin,s);
		for(int i =0;i<b;i++)
		{
			getline(cin,s);
			arr.PB(toNum(s));
		}
		
		BFS(arr,a);
		if(value==INF)
		cout<<"Case "<<tc++<<": IMPOSSIBLE"<<endl;
		else
		cout<<"Case "<<tc++<<": "<<value<<endl;
	}
	return 0;
}