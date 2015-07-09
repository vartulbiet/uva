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

int main()
{
	int n = 0;
	scanf("%d",&n);
	int vec[301][301];
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			int u;
			scanf("%d",&u);
			vec[i][j] = u;
		}
	}
	map<int,bool> arr[301][301][301][301];
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			int h = vec[i][j];
			for(int k = 0;k<n;k++)
			{
				map<int,bool>temp;
			map<int,bool>keep;
				for(int l= 0;l<n;l++)
				{
					if(k<i||l<j)
					arr[i][j][k][l] = temp;
					else if(k==i && l==j)
					{
						temp[vec[k][l]] = true;
						arr[i][j][k][l] = temp;
					}
					else 
					{
						temp[vec[k][l]] =  true;
						arr[i][j][k][l] = temp;
					}
					
				}
			}
		}
	}
	int m =0;
	scanf("%d",&m);
	for(int jj =0;jj<m;jj++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int ans =0;
		a-=1;b-=1;c-=1;d-=1;
		if(a==c && b==d)
				printf("1\n");
		else
		{
			
		}
	}
	return 0;
}