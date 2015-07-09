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
map<int,int>mymap;
int main()
{
	int n =0;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i =0;i<n;i++)
		{
			int a =0;
			scanf("%d",&a);
			mymap[a]++;
		}
		int  jjj =0;
		for(std::map<int,int>::iterator it =mymap.begin();it!=mymap.end();it++)
		{
			while(mymap[it->first]!=0)
			{
				if(jjj!=0)
				printf(" ");
				jjj++;
				printf("%d",it->first);
				mymap[it->first]--;
			}
		}
		mymap.erase(mymap.begin(),mymap.end());
		printf("\n");
		scanf("%d",&n);
	}
}