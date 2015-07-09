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
#define INF 1<<30

using namespace std;
int arr[15][15];
void init()
{
	for(int i =0;i<15;i++)
		for(int j =0;j<15;j++)
		arr[i][j] = 0;
}

int main()
{
	int n =0;int gg= 0;
	while(scanf("%d",&n)==1)
	{
		init();if(gg!=0)
		cout<<endl;
		gg++;
		int x = 0;
		int y= n/2;
		for(int i =1;i<=n*n;)
		{
			if(x<0)
				x=n-1;
			else if(x>n-1)
				x= 0;
				if(y>n-1)
					y=0;
					else if(y<0)
					 y =n-1;
				
			if(arr[x][y]==0)
			{
				arr[x][y] = i;
				i++;
				int u= x-1;
				int v =y+1;
				if(u<0)
				u=n-1;
			else if(u>n-1)
				u= 0;
				if(v>n-1)
					v=0;
					else if(v<0)
					 v =n-1;
					 if(arr[u][v]==0)
					 {
					 x=u;
					 y=v;
					 }
			}
			else
			{
				x++;
			}
		}
		int sum =0;
		for(int i =0;i<n;i++)
		{
			sum+=arr[i][0];
		}
		cout<<"n="<<n<<", sum="<<sum<<endl;
		for(int i =0;i<n;i++)
		{
			for(int  j=0;j<n;j++)
			if(n==3)
			printf(" %d",arr[i][j]);
			else if(n<=9)
			printf(" %2d",arr[i][j]);
			else
			printf(" %3d",arr[i][j]);
			cout<<endl;
		}
	}
	return 0;
}