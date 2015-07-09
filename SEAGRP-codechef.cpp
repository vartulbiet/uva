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
int find(vector<int>&arr,int a)
{
	if(arr[a]== a)
		return a;
	else
		return arr[a]=find(arr,arr[a]);
}

void merge(vector<int>&arr,int a,int b)
{
	arr[find(arr,a)]=find(arr,b);
}

int main()
{
	int n =0;
	scanf("%d",&n);
	while(n>0)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		vector<int>arr(a);
		for(int i=0;i<a;i++)
		arr[i]= i;
		bool bt = true;
		for(int i =0;i<b;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(find(arr,x-1)!=find(arr,y-1))
			{
				merge(arr,x-1,y-1);
				bt = true;
			}
			else
			bt = false;
		}
		if(bt == false)
		printf("YES");
		else
		printf("NO");
		printf("\n");
		n--;
	}
	return 0;
}