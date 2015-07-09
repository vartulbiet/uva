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
#define INF 1<<20
using namespace std;
vector<int> func(vector<int>arr1,vector<int>arr2,vector<int>arr3)
{
	vector<int> ans1;
		for(int i =0;i<arr1.size();i++)
		{
			bool bt = true;
			for(int j =0;j<arr3.size() && bt;j++)
			{
				if(arr1[i] ==arr3[j])
					bt =false;
			}
			for(int j =0;j<arr2.size() && bt;j++)
			{
				if(arr1[i] ==arr2[j])
					bt =false;
			}
			if(bt)
			ans1.PB(arr1[i]);
		}
		sort(ans1.begin(),ans1.end());
		return ans1;
}
void printt(vector<int>ans)
{
	cout<<ans.size();
	for(int i =0;i<ans.size();i++)
	cout<<" "<<ans[i];
	cout<<endl;
}
int main()
{
	int n =0;
	cin>>n;int tc =1;
	while(n>0)
	{
		int m =0;
		cin>>m;
		vector<int>arr1(m);
		for(int i =0;i<m;i++)
		cin>>arr1[i];
		int k =0;
		cin>>k;
		vector<int>arr2(k);
		for(int i =0;i<k;i++)
		cin>>arr2[i];
		int p =0;
		cin>>p;
		vector<int>arr3(p);
		for(int i =0;i<p;i++)
		cin>>arr3[i];
		vector<int>ans1,ans2,ans3;
		ans1= func(arr1,arr2,arr3);
		ans2= func(arr2,arr1,arr3);
		ans3= func(arr3,arr1,arr2);
		int a = ans1.size();
		int b = ans2.size();
		int c = ans3.size();
		cout<<"Case #"<<tc++<<":"<<endl;
		if(a>b)
		{
			if(a>c)
			{
				cout<<"1"<<" ";
				printt(ans1);
			}
				else if(a==c)
				{
					cout<<"1"<<" ";
					printt(ans1);
					cout<<"3"<<" ";
					printt(ans3);
				}
				else
				{
					cout<<"3"<<" ";
					printt(ans3);
				}
		}
		else if(a==b)
		{
			if(a>c)
			{
				cout<<"1"<<" ";
				printt(ans1);
				cout<<"2"<<" ";
				printt(ans2);
			}
				else if(a==c)
				{
				cout<<"1"<<" ";
					printt(ans1);cout<<"2"<<" ";
					printt(ans2);cout<<"3"<<" ";
					printt(ans3);
				}
				else
				{
					cout<<"3"<<" ";
					printt(ans3);
				}
		}
		else
		{
			if(b>c)
			{
				cout<<"2"<<" ";
				printt(ans2);
			}
				else if(b==c)
				{
				cout<<"2"<<" ";
					printt(ans2);cout<<"3"<<" ";
					printt(ans3);
				}
				else
				{cout<<"3"<<" ";
					printt(ans3);
				}
		}
		n--;
	}
	return 0;
}