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
using namespace std;
char graph[25][25];int n =0;
void init()
{
	for(int i =0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				graph[i][j]==')';
			}
		}
}
map<string,bool>mymap;

void recurse(int i,int j,string s)
{
	if(s.size()<=n*n)
	{
		if(s.size()>=3)
		{
			if(mymap.find(s)==mymap.end())
			mymap[s] = true;
		}
		if(i+1>=0 && i+1<n && j+1>=0 && j+1<n && graph[i+1][j+1]>graph[i][j])
		{
			string zz =s;
			zz.push_back(graph[i+1][j+1]);
			recurse(i+1,j+1,zz);
		}
		if(i-1>=0 && i-1<n && j-1>=0 && j-1<n && graph[i-1][j-1]>graph[i][j])
		{
			string zz =s;
			zz.push_back(graph[i-1][j-1]);
			recurse(i-1,j-1,zz);
		}
		if(i+1>=0 && i+1<n && j-1>=0 && j-1<n && graph[i+1][j-1]>graph[i][j])
		{
			string zz =s;
			zz.push_back(graph[i+1][j-1]);
			recurse(i+1,j-1,zz);
		}
		if(i-1>=0 && i-1<n && j+1>=0 && j+1<n && graph[i-1][j+1]>graph[i][j])
		{
			string zz =s;
			zz.push_back(graph[i-1][j+1]);
			recurse(i-1,j+1,zz);
		}
		if(j+1>=0 && j+1<n && graph[i][j+1]>graph[i][j])
		{
			string zz =s;
			zz.push_back(graph[i][j+1]);
			recurse(i,j+1,zz);
		}
		if(j-1>=0 && j-1<n && graph[i][j-1]>graph[i][j])
		{
			string zz =s;
			zz.push_back(graph[i][j-1]);
			recurse(i,j-1,zz);
		}
		if(i+1>=0 && i+1<n && graph[i+1][j]>graph[i][j])
		{
			string zz =s;
			zz.push_back(graph[i+1][j]);
			recurse(i+1,j,zz);
		}
		if(i-1>=0 && i-1<n &&  graph[i-1][j]>graph[i][j])
		{
			string zz =s;
			zz.push_back(graph[i-1][j]);
			recurse(i-1,j,zz);
		}
		else
		return;
	}
	else
	return;
}
int main()
{
	int tc =0;
	cin>>tc;
	
	while(tc!=0)
	{
	init();
		cin>>n;
		for(int i =0;i<n;i++)
		{
			cin>>graph[i];
		}
		for(int i =0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				string temp;
				temp.push_back(graph[i][j]);
				recurse(i,j,temp);
			}
		}
		vector<pair<int,string> >vec;
		for(std::map<string,bool>::iterator it  = mymap.begin();it!=mymap.end();it++)
		{
			string h =it->first;
			vec.PB(make_pair(h.size(),it->first));
		}
		sort(vec.begin(),vec.end());
		for(int jj =0;jj<vec.size();jj++)
		{
			cout<<vec[jj].second<<endl;
		}
		if(tc!=1)
		cout<<endl;
		tc--;
		mymap.erase(mymap.begin(),mymap.end());
	}
	return 0;
}