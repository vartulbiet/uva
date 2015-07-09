#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;int t =0;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int>x;
	
		t++;
		for(int i =0;i<n;i++)
		{
			int y =0;
			cin>>y;
			x.push_back(y);
		}
		int sum =0;
		cin>>sum;
		sort(x.begin(),x.end());
		int p = 0,q=n-1;
		int d,e;
		
		while(p!=q)
		{
			if(x[p]+x[q] == sum)
			{//cout<<"Peter should buy books whose prices are "<<d<<" and "<<e<<"."<<endl;
				d = x[p];
				e = x[q];
				q--;
			}
			else {if(x[p]+x[q]>sum)
				q--;
				else
				p++;}
		}
		cout<<"Peter should buy books whose prices are "<<d<<" and "<<e<<"."<<endl;
		//cout<<d<<e<<endl;	if(t!=0)
		cout<<endl;
	}
	return 0;
}