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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
int ans;
void recurse(vector<int>x)
{
	if(x.size()<2)
	return;
	else
	{
		vector<int>give;
		for(int i =0;i<x.size();i = i+2)
		{
			if((x[i]==0 && x[i+1]== 1) || (x[i]==1 && x[i+1]== 0))
			ans++;
			if(x[i] == 0  && x[i+1]==0)
			{
				give.PB(0);
			}
			else
			give.PB(1);
		}
		recurse(give);
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int a,b;
		cin>>a>>b;ans =0;
		int c = pow(2,a);
		vector<int>vec(c);
		fill(vec.begin(),vec.begin()+c,1);
		for(int i =0;i<b;i++)
		{
			int x =0;
			cin>>x;
			vec[x-1] = 0;
		}
		recurse(vec);
		cout<<ans<<endl;
		n--;
	}
	return 0;
}