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
#include<assert.h>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;

int	 main()
{
	int n = 0;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int*arr = (int*)malloc(sizeof(int)*a);
		
		memset(arr,1,sizeof(arr));
		vector<pair<int,int> >vec;
		for(int i =0;i<b;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			vec.PB(make_pair(x-1,y-1));
		}
		for(int i =0;i<c;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if(x == 1)
				arr[a-1] =0;
			else
				arr[x-2] =0;
			arr[y-1]= 0;
		}
		bool bt =true;
		for(int i =0;i<b && bt;i++)
		{
			int st = vec[i].first;
			int end = vec[i].second;
			while(st!=end)
			{
				int te = arr[st];
				if(te == 0)
				{bt =false;break;}
				else
				st =st+1;
				if(st == a)
				{
					st =0; 
				}
			}
		}
	
		if(bt)
			printf("Yes\n");
		else
			printf("No\n");
			free(arr);
			if(n>0)
			cout<<endl;
	}
	return 0;
}