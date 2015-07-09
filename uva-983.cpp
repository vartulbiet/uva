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
long long arr[1001][1001];
int m;
int x;
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
	for(int i =1;i<m;i++)
	arr[i][0]=arr[i][0]+arr[i-1][0];
	for(int i =1;i<m;i++)
	arr[0][i]=arr[0][i]+arr[0][i-1];
	for(int i =1;i<m;i++)
	{
		for(int j =1;j<m;j++)
		arr[i][j] = arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
	}
	/*for(int i =0;i<m;i++)
	{
		for(int j =0;j<m;j++)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}*/
}
void calculate()
{
	long long max_sum =0;
	long long ans =0;
	for(int i =m-1;i>=x-1;i--)
	{
		for(int j =x-1;j<m;j++)
		{
					long long temp = arr[i][j];
					if(i-x>=0)
					temp -=arr[i-x][j];
					if( j-x>=0)
					temp-=arr[i][j-x];
					if(i-x>=0 && j-x>=0)
					temp+=arr[i-x][j-x];
					cout<<temp<<endl;
					ans+=temp;
		}
	}
	cout<<ans<<endl;
}
int main()
{
int yy =0;
	while(scanf("%d%d",&m,&x)==2)
	{
		init();
		if(yy!=0)
		cout<<endl;
		yy++;
		 for ( int i =m-1;i>=0; i-- )
            for ( int j = 0; j <m; j++ )
               {
					scanf("%d",&arr[i][j]);
			   }
		do_sum();
		calculate();
		string s;
		getline(cin,s);
	}
	return 0;
}