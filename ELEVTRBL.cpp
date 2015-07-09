#include <iostream>
#include <vector>
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
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull long long int  
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define M 1000000009
using namespace std;
vector<int>arr;
int BFS(int start,int down, int u, int d )
{
	if(start == down)
		return 0;
	else
	{
		int x = INF;
		if(start + u < floor && arr[start+u] !=0)
		{
			arr[start+u] = 0;
			x = BFS(start + u, down ,u,d);
		}
		if(start - d >=0 && arr[start-d] !=0)
		{
			arr[start-d] = 0;
			x = min(x,BFS(start - d, down ,u,d));
		}
		return x;
	}
}
int main()
{
	int floor,start,dest,up,down;
	cin>>floor>>start>>dest>>up>>down;
	for(int i =1; i<=floor ; i++)
	{
		arr.PB(-1);
	}
	arr[start-1] = 0;
	cout<<BFS(start-1,dest-1,up,down);
	return 0;
}