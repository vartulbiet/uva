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
#define MP make_pair
#define INF 1<<10
using namespace std;
int arr[100][100];
int brr[100][100];
void floyd_warshal()
{
	for(int k =0;k<100;k++)
	{
		for(int i =0;i<100;i++)
			for(int j =0;j<100;j++)
			arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
	}
	for(int i =0;i<100;i++)
			for(int j =0;j<100;j++)
			if(arr[i][j] != INF && arr[i][j] !=0)
			arr[i][j] = 1;
			
}
void floyd_warshal_b()
{
	for(int k =0;k<100;k++)
	{
		for(int i =0;i<100;i++)
			for(int j =0;j<100;j++)
			brr[i][j] = min(brr[i][j],brr[i][k] + brr[k][j]);
	}
	for(int i =0;i<100;i++)
			for(int j =0;j<100;j++)
			if(brr[i][j] != INF && brr[i][j] !=0)
			brr[i][j] = 1;
			
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int k =0;
		cin>>k;
		for(int i =0;i<100;i++)
		{
			for(int j =0;j<100;j++)
			{
				arr[i][j] = INF;
				arr[i][i] =0;
				brr[i][j] = INF;
				brr[i][i] =0;
			}
		}
		while(k--)
		{
			char x,y;
			cin>>x>>y;
			//cout<<x<<y;
			arr[x-'A'][y-'A'] =1;
		}
		int e =0;
		cin>>e;
		while(e--)
		{
			char x,y;
			cin>>x>>y;
			brr[x-'A'][y-'A'] =1;
		}
		floyd_warshal();
		floyd_warshal_b();bool  bt =true;
		for(int i =0;i<10;i++)
		{
		for(int j =0;j<10;j++)
		{
			if(arr[i][j] != brr[i][j])
			{
			bt =false;
			}
			//cout<<arr[i][j]<<" ";
		}//cout<<endl;
		}
		
			if(bt)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
			if(n!=0)
			cout<<endl;
	}
	return 0;
}