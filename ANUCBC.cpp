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
#define ull long long int  
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define M 1000000009
using namespace std;

int main()
{
	int n =0;
	scanf("%d",&n);
	while(n--)
	{
		int sz =0;
		scanf("%d",&sz);
		int queries =0;
		scanf("%d",&queries);
		vector<ull>arr;
		ull total =0;vector<ull>mint;
		for(int i =0;i<sz;i++)
		{
		ull x =0;
		scanf("%llu",&x);
		if(x>0)
		{total+=x;arr.PB(x);}
		if(x<0)
		mint.PB(labs(x));
		}
		ull table[sz+1][total+1];
		memset(table,0,sizeof(table));
		for(ull i =0;i<sz+1;i++)
			table[i][0] =1;
			
	for(ull i =1;i<=sz;i++)
	{
		for(ull j = 0;j<=total;j++)
		{
			table[i][j] = table[i-1][j];
			if(j>arr[i-1] && table[i-1][j-arr[i-1]]>0)
			{
				table[i][j] +=table[i-1][j-arr[i-1]];
			}
			else if(j == arr[i-1])
			table[i][j]++;
			table[i][j] %=M;
		}
	}
	ull neg = 0;
	for(ull i =0;i<mint.size() ;i++)
	neg += mint[i];
	ull tt[mint.size()+1][neg+1];
	memset(tt,0,sizeof(tt));
	for(ull i =1;i<mint.size()+1;i++)
	{
		for(ull j =0;j<=neg;j++)
		{
			tt[i][j] =tt[i-1][j];
			if(j>mint[i-1] && tt[i-1][j-mint[i-1]]>0)
			tt[i][j] +=tt[i-1][j-mint[i-1]];
			else if(j == mint[i-1])
			tt[i][j]++;
			tt[i][j] %=M;
		}
	}
	//cout<<sz<<total<<endl;
	/*for(int i =0;i<=sz;i++)
	{
		for(int j =0;j<=total;j++)
		cout<<table[i][j]<<" ";
		cout<<endl;
	}*/
	//cout<<neg;
		for(int i =0;i<queries;i++)
		{
			int y =0;
			scanf("%d",&y);
			ull ans =0;
			for(ull j =0;j*y<=total;j++)
			{
				//cout<<"--"<<i*y<<table[sz][i]<<endl;
				ans+=table[sz][j*y];ans %=M;
				for(ull k =1;k<=neg;k++)
				{
					if(tt[mint.size()][k]>0 && j*y + k <=total)
				{//	cout<<k<<endl;
					ans+=(table[sz][j*y+k]*tt[mint.size()][k]);
					ans %=M;}
				}
			}
			printf("%llu\n",ans);
		}
	}
	return 0;
}