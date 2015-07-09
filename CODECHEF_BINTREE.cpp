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
int main()
{
	int n =0;
	cin>>n;
	for(int i =0;i<n;i++)
	{
		ull x,y;
		cin>>x>>y;
		int arr[50];
		int brr[50];
		memset(arr,0,sizeof(arr));
		memset(brr,0,sizeof(brr));
		for(int i =0;i<50,x>0;i++)
		{
			arr[i] = x;
			x =x/2;
		}
		//for(int i =0;i<50;i++)
		//cout<<arr[i]<<" ";
		//cout<<endl;
		bool bt = true;
		int c =0;int d  =0;
		while(y>0 && bt)
		{
			for(int i =0;i<50 && bt;i++)
			{
				if(y == arr[i])
					{ d =i;
					 bt =false;}
			}
			if(bt)
			c++;
			y =y/2;
		}
		//cout<<c<<d<<endl;
		cout<<c+d<<endl;
	}
	return 0;
}