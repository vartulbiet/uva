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
	stack<int> arr[51];
void init()
{
	for(int i =0;i<51;i++)
	{
		stack<int>st;
	arr[i] = st;
	}
}
bool check(stack<int>st,int ball)
{
	if(st.empty())
	return true;
	else if(sqrt(st.top()+ball) == (int)sqrt(st.top()+ball))
	return true;
	else
	return false;
}
void recurse(int*balls,int pegs)
{
	if(*balls>1300)
	{
	*balls =1;
	return;
	}
	for(int i =0;i<pegs;i++)
	{
		int x = *balls;
		stack<int> st =arr[i];
		if(check(st,x))
		{
			st.push(x);
			arr[i] = st;
			x++;
			*balls= x;
			recurse(balls,pegs);
			return;
		}
	}
	return;
}
int main()
{
	int tc = 0;
	scanf("%d",&tc);
	
	while(tc>0)
	{
		init();
		int pegs;
		scanf("%d",&pegs);
		int balls =0;
		recurse(&balls,pegs);
		cout<<balls-1<<endl;
		tc--;
	}
	return 0;
}