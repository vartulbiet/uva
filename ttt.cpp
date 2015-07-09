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
ull arr[1570000];

int main()
{
	//ull n =0;
	//scanf("%d",&n);
	for(ull i=1;i<1570000;i++)
	{
		ull c=0;arr[i] = 0;
		for(int j =1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				if((i/j) == j)
				c++;
				else c=c+2;
			}
		}
		arr[i]=c+arr[i-1];
		cout<<arr[i]<<endl;
	}
	return 0;
}