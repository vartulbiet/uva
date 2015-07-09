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
vector<string>mymap;
void recurse(string arr,int c,string vec)
{
	if(c==0)
	mymap.PB(vec);
	else
	{
		for(int i =0;i<arr.size();i++)
		{
			string t =vec;
			t.PB(arr[i]);
			recurse(arr,c-1,t);
		}
	}
}
bool bt;int m;
void recurse_again(int k,vector<bool>visited,string s)
{
	if(!bt)
	return;
	if(k==0)
	{
		for(int i = 0;i<s.size();i++)
		cout<<s[i]+0;
		bt= false;
		cout<<endl;
	}
	else
	{
		for(int i =0;i<mymap.size() && bt;i++)
		{
			string t= mymap[i];
			string y= t.substr(0,m-1);
			string g;
			if(s.size()>=m)
			{
			 g = s.substr(s.size()-m,m-1);
				if(visited[i] ==false &&(k==mymap.size() || g==y ))
				{
					vector<bool>temp = visited;
					temp[i]= true;
					string tt =s;
					tt+=mymap[i][m-1];
					recurse_again(k-1,temp,tt);
				}
			}
			else
			{
				vector<bool>temp = visited;
				temp[i]= true;
				recurse_again(k-1,temp,mymap[i]);
			}
		}
	}
}
int main()
{
	int n;
	while(scanf("%d%d",&m,&n)==2)
	{
	bt= true;
		string arr;
		for(int i =0;i<n;i++)
		arr.PB(i);
		string vec;
		recurse(arr,m,vec);
		string val;
		vector<bool>visited(mymap.size());
		fill(visited.begin(),visited.end(),false);
		recurse_again(mymap.size(),visited, val);
		mymap.erase(mymap.begin(),mymap.end());
		cout<<endl;
	}
	return 0;
}