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
string s;
void backtrack(map<char,char>vec,char a,char b)
{
	if(a==b)
	return;
	else
	{
		s.PB(b);
		backtrack(vec,a,vec[b]);
	}
}
void bfs(string a,string b,map<string,list<string> >mymap)
{
	queue<string>q;
	q.push(a);
	map<string,bool>my;
	for(std::map<string,list<string> >::iterator it =mymap.begin();it!=mymap.end();it++)
	my[it->first] = false;
	map<char,char>vec;
	vec[a[0]]=a[0];
	while(!q.empty())
	{
		string z = q.front();
		q.pop();
		list<string>l =mymap[z];
		for(std::list<string>::iterator i =l.begin();i!=l.end();i++)
			if(my[*i]==false)
			{
				string h =*i;
				q.push(h);
				vec[h[0]] = z[0];
				my[h] = true;
				if(h==b)
				break;
			}
	}
	backtrack(vec,a[0],b[0]);
	s.PB(a[0]);
	reverse(s.begin(),s.end());
	cout<<s<<endl;
	s.erase(s.begin(),s.end());
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int a,b;
		cin>>a>>b;
		map<string,list<string> >mymap;
		for(int i =0;i<a;i++)
		{
			string x,y;
			cin>>x>>y;
			list<string>l =mymap[x];
			l.PB(y);
			list<string>r =mymap[y];
			r.PB(x);
			mymap[x] =l;
			mymap[y] =r;
		}
		for(int i =0;i<b;i++)
		{
			string x,y;
			cin>>x>>y;
			bfs(x,y,mymap);
		}
		if(n>1)
		cout<<endl;
		n--;
	}
}