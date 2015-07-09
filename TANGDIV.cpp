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
int find(int x,int *arr)
{
	if(x == arr[x])
	{
		return x;
	}
	else
		return arr[x] = find(arr[x],arr);
}
void merge(int y,int z,int*arr)
{
	arr[find(z,arr)] = find(y,arr);
}
int main()
{
	int n = 0;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int *arr =(int*)malloc(sizeof(int)*2*a);
		for(int i =0;i<2*a;i++)
			arr[i ] =i;

	vector<pair<int,int> >vec;
	for(int i =0;i<b;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)
			y+=a;
		vec.PB(make_pair(x-1,y-1));
	}
	for(int i =0;i<c;i++)
	{
		int x,y;
			scanf("%d%d",&x,&y);
		if(x>y)
			y+=a;
		for(int j =x-1;j<y-1;j++)
			merge(j,j+1,arr);
	}
	bool bt =true;
	//for(int i =0;i<2*a;i++)
	//		cout<<arr[i]<<" ";
	//		cout<<endl;
	for(int i =0;i<b && bt;i++)
	{
		if(find(vec[i].first,arr) != find(vec[i].second,arr))
			bt =false;
	}
	if(bt)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		free(arr);
		vec.erase(vec.begin(),vec.end());
		}
		return 0;
}