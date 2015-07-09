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

int graph[30][30];
vector<char>arr;
map<char,int>mymap;
bool visited[30];
void init()
{
	for(int i =0;i<30;i++)
	{
		for(int j =0;j<30;j++)
		graph[i][j] = 0;
		visited[i] = false;
	}
}
void do_topo(int m,stack<char>&st)
{
	visited[m] = true;
	int n = mymap.size();
	for(int j =n-1;j>=0;j--)
	{
		if(!visited[j] && graph[m][j]==1)
		{
			do_topo(j,st);
		}
	}
	st.push(arr[m]);
}
void topo_sort()
{
	int n = mymap.size();
	
	for(int j = n-1;j>=0;j--)
	{
		stack<char>st;
			for(int i =0;i<30;i++)
		visited[i]= false;
		do_topo(j,st);
		for(int i =0; i<n;i++)
		{
			if(!visited[i] )
			{
				do_topo(i,st);
			}
		}
		while(!st.empty())
	{
				cout<<st.top()<<" ";
				st.pop();
	}
	cout<<endl;
	}
	
}

int main()
{
	int n =0;
	cin>>n;
	string s;
		getline(cin,s);
	while(n>0)
	{
		getline(cin,s);
		char x;
		string s;
		getline(cin,s);
		for(int i =0;i<s.size();i++)
		{
			if(s[i]!=' ')
			arr.PB(s[i]);
		}
		sort(arr.begin(),arr.end());
		for(int i =0;i<arr.size();i++)
		{
			mymap[arr[i]]= i;
		}
		while(cin>>s)
		{
			graph[mymap[s[0]]][mymap[s[2]]] = 1;
		}
		topo_sort();
		mymap.erase(mymap.begin(),mymap.end());
		arr.erase(arr.begin(),arr.end());
		n--;
	}
}