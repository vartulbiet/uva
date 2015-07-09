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
	int n =0;
	cin>>n;int tc =1;
	while(n != 0)
	{
	double graph[35][35];
		map<string,int>mymap;
			for(int i =0;i<n;i++)
			for(int j=0;j<n;j++)
				graph[i][j] = 0;
		for(int i =0;i<n;i++)
		{
			string f;
			cin>>f;
			mymap[f] = i;
		}
		int m =0;
		cin>>m;
		for(int y =0;y<m;y++)
		{
			string a,b;
			double c;
			
			cin>>a>>c>>b;
			graph[mymap[a]][mymap[b]] =c;
		}
		bool bt = false;

		
		for(int i =0;i<n ;i++)
		{
			for(int j =0;j<n ;j++)
			{
				for(int k =0;k<n ;k++)
				{	
					graph[j][k] = max(graph[j][k],graph[j][i]*graph[i][k]);
				}
			}
		}
		for(int i =0;i<n;i++)
		{
			if(graph[i][i]>1.0)
			bt =true;
		}
		cout<<"Case "<<tc++<<": ";
		if(bt)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		cin>>n;
	}
}