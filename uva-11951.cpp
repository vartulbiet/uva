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
int p,q;
long long r;
void init()
{
	for(int i =0;i<101;i++)
	{
		for(int j =0;j<101;j++)
		arr[i][j] =0;
	}
}
void do_sum()
{
	for(int i =1;i<p;i++)
	arr[i][0]=arr[i][0]+arr[i-1][0];
	for(int i =1;i<q;i++)
	arr[0][i]=arr[0][i]+arr[0][i-1];
	for(int i =1;i<p;i++)
	{
		for(int j =1;j<q;j++)
		arr[i][j] = arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
	}
	/*for(int i =0;i<p;i++)
	{
		for(int j =0;j<q;j++)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}*/
}
long long calculate()
{
	long long max_sum =10000000;
	long long ans  =0;
	for(int i =0;i<p;i++)
	{
		for(int j =0;j<q;j++)
		{
			for(int k =i+1;k<=p;k++)
			{
				for(int l =j+1;l<=q;l++)
				{
					if((k-i)*(l-j)>ans && arr[k][l]-arr[i][l]-arr[k][j]+arr[i][j]<=r)
					{
							ans = (k-i+1)*(l-j+1);
							max_sum = arr[k][l]-arr[i][l]-arr[k][j]+arr[i][j];
					}
					else if((k-i)*(l-j)==ans  && arr[k][l]-arr[i][l]-arr[k][j]+arr[i][j]<=r)
					{
						max_sum = min(arr[k][l]-arr[i][l]-arr[k][j]+arr[i][j],max_sum);
					}
				}
			}
		}
	}
	cout<<ans<<" ";
	return max_sum;
}
int main()
{
	int n =0;
	cin>>n;
	int tt =1;
	while(n>0)
	{
		cin>>p>>q>>r;
		 for ( int i = 0; i <p; i++ )
            for ( int j =0; j <q; j++ )
               {
					cin>>arr[i][j];
			   }
		do_sum();
		cout<<"Case #"<<tt++<<": ";
		long long ans = calculate();
		cout<<ans<<endl;
		n--;
	}
	return 0;
}