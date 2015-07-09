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

bool check(int arr[5],int value,int d)
{
	//cout<<value<<endl;
	if(d ==5)
	{
	if(value ==23)
	return true;
	else
	return false;
	}
	else
	{
				if( check(arr,value+arr[d],d+1)|| check(arr,value-arr[d],d+1)|| check(arr,value*arr[d],d+1))
				return true;
				else return false;
	}
}

bool permute(int arr[5],bool v[5],int c,int combi[5])
{
	if(c==5)
	{
	//for(int i =0;i<5;i++)
	//cout<<combi[i]<<" ";
	//cout<<endl;
	return check(combi,combi[0],1);
	}
	else
	{
		for(int i =0;i<5;i++)
		{
			if(!v[i])
			{
			v[i] = true;
			combi[c] = arr[i];
			if( permute(arr,v,c+1,combi))
			return true;
			v[i] = false;
			}
		}
		return false;
	}
}

int main()
{
	int n =5;
	int arr[5];int temp[5];
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	while(a!=0 &&b!=0 &&c!=0 &&d!=0 &&e!=0)
	{
	arr[0] = a;arr[1] = b;arr[2] = c;arr[3] = d;arr[4] = e;
	bool v[5];
	fill(v, v+5, false);
	if(permute(arr,v,0,temp))
	cout<<"Possible";
	else
	cout<<"Impossible";
	cout<<endl;
	cin>>a>>b>>c>>d>>e;
	}
	return 0;
}