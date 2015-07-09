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
	vector<int>vec;
	int j =0;
	cin>>j;
	for(int i =0;i<j;i++)
	{
		int u =0;
		cin>>u;
		vec.PB(u);
	}
	int sz =vec.size();
	int k = 1<<sz;
	cout<<k<<endl;
	for(int  i =1;i<(1<<sz);i++)
	{
		int y =i;
		vector<int>sum;
		int n =0;
		while(y!=0)
		{
			if(y&1)
			sum.PB(vec[vec.size()-n-1]);
			n++;
			y>>=1;
		}
		for(int k = 0;k<sum.size();k++)
		cout<<sum[k]<<" ";
		cout<<endl;
	}
}