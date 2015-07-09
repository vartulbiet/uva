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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
int func(vector<string>arr,int kk,int mm)
{
	int ans =0; int n = arr.size();
			for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				int x =i;
				int y =j;
				bool bt = true;
				if(arr[x][y]!='X' && (x!=kk || y!=mm))
				{
				for(int k =x-1;k>=0 && bt;k--)
				{
					if(arr[k][y]=='1')
					bt= false;
					if(arr[k][y]=='X')
					break;
				}
				for(int k =x+1;k<n && bt;k++)
				{
					if(arr[k][y]=='1')
					bt= false;
					if(arr[k][y]=='X')
					break;
				}
				for(int k =y-1;k>=0 && bt;k--)
				{
					if(arr[x][k]=='1')
					bt= false;
					if(arr[x][k]=='X')
					break;
				}
				for(int k =y+1;k<n  && bt;k++)
				{
					if(arr[x][k]=='1')
					bt= false;
					if(arr[x][k]=='X')
					break;
				}
				if(bt)
				{
					arr[x][y]='1';
					ans++;
				}
				}
			}
		}
		return ans;
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		vector<string>arr;
		string s;
		getline(cin,s);
		for(int i =0;i<n;i++)
		{
			getline(cin,s);
			arr.PB(s);
		}
		int ans =0;
	for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
			if(arr[i][j]!='X')
			{
			arr[i][j] ='1';
			ans = max(ans,func(arr,i,j)+1);
			arr[i][j] = '.';
			}
			}}
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}