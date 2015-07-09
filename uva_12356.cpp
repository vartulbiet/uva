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
int next[1000100];
int prev[1000100];
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	while(m!=0 && n!=0)
	{
		
		prev[0] =-1;
		next[m-1]=-1;
		
		for(int i =0;i<m;i++)
		{
		prev[i] = i-1;
		next[i] = i+1;
		}
		next[m-1]=-1;
		
		for(int j =0;j<n;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--;
			y--;
			if(prev[x] !=-1)
			next[prev[x]]= next[y];
			if(next[y] !=-1)
			prev[next[y]] = prev[x];
			if(prev[x]==-1)
			printf("* ");
			else
			printf("%d ",prev[x]+1);
			if(next[y] == -1)
			printf("*\n");
			else
			printf("%d\n",next[y]+1);
		}
		printf("-\n");
		scanf("%d%d",&m,&n);
	}
	return 0;
}