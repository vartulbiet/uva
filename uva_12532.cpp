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
int get_product_util(int*seg_tree,int*arr,int s,int e,int x,int y,int ind)
{
	if(x<=s && e<=y)
	{
		return seg_tree[ind];
	}
	if(s>y || e<x)
	return 1;
	else
	{
		int mid = s+(e-s)/2;
		return get_product_util(seg_tree,arr,s,mid,x,y,2*ind+1)*get_product_util(seg_tree,arr,mid+1,e,x,y,2*ind+2);
	}
}

int get_product(int*seg_tree,int*arr,int m,int x,int y)
{
	return get_product_util(seg_tree,arr,0,m-1,x,y,0);
}
int update_util(int*seg_tree,int*arr,int s,int e,int x,int index,int val)
{
	if(x<s || x>e)
	return 1;
	//if(s == e)
	//seg_tree[index] = arr[x];
	if(s!=e)
	{
		int mid = s+(e-s)/2;
		seg_tree[index] = update_util(seg_tree,arr,s,mid,x,2*index+1,val)*update_util(seg_tree,arr,mid+1,e,x,2*index+2,val);
	}
}
void update(int*seg_tree,int *arr,int m,int x,int y)
{
	if(x>=m)
	return;
	if(( y > 0 && arr[x] > 0)|| ( y < 0 && arr[x] < 0) || ( y == 0 && arr[x] == 0))
		return;
	else
	{
		int tt =0;
		if(y>0)
		{
			cout<<"HI"<<endl;
			arr[x] = 1;
			tt =update_util(seg_tree,arr,0,m-1,x,0,-1);
		}
		else if(y<0)
		{
			arr[x] = -1;
			tt =update_util(seg_tree,arr,0,m-1,x,0,-1);
		}
		else if(y == 0)
		{
			arr[x] = 0;
			tt =update_util(seg_tree,arr,0,m-1,x,0,0);
		}
	}
}
void create_util(int*seg_tree,int*arr,int i,int j,int ind)
{
	if(i == j)
	seg_tree[ind] = arr[i];
	else
	{
		int mid =  i +(j-i)/2;
		int p =1;
		for(int k =i; k<=j;k++)
		p *=arr[k];
		seg_tree[ind] = p;

		create_util(seg_tree,arr,i,mid,2*ind+1);
		create_util(seg_tree,arr,mid+1,j,2*ind+2);
	}
}
void create_seg_tree(int* seg_tree,int*arr,int n)
{
	create_util(seg_tree,arr,0,n-1,0);
}
void print_seg_array(int*seg_arr,int seg_size)
{
	for(int i =0;i<seg_size;i++)
	cout<<seg_arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)==2)
	{
		int*arr  = (int*)malloc(sizeof(int)*m);
		memset(arr,0,sizeof(arr)*m);
				int x = (int)(ceil(log(m))); 
		int sz = 2*(int)pow(2, x) - 1;
		//cout<<sz<<endl;
		//int seg_tree[7];
		int*seg_tree = (int*)malloc(sizeof(int)*sz);
		for(int i =0;i<sz;i++)
		seg_tree[i] = 1;
		//cout<<"::";
		for(int i = 0;i< m;i++)
		{
			int y = 0;
			cin>>y;
			if(y>0)
			y = 1;
			if(y<0)
			y = -1;
			arr[i] = y;
		}
		create_seg_tree(seg_tree,arr,m);
	//	print_seg_array(seg_tree,sz);
		for(int i = 0 ; i < n ; i++)
		{
			char z;
			cin>>z;
			int x,y;
				cin>>x>>y;
			if(z == 'C')
			{
				update(seg_tree,arr,m,x-1,y);
				print_seg_array(seg_tree,sz);
			}
			else
			{
				int ans = get_product(seg_tree,arr,m,x-1,y-1);
				if(ans ==0)
				cout<<"0";
				else if(ans>0)
				cout<<"+";
				else cout<<"-";
				cout<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}