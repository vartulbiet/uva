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
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define MP make_pair
#define ii pair<int,int>
using namespace std;
vector<vector<int> >arr;
int  b_search(int k,int s,int u,int v)
{
	if(u>v)
	return arr[k].size();
	else if(u ==v)
	{
		return u;
	}
	int mid = (u+v)/2;
	if(arr[k][mid]>s && ((mid-1>=0 && arr[k][mid-1]<=s)||(mid-1<0)))
	return mid;
	if(arr[k][mid]<s)
	{
		return b_search(k,s,mid+1,v);
	}
	else
		return b_search(k,s,u,mid-1);
}

int main()
{
	for(int i =0;i<101;i++)
		{
			vector<int>temp;
			arr.PB(temp);
		}
		int c =0;
		cin>>c;
		for(int i =0;i<c;i++)
		{
			int y =0;
			cin>>y;
			arr[y].PB(i);
		}
		cout<<b_search(1,3,0,arr[1].size()-1)<<endl;
	return 0;
}