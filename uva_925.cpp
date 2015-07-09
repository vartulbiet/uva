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
#define INF 1<<20
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	while(n--)
	{
		int x =0;
		cin>>x;
		int graph[125][125] ={};
		int nn =x;
		map<string,int>mymap;
		map<int,string>backmap;
		int i =0;
		vector<string>vec;
		while(x--)
		{
			string f;
			cin>>f;
			vec.PB(f);
		}
		sort(vec.begin(),vec.end());
		x =nn;
		while(x--)
		{
			mymap[vec[i]] = i;
			backmap[i++] = vec[i];
		}
		int y =0;
		cin>>y;
		while(y--)
		{
			string g;
			cin>>g;
			int l= mymap[g];
			int u =0;
			cin>>u;
			while(u--)
			{
				string gf;
			cin>>gf;
			int o= mymap[gf];
			graph[l][o] =1;
			}
		}

		for(int i =0;i<nn;i++)
		for(int h =0;h<nn;h++)
		for(int k =0;k<nn;k++)
		{
		if(graph[h][i]!=0 && graph[i][k]!=0)
		graph[h][k] = max(graph[h][k],graph[h][i]+graph[i][k]);
		}
		
		vector<vector<int> >c;
		for(int i =0;i<nn;i++)
		{
			vector<int>f;
			for(int j =0;j<nn;j++)
			{
				if(graph[i][j] == 1)
				f.PB(j);
			}
			c.PB(f);
		}
		for(int i =0;i<nn;i++)
		{
			if(c[i].size())
			{
			cout<<backmap[i]<<" "<<c[i].size();
			for(int j =0;j<c[i].size();j++)
			{
				cout<<" "<<backmap[c[i][j]];
			}
			cout<<endl;
			}
		}
	}
	return 0;
}