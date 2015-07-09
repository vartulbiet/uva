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
int LIS(pair<int,int>*inp,int n)
{
	bool*arr = (bool*)malloc(sizeof(bool)*n);
	int r =0;
	for(int i =0;i<n;i++)
	{
		arr[i] = false;
	}
	for(int i =0;i<n;i++)
	{
		if(arr[i] == true)
		continue;
			arr[i] = true;
			r++;
			int k = i;
			for(int j =i+1;j<n;j++)
			{
				if(arr[j] == true)
				continue;
				if((inp[k].first < inp[j].first && inp[k].second < inp[j].second))
				{
					k =j;
					arr[j] = true;
				}
			}
	}
	
	return r;
}
int main()
{
	int n =0 ;
	scanf("%d",&n);
	while(n>0)
	{
		int t =0;
		scanf("%d",&t);int r =t;
		pair<int,int>*grp = (pair<int,int> *)malloc(sizeof(pair<int,int> )*t);int i =0;
		while(t>0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			grp[i++] = make_pair(a,b);
			t=t-1;
		}
		sort(grp,grp+r);
		printf("%d\n",LIS(grp,r));
		n--;
	}
	return 0;
}