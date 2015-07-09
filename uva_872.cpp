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

map<char,vector<char> >mapp;
vector<char>arr;
bool visited[30];
void init()
{
	for(int i =0;i<30;i++)
	{
		visited[i] = false;
	}
}
bool isValid(char e)
{
	for(int i =0;i<mapp[e].size();i++)
	if(visited[mapp[e][i]-'A'] == true)
	return false;
	return true;
}
bool bt;
void DFS(vector<char>st)
{
	if(st.size()== arr.size())
	{
		
		for(int i =0;i<arr.size();i++)
		{
			if(i==arr.size()-1)
				cout<<st[i];
			else
			cout<<st[i]<<" ";
		}
		cout<<endl;
		bt = false;
	}
	else
	{
		for(int i =0;i<arr.size();i++)
		{
			if(!visited[arr[i] -'A']&& isValid(arr[i]))
			{
				vector<char>temp =st;
				temp.PB(arr[i]);
				visited[arr[i] -'A'] = true;
				DFS(temp);
				visited[arr[i]-'A'] = false;
			}
		}
	}
}
int main()
{
	int n =0;
	scanf("%d\n\n",&n);
	string s;
	while(n>0)
	{
		char x;
		string s;
		getline(cin,s);
		for(int i =0;i<s.size();i++)
		{
			vector<char>temp;
			if(s[i]!=' ')
			{
			mapp[s[i]] = temp;
			arr.PB(s[i]);
			}
		}
		bt = true;
		sort(arr.begin(),arr.end());
		stringstream ss;
		string line;
		getline(cin,line);
		ss.str(line);
		char uu,y,z;
		while(ss>>uu>>y>>z)
		{
			mapp[uu].PB(z);
		}
		for(int i =0;i<n;i++)
		{
			vector<char>temp;init();
			DFS(temp);
		}
		if(bt)
			cout<<"NO"<<endl;
		mapp.erase(mapp.begin(),mapp.end());
		arr.erase(arr.begin(),arr.end());
		n--;
		if(n!=0)
		cout<<endl;
	}
	return 0;
}