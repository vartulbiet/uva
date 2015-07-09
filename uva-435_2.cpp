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
bool find_value(int a,vector<int>arr)
{
		
	for(int i =0;i<arr.size();i++)
	{
		if(a == arr[i])
		return true;
	}
	return false;
}
int main()
{
	int n =0;
	cin>>n;
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
		for(int i=0;i<(1<<h);i++)
		{
			int y =i;
			vector<int>notPushed;
			int t =0;
			int n =0;
			while(y!=0)
			{
				if(y&1)
				{
					t+= arr[arr.size()-n-1];
					notPushed.PB(arr.size()-n-1);
				}
				n++;
				y>>=1;
			}
			vector<int>nn;
			for(int k =0;k<h;k++)
			{
				bool bt =true;
				for(int kk =0;kk<notPushed.size();kk++)
				if(notPushed[kk] == k)
				bt =false;
				if(bt== true)
				nn.PB(arr[k]);
			}
			for(int k = 0;k<nn.size();k++)
			if(nn[k]+t>=total && t<total)
			mymap[nn[k]]++;
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