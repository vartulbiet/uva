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
vector<int>arr[1000001];
int main()
{
	int sz,m =0;
	while ( scanf ("%d %d", &sz, &m) ==2 ) 
	{
	 for ( int i = 0; i < 1000001; i++ )
            arr[i].clear ();
		for(int i =0;i<sz;i++)
		{
			int x =0;
			scanf("%d",&x);
			arr[x].PB(i+1);
		}
		for(int i =0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(arr[b].size()<a)
				cout<<"0"<<endl;
			else
				cout<<arr[b][a-1]<<endl;
		}
	}
	return 0;
}