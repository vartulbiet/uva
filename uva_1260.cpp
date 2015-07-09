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
int main()
{
	int n = 0;
	scanf("%d",&n);
	while(n!=0)
	{
		int x =0;
		scanf("%d",&x);
		vector<int>arr(x);
		for(int i =0;i<x;i++)
		{
			int y =0;
			scanf("%d",&y);
			arr[i] = y;
		}
		int sum  = 0;
		for(int i =1;i<x;i++)
		{
			for(int j =0;j<i;j++)
			{
				if(arr[j]<=arr[i])
				sum++;
			}
		}
		printf("%d\n",sum);
		n--;
	}
	return 0;
}