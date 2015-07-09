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
int arr[105][105];
int n ;
void init()
{
	for(int i =0;i<105;i++)
	{
		for(int j =0;j<105;j++)
		arr[i][j] = 0;
	}
}

void do_sum()
{
	for(int i =1;i<n;i++)
	arr[i][0]=arr[i][0]+arr[i-1][0];
	for(int i =1;i<n;i++)
	arr[0][i]=arr[0][i]+arr[0][i-1];
	for(int i =1;i<n;i++)
	{
		for(int j =1;j<n;j++)
		arr[i][j] = arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
	}
}
int main()
{
	cin>>n;
	init();
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		cin>>arr[i][j];
	}
	do_sum();
	int max_sum =-127*100*100;
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =i;k<n;k++)
			{
				for(int l =j;l<n;l++)
				{
					int temp = arr[k][l];
					if(i-1>=0)
					temp -=arr[i-1][l];
					if( j-1>=0)
					temp-=arr[k][j-1];
					if(i-1>=0 && j-1>=0)
					temp+=arr[i-1][j-1];
					//cout<<temp<<" ";
					max_sum = max(max_sum,temp);
				}
			}
		}
	}
	cout<<max_sum<<endl;
	return 0;
}