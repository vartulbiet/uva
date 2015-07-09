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
int main()
{
	int x,y;
	cin>>x>>y;
	while(x!=0 && y!=0)
	{
		int arr[105][105] = {{0}};
		for(int i = 1;i<=y;i++)
		arr[0][i] = 1;
		for(int i =1;i<=x;i++)
		{
			for(int j =1;j<=y;j++)
			{
				arr[i][j] = (arr[i-1][j]+arr[i][j-1])%1000000;
			}
		}
		cout<<arr[x][y]<<endl;
		cin>>x>>y;
	}
	return 0;
}