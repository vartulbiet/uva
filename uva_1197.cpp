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
int arr[30001];
int find_set(int a,int m)
{
	if(arr[a] ==a)
	return a;
	else
	return arr[a] = find_set(arr[a],m);
}
void merge_set(int a,int b,int m)
{
	arr[find_set(a,m)] = arr[find_set(b,m)];
}
int count(int m,int x)
{	
	int t =0;
	for(int i =0;i<m;i++)
	{
		if(find_set(arr[i],m)==find_set(x,m))
		t++;
	}
	return t;
}
int main()
{
	int m,n;
	cin>>m>>n;
	while(!(m==0 && n==0))
	{
		for(int i =0;i<m;i++)
		arr[i] =i;
		for(int j =0;j<n;j++)
		{
			int k =0;
			cin>>k;
			vector<int>store;
			for(int i =0;i<k;i++)
			{
				int y =0;
				cin>>y;
				store.PB(y);
				if(i!=0)
				{
					merge_set(store[i],store[i-1],m);
				}
			}
		}
		cout<<count(m,0)<<endl;
		cin>>m>>n;
	}
	return 0;
}