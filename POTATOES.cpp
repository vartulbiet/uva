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
int arr[2500];
void calc()
{
	arr[1] =0;
	arr[2] =1;
	arr[3] =1;
	for(int i=4;i<2500;i++)
	{
		int y= sqrt(i);bool bt =true;
		for(ull j =2;j<=y &&bt;j++)
		{
			if(i%j==0)
			{
				arr[i] =0;bt =false;
			}
		}
		if(bt)
			arr[i]=1;
	}
}
int main()
{
	int n =0;
	cin>>n;
	memset(arr,0,sizeof(arr));
	calc();
	while(n--)
	{
			int x,y;
			cin>>x>>y;
			int sum =x+y;
			for(int i =sum+1;i<2500;i++)
			{
				if(arr[i] ==1){
				cout<<i-sum<<endl;
				break;}
			}
	}
	return 0;
}