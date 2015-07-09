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
pair<ull,ull> binary_search(ull*arr,ull key,int s,int n)
{
	if(s>n)
	return make_pair(0,0);
	else
	{
		int mid = (n+s)/2;
		if(arr[mid]==key)
		return make_pair(arr[mid-1],arr[mid+1]);
		else if(arr[mid]<key && arr[mid+1]>key)
		return make_pair(arr[mid],arr[mid+1]);
		else if(arr[mid]>key)
		{
			return binary_search(arr,key,s,mid);
		}
		else 
			return binary_search(arr,key,mid,n);
	}
}
int main()
{
	int n =0;
	scanf("%d",&n);
	ull arr[n];
	for(int i =0;i<n;i++)
	{
		ull ff =0;
	scanf("%ull",&ff);
	arr[i] =ff;
	}

	int q =0;
	scanf("%d",&q);
	for(int i =0;i<q;i++)
	{
		ull z =0;
		scanf("%ull",&z);
		//cout<<z<<endl;
		if(z>arr[n-1])
		cout<<arr[n-1]<<" "<<"X"<<endl;
		else if(z<arr[0])
		cout<<"X"<<" "<<arr[n-1]<<endl;
		else
		{
		pair<ull,ull>p = binary_search(arr,z,0,n);
		cout<<p.first<<" "<<p.second<<endl;
		}
	}
	return 0;
}