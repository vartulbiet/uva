#include <iostream>
#include <vector>
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
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull long long int  
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define M 1000000009
using namespace std;
int main()
{
	int n = 0;
	cin>>n;
	while(n--)
	{
		int x,y,z;
		queue<int>lq,rq;
		int current_time = 0;
		cin>>x>>y>>z;
		for(int i =0 ;i < z ; i++)
		{
			int t;
			string s;
			cin>>t>>s;
			if(s == "left")
				lq.push(t);
			else
				rq.push(t);
		}
		bool bt =true;
		while(!lq.empty() && !rq.empty())
		{
			if(bt)
			{
				int u = 0;
				while(!lq.empty() && u<x && lq.front()<= current_time)
				{
					int yy = lq.front();
					lq.pop();
					u++;
					bt = false;
				}
			}
			
			current_time+=y;
			u = 0;
			while(!rq.empty() && u<x && rq.front()<= current_time)
				{
					int yy = lq.front();
					rq.pop();
					u++;
				}
				current_time++;
			
		}
	}
	return 0;
}