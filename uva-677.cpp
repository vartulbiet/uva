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
int arr[11][11];
int transposed[11][11];
int temp[11][11];
void transpose()
{
	for(int i =0;i<11;i++)
	{
		for(int j = 0;j<11;j++)
		{
			transposed[i][j] = arr[j][i];
		}
	}
}
void init()
{
	for(int i =0;i<11;i++)
	{
		for(int j =0;j<11;j++)
		arr[i][j] = 0;
	}
}
int multiplication(int *brr,int *crr ,int t )
{
	int temp = 0;
	for(int i =0;i<t;i++)
	{
		int val =0;
		if(brr[i] == 0 || crr[i] == 0)
		val =0;
		else
		val=1;
		if(temp== 1 || val==1)
		return 1;
	}
	return 0;
}
void multiply(int m,int n,int brr[11][11])
{
	if(n>1)
	{
		for(int i =0;i<m;i++)
		{
			int *t1 = brr[i];
			int *t2 =transposed[i];
			for(int j =0;j<m;j++)
			{
				temp[i][j] = multiplication(t1,t2,m);
			}
		}
		multiply(m,n-1,temp);
	}
}
void create_ans(int h,int g,int trr[11][11],vector<int>ans,int x)
{
	if(g==0)
	{
		cout<<"(";
		for(int i =0;i<ans.size();i++)
		cout<<ans[i]+1<<",";
		cout<<")";
		cout<<endl;
	}
	else
	{
		for(int i =0;i<h;i++)
		{
			if(arr[x][i] ==1)
			{
				vector<int>temp = ans;
				temp.PB(i);
				create_ans(h,g-1,trr,temp,i);
			}
			else
			return;
		}
	}
}
int main()
{
	int a;int b;
	int c =0;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(c!=0)
		{
			int h =0;
			cin>>h;
			c++;
		}
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<a;j++)
			{
				int g;
				cin>>g;
				arr[i][j] = 1;
			}
		}
		transpose();
		multiply(a,b,arr);
		vector<int>ans;
		if(b==1)
		{
			create_ans(a,b,arr,ans,0);
		}
		else
		{
			create_ans(a,b,temp,ans,0);
		}
		cout<<endl;
	}
	return 0;
}