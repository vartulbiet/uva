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
struct st
{
	int e;
	int f;
	int g;
};
int limit,dest;
int max_cost;
vector< struct st >arr;
void recurse(int*x,int pp)
{
	int tempp=0;
	if(pp>dest)
	return;
	if(pp<=dest)
	{
	for(int i =0;i<dest;i++)
	{
		tempp+=x[i];
	}
	if(max_cost<tempp)
	max_cost =tempp;
	}
		struct st p= arr[pp];
		int temp[10];
		for(int l =0;l<dest;l++)
		temp[l]=x[l];
			for(int k =p.e;k<p.f;k++)
			temp[k]+=p.g;
			bool bt= true;
			for(int l =0;l<dest;l++)
				if(temp[l]>limit){
				bt= false;
				break;}
			if(bt)
			{
			recurse(temp,pp+1);
			}
			recurse(x,pp+1);
}
int main()
{
		int loop;
		//cin>>limit>>dest>>loop;
		scanf("%d%d%d",&limit,&dest,&loop);
		while(limit!=0 && dest!=0 && loop!=0)
		{
			int a,b,c;
			for(int i =0;i<loop;i++)
			{
				struct st m;
				scanf("%d%d%d",&m.e,&m.f,&m.g);
				arr.PB(m);
			}
			int cost[10];
			for(int i =0;i<10;i++)
				cost[i] =0;
			max_cost =0;
			vector<bool>vec;
			for(int i =0;i<loop;i++)
			vec.PB(false);
			recurse(cost,0);
			printf("%d\n",max_cost);
			arr.erase(arr.begin(),arr.end());
			scanf("%d%d%d",&limit,&dest,&loop);
		}
		return 0;
}