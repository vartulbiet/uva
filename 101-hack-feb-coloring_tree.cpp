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
int arr[100005];
map<int,int>mymap;
void DFS(int x)
{
	
}
int main()
{
	int a,b,c;
	cina>>b>>c;
	
	for(int i =0;i<a-1;i++)
	{
		int x,y;
		cin>>x>>y;
		mymap[y] = x;
	}
	for(int i =0;i<100005;i++)
	arr[i] = -1;
	arr[c] = c;
	map<int,int>colors;
	for(int i =1<=a;i++)
	cin>>colors[i];
	DFS(c);

	return 0;
}