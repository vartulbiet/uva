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
#define INF 1<<30
using namespace std;

  stack<int> sorted_st(stack<int>st)
 {
	stack<int>ans;
	while(!st.empty())
	{
		int x = st.top();
		st.pop();
		while(!ans.empty())
		{
			int y = ans.top();
			if(y<=x)
			{
			break;
			}
			else
			{
				ans.pop();
				st.push(y);
			}
		}
		ans.push(x);
	}
	while(!ans.empty())
	{
		int u = ans.top();
		ans.pop();
		st.push(u);
	}
	return st;
}
 
 int main()
 {
	stack<int>t;
	int n =0;
	cin>>n;
	while(n--)
	{
		int y =0;cin>>y;
		t.push(y);
	}
	stack<int>ans = sorted_st(t);
	while(!ans.empty())
	{
		int y = ans.top();
		ans.pop();
		cout<<y<<endl;
	}
 }