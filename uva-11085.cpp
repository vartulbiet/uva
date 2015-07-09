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

vector< vector<int> >mymap;

bool check(int val[8],int a,int b)
{
	for(int i =0;i<a;i++)
	{
		if(abs(i-a) == abs(val[i]-b))
		return false;
	}
	return true;
}
bool search(vector<int>val)
{
	for(int i =0;i<mymap.size();i++)
	{
		vector<int>x =mymap[i];
		int j =0;
		for( j =0;i<8;i++)
		{
			if(x[j]!=val[j])
			break;
		}
		if(j==8)
		return false;
	}
	return true;
}

void recurse(int val[8],bool arr[8],int t)
{
	if(t==8)
	{
	vector<int>x(8);
	for(int i =0;i<8;i++)
	x[i ] =val[i];
	if(search(x))
	{
		
		//cout<<endl;
		mymap.PB(x);
	}
	}
	else
	{
			for(int j =0;j<8;j++)
			{
				if(arr[j] == false && check(val,t,j))
				{
					val[t] = j;
					arr[j] =true;
					recurse(val,arr,t+1);
					arr[j] = false;
				}
			}
	}
}
int main()
{
	bool arr[8];
	for(int i =0;i<8;i++)
	{
			arr[i] = false;
	}
	int val[8];
	recurse(val,arr,0);
	int tt =0;
	int k =1;
	while(scanf("%d",&tt)==1)
	{
		vector<int> vec(8);
		vec[0] = tt-1;
		cout<<"Case "<<k++<<": ";
		for(int i =1;i<8;i++)
		{
			cin>>tt;
			vec[i] = tt-1;
		}
		int ans =7;
		for(int j =0;j<mymap.size();j++)
		{	
			vector<int>c = mymap[j];
			int t =0;
			
			for(int i =0;i<8;i++)
			{
				if(c[i] != vec[i])
				t++;
			}
			if(t<ans)
			ans =t;
 		}
		cout<<ans<<endl;
	}
	return 0;
}