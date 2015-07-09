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
		ull total =0;
		ull neg =0;
		for(int i =0;i<sz;i++)
		{
		ull x =0;
		scanf("%lld",&x);
		arr.PB(x);
		if(x>0)
		{total+=x;}
		if(x<0)
		neg+=x;
		}
		vector<ull>brr;
		for(int i = neg;i<=total;i++)
			brr.PB(i);
		int uu =brr.size();
		ull table[sz+1][uu+1];
		memset(table,0,sizeof(table));		
	for(ull i =1;i<=sz;i++)
	{
		for(ull j =0;j<=uu;j++)
		{
			table[i][j] = table[i-1][j];
			if(brr[j]>arr[i-1] && table[i-1][brr[j]-arr[i-1]]>0)
			{
				table[i][j] +=table[i-1][brr[j]-arr[i-1]];
			}
			else if(brr[j] == arr[i-1])
			table[i][j]++;
			table[i][j] %=M;
		}
	}
for(int i =0;i<=sz;i++)
	{
		for(int j =0;j<=total;j++)
		cout<<table[i][j]<<" ";
		cout<<endl;
	}
		
	}
	return 0;
}