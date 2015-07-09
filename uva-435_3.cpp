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

int main()
{
	int n =0;
	cin>>n;
	int * values = new int[1 << 20];
	while(n>0)
	{
		int h =0;
		cin>>h;
		vector<int>arr;
		map<int,int>mymap;
		map<int,int>count;
		int total =0;
		for(int i =0;i<h;i++)
		{
			int g =0;
			cin>>g;
			total+=g;
			arr.PB(g);
			count[g]++;
		mymap[g] = 0;
		}
		total =total/2;
		total++;
		int k = 1<<h;
		for (int i = 0; i < (k); i++) 
            values[i] = 0;
		for(int i=0;i<(k);i++)
		{
			int y =i;int ll =0;
			while(y!=0)
			{
				if(y&1)
				{
					values[i]+= arr[arr.size()-ll-1];
				}
				ll++;
				y>>=1;
			}
		//	cout<<values[i]<<" ";
		}
		for(int i=0;i<(1<<h);i++)
		{
			int y =i;int ll =0;
			while(y!=0)
			{
				if(y&1)
				{
					if(values[i]-arr[arr.size()-ll-1]<total && values[i]>=total)
					mymap[arr[arr.size()-ll-1]]++;
				}
				ll++;
				y>>=1;
			}
		}
		for(int i =0;i<h;i++)
		{
			cout<<"party "<<i+1<<" has power index "<<mymap[arr[i]]/count[arr[i]];
			cout<<endl;
		}
			cout<<endl;
			n--;
	}
	return 0;
}