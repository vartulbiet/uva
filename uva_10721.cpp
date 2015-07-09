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
int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		ull arr[55][55] = {{0}};
		for(int i =1;i<=c;i++)
		{
			arr[i][1] =1;
		}

		for(int i =1;i<=a;i++)
		{
			for(int j =2;j<=b;j++)
			{
				ull temp =0;
				for(int k =1;k<=c;k++)
				{
					if(i-k>=0 && j-1>=0)
					temp+= arr[i-k][j-1];
				}
				arr[i][j] = temp;
				
			}
			
		}
		cout<<arr[a][b]<<endl;
	}
}