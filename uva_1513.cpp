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
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		vector<int>arr(x);
		for(int  i=0;i<x;i++)
		arr[i] = i+1;
		for(int j =0;j<y;j++)
		{
			int r =0;
			cin>>r;
			for(int i =0;i<x;i++)
			{
				if(arr[i] == r)
				{
				arr.erase(arr.begin()+i);
				cout<<i;
				arr.insert(arr.begin(),r);
				break;
				}
			}
			if(j != y-1)
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}