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
		ull total =0;vector<ull>mint;ull neg =0;
		for(int i =0;i<sz;i++)
		{
		ull x =0;
		scanf("%llu",&x);
		if(x>0)
		{total+=x;arr.PB(x);}
		if(x<0){
		mint.PB(labs(x));neg+=labs(x);};
		}
		ull table[total+1];
		memset(table,0,sizeof(table));
		
			table[0] =1;
			
	for(int i=0; i<arr.size() ;i++)
        for(int j=arr[i]; j<=total; j++)
            table[j] += table[j-arr[i]];
			

	ull tt[neg+1];
	memset(tt,0,sizeof(tt));
	tt[0]=1;
		for(int i=0; i<mint.size() ;i++)
			for(int j=mint[i]; j<=neg; j++)
            tt[j] += tt[j-mint[i]];

		for(int j =0;j<=total;j++)
		cout<<table[j]<<" ";
		cout<<endl;
		
		
	for(int j=0; j<=neg; j++)
	cout<<tt[j]<<" ";
	cout<<endl;
	
	
		for(int i =0;i<queries;i++)
		{
			int y =0;
			scanf("%d",&y);
			ull ans =0;
			for(ull j =0;j*y<=total;j++)
			{
				//cout<<"--"<<i*y<<table[sz][i]<<endl;
				ans+=table[j*y];ans %=M;
				for(ull k =1;k<=neg;k++)
				{
					if(tt[k]>0 && j*y + k <=total)
				{	cout<<k<<endl;
					ans+=(table[j*y+k]*tt[k]);
					ans %=M;}
				}
			}
			printf("%llu\n",ans);
		}
	}
	return 0;
}