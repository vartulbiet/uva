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
long long arr[101][101];
int m;
void init()
{
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<m;j++)
		arr[i][j] =1;
	}
}
void do_sum()
{
	for(int i =1;i<m;i++)
	arr[i][0]=arr[i][0]+arr[i-1][0];
	for(int i =1;i<m;i++)
	arr[0][i]=arr[0][i]+arr[0][i-1];
	for(int i =1;i<m;i++)
	{
		for(int j =1;j<m;j++)
		arr[i][j] = arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
	}
	/*for(int i =1;i<india;i++)
	{
		for(int j =1;j<india;j++)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}*/
}
long long calculate()
{
	long long max_sum =0;
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<m;j++)
		{
			for(int k =i;k<m;k++)
			{
				for(int l =j;l<m;l++)
				{
					long long temp = arr[k][l];
					if(i-1>=0)
					temp -=arr[i-1][l];
					if( j-1>=0)
					temp-=arr[k][j-1];
					if(i-1>=0 && j-1>=0)
					temp+=arr[i-1][j-1];
					max_sum = max(max_sum,temp);
				}
			}
		}
	}
	return max_sum;
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		cin>>m;
		init();
		int t =0;
		cin>>t;
		for(int k =0;k<t;k++)
		{
			int a1,a2,a3,a4;
			cin>>a1>>a2>>a3>>a4;
		 for ( int i = a1-1; i <=a3-1; i++ )
            for ( int j = a2-1; j <= a4-1; j++ )
               {
					arr[i][j] =-1000000000;
			   }
		}
		do_sum();
		long long ans = calculate();
		cout<<ans<<endl;
		n--;
	}
	return 0;
}