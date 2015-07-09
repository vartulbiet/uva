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
bool ct;
bool recurse(int arr[5],bool v[5],int value,int d)
{
	//cout<<value<<endl;
	if((value==23 && d==5 )|| ct)
	return true;
	else
	{
		bool bt =false;
		for(int i =0;i<5;i++)
		{
			if(v[i] == false)
			{
				v[i] =true;
				bt = bt|| recurse(arr,v,value+arr[i],d+1) ;
				if(bt ==true)
				ct =true;
				bt = bt || recurse(arr,v,value-arr[i],d+1) ;
				if(bt ==true)
				ct =true;
				bt = bt || recurse(arr,v,value*arr[i],d+1);
				if(bt ==true)
				ct =true;
				v[i] = false;
			}
		}
		return bt;
	}
}
int main()
{
	int n =5;
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	int arr[5];bool v[5];
	while(a!=0 && b!=0 &&c!=0 &&d!=0 &&e!=0)
	{
	
	arr[0] = a;arr[1] = b;arr[2] = c;arr[3] = d;arr[4] = e;
	bool bt =false;ct=false;
	fill(v,v+5,false);
	for(int i =0;i<5;i++)
	{
	v[i] = true;
	 bt = bt || recurse(arr,v,arr[i],1);
	 v[i]= false;
	 if(bt)
	 break;
	// cout<<"+++++++"<<endl;
	}
	if(bt)
	cout<<"Possible";
	else
	cout<<"Impossible";
	cout<<endl;
	cin>>a>>b>>c>>d>>e;
	}
	return 0;
}