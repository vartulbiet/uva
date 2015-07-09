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
#include <assert.h>
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
		ull total =0;ull neg =0;
		vector<ull>mint;
		for(int i =0;i<sz;i++)
		{
		ull x =0;
		scanf("%lld",&x);
		if(x>0)
		{total+=x;arr.PB(x);}
		if(x<0){
		mint.PB(labs(x));neg+=labs(x);}
		}
		
		ull table[2][total+1];
		memset(table,0,sizeof(table));
		for(ull i =0;i<2;i++)
			table[i][0] =1;
			
		for(ull i =1;i<=sz;i++)
		{
			for(ull j = 0;j<=total;j++)
			{
				table[1][j] = table[0][j];
				if(j>arr[i-1] && table[0][j-arr[i-1]]>0)
				{
					table[1][j] +=table[0][j-arr[i-1]];
				}
				else if(j == arr[i-1])
				table[1][j]++;
				table[1][j] %=M;
			}
			for(int d =0;d<=total;d++)
			{
				table[0][d] = table[1][d];
				table[1][d] =0;
			}
		}
	
	
		ull tt[2][neg+1];
		memset(tt,0,sizeof(tt));
		for(ull i =0;i<2;i++)
				tt[i][0] =1;
		for(int i =1;i<=mint.size();i++)
		{
			for(int j =0;j<=neg;j++)
			{
				tt[1][j] =tt[0][j];
				if(j>mint[i-1] && tt[0][j-mint[i-1]]>0)
				tt[1][j] +=tt[0][j-mint[i-1]];
				else if(j == mint[i-1])
				tt[1][j]++;
				tt[1][j] %=M;
			}
			for(int d =0;d<=neg;d++)
			{
				tt[0][d] = tt[1][d];
				tt[1][d] =0;
			}
		}
		for(int i =0;i<queries;i++)
		{
			int y =0;
			scanf("%d",&y);
			ull ans =0;
			for(int j =0;j*y<=total;j++)
			{
				ans+=(table[0][j*y]%M);
				ans %=M;
				for(ull k =1;k<=neg;k++)
				{
					if(tt[0][k]>0 && j*y + k <=total)
					{
					ans+=(((table[0][j*y+k]%M)*(tt[0][k]%M))%M);
					ans %=M;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}