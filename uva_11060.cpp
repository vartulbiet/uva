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
#define INF 1<<10
using namespace std;
 int arr[105][105]; bool visited[105];
 vector<string>brr;
 void init()
 {
	for(int i =0;i<105;i++)
	{
		for(int j=0;j<105;j++)
		arr[i][j] =0;
		visited[i] = false;
	}
 }

 int n;
  void do_topo(int i,stack<int>&st)
 {
	visited[i] = true;
	for(int k =0;k<n;k++)
	{
		if(arr[i][k] == 1&& visited[k]==false)
		do_topo(k,st);
	}
	st.push(i);
 }
 stack<int>reversed(stack<int>st)
 {
	stack<int>r;
	while(!st.empty())
	{
		r.push(st.top());
		st.pop();
	}
	return r;
 }

 void topo_sort()
 {
	vector<stack<int> >vec;
	for(int i =0;i<n;i++)
	{
		stack<int>st;
		if(visited[i]==false)
		{
			do_topo(i,st);
			vec.PB(st);
		}
	}
	for(int i =0;i<vec.size();i++)
	{
		stack<int>cc =reversed(vec[i]);
		while(!cc.empty())
		{
			cout<<" "<<brr[cc.top()];
			cc.pop();
		}
	}
 }
 

int main()
{
	int tc =1;
		while(scanf("%d",&n)!=EOF)
		{
			init();
			map<string,int>mymap;
			string s;getline(cin,s);
			for(int i =0;i<n;i++)
			{
				getline(cin,s);
			//	cout<<s<<"-";
				mymap[s] =i;
				brr.PB(s);
			}
			int m =0;
			cin>>m;
			for(int i =0;i<m;i++)
			{
				string x,y;
				cin>>x>>y;
				//cout<<x<<y;
				arr[mymap[y]][mymap[x]] =1;
			}
			cout<<"Case #"<<tc++<<": Dilbert should drink beverages in this order:";
			topo_sort();
			cout<<"."<<endl;
			cout<<endl;
			brr.erase(brr.begin(),brr.end());
		}
		return 0;
}