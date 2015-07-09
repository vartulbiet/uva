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
void init()
{
	for(int i =0;i<100005;i++)
	arr[i] = i;
}

int find_set(int x)
{
	if(arr[x] == x)
	return x;
	else
	return arr[x] = find_set(arr[x]);
}

void merge(int a,int b)
{
	arr[find_set(a)] = find_set(b);
}

int main()
{
	int a,b;int ct =0;
	init();
	while(scanf("%d",&a)==1)
	{
		if(a == -1)
		{
		cout<<ct<<endl;
		ct =0;
		init();
		}
		else
		{
		cin>>b;
		if(find_set(a) != find_set(b))
		merge(a,b);
		else
		ct++;
		}
	}
	return 0;
}