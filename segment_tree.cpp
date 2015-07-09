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
int seg_size;
int n;
void construct_ST_util(int*seg,int*arr,int s,int e,int ind)
{
	if(s == e)
	{
	seg[ind] = arr[s];
	return;
	}
	else
	{
		int mid = s+(e-s)/2;
		int sum =0;
		for(int i = s;i<=e;i++)
		{
			sum+=arr[i];
		}
		seg[ind] = sum;
		//cout<<s<<" "<<e<<" "<<sum<<endl;
		construct_ST_util(seg,arr,s,mid,2*ind+1);
		construct_ST_util(seg,arr,mid+1,e,2*ind+2);
		return ;
	}
}
void construct(int*seg_arr,int*arr)
{
	construct_ST_util(seg_arr,arr,0,n-1,0);
}
void print_seg_array(int*seg_arr)
{
	for(int i =0;i<seg_size;i++)
	cout<<seg_arr[i]<<" ";
	cout<<endl;
}
void update_util(int*seg,int*arr,int i,int s,int e,int ind,int val)
{
	if(i<s || i>e)
		return;
	seg[ind] += val;
	 if(s != e)
	{
		int mid = s+(e-s)/2;
		//cout<<"  "<<seg[ind]<<endl;
		update_util(seg,arr,i,s,mid,2*ind+1,val);
		update_util(seg,arr,i,mid+1,e,2*ind+2,val);
	}
}
void update(int*seg,int*arr,int i,int val)
{
	if(i<0 || i>=n)
	return;
	
	int diff = val - arr[i];
	cout<<"diff "<<diff<<endl;
	update_util(seg,arr,i,0,n-1,0,diff);
}
int sum_util(int* seg,int qs,int qe,int s,int e,int ind)
{
	if(qs<=s && e<=qe)
	return seg[ind];
	if(s>qe || e<qs)
	return 0;
	else
	{
		int mid = s+(e-s)/2;
		return (sum_util(seg,qs,qe,s,mid,2*ind+1)+sum_util(seg,qs,qe,mid+1,e,2*ind+2));
	}
}
int get_sum(int*seg_arr,int qs,int qe)
{
	if(qs<0 || qe>n-1 || qe<qs)
	return -1;
	else
	{
		return sum_util(seg_arr,qs,qe,0,n-1,0);
	}
}
int main()
{
	int arr[] = {1,3,5,7,9,11};
	n = 6;
	 int x = (int)(ceil(log2(n))); 
    seg_size = 2*(int)pow(2, x) - 1;
	int seg_array[seg_size];
	for(int i =0;i<seg_size;i++)
	seg_array[i] = 0;
	construct(seg_array,arr);
	print_seg_array(seg_array);
	int ind,value;
	cin>>ind>>value;
	update(seg_array,arr,ind,value);
	print_seg_array(seg_array);
	int query_s,query_e;
	cin>>query_s>>query_e;
	cout<<get_sum(seg_array,query_s,query_e)<<endl;
	return 0;
}