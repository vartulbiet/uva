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
	int m,n,p;
	scanf("%d%d%d",&m,&n,&p);
	map<int,int>index;
	vector<map<int,int> > vect;
	int k =0;
	while(p--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(index.find(x) == index.end())
		{
			index[x] = k++;
			map<int,int>mapp;
			mapp[y] =1;
			vect.PB(mapp);
		}
		else
		{
			map<int,int>mapp =vect[index[x]];
			if(mapp.find(y) == mapp.end())
			mapp[y] =1;
			else
			mapp[y]++;
			vect[index[x]] = mapp;
		}
	}
	for(int i =1;i<=m;i++)
	{	
		if(index.find(i) == index.end())
		{
			printf("%d\n",n-1);
		}
		else
		{
			map<int,int>my =vect[index[i]];
			int y = n-1;bool ct =true;
			for(std::map<int,int>::iterator bt = my.begin();bt != my.end() && ct;bt++)
			{
				int col = bt->first;
				int val =bt->second;
				int nxt_col = col+1;
				int nxt_val =0;
				
				if(my.find(nxt_col) !=my.end())
				{
					nxt_val = my[nxt_col];
				}
				
				if(col !=n)
				{
					if(col+val>nxt_val+nxt_col)
					ct =false;
				}
				if(col == n)
				{
					y+=val;
				}
				if(col ==1)
				y-=val;
			}
			if(ct)
			printf("%d\n",y);
			else
			printf("-1\n");
		}
	}
	return 0;
}