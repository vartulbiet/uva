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
using namespace std;
int arr[100005];
int seg_tree[200010];
int make_query(int x,int y,int i,int j,int k)
{
	if(x>j|| y<i)
	return -1;
	if(i>=x && j<=y)
	return seg_tree[k];
	else
	{
		int p =make_query(x,y,i,j/2,2*k+1);
		int q =make_query(x,y,j/2+1,j,2*k+2);
		if(arr[p]>arr[q])
		return p;
		else 
		return q;
	}
}
void create_segment_tree(int i,int j,int k)
{

	if(i==j)
	{
		seg_tree[k] = i;
	}
	else
	{
		int mid = (j+i)/2;
		 create_segment_tree(i,mid,2*k+1);
		 create_segment_tree(mid+1,j,2*k+2);
		if(arr[seg_tree[2*k+1]]>arr[seg_tree[2*k+2]])
			seg_tree[k] =seg_tree[2*k+1];
		else
			seg_tree[k] =seg_tree[2*k+2];
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int q =0;
		cin>>q;
		for(int i =0;i<n;i++)
		{
			cin>>arr[i];
		}
		create_segment_tree(0,n-1,0);
		for(int i =0;i<q;i++)
		{
			int f,l;
			cin>>f>>l;
			cout<<arr[make_query(--f,--l,0,n-1,0)]<<endl;;
		}
		cin>>n;
	}
	return 0;
}