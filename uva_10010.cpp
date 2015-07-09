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
bool bt;
char arr[55][55];
int a,b;
void update()
{
	for(int i =0;i<a;i++)
		{
			for(int j =0;j<b;j++)
			{
				if(arr[i][j]<'a')
				arr[i][j] = arr[i][j]+32;
			}
		}
}
string change(string x)
{
	string t;
	for(int i =0;i<x.size();i++)
	if(x[i]<'a')
	t.PB(x[i]+32);
	else
	t.PB(x[i]);
	return t;
}
void check(int i,int j,string s,int k,int c,int d)
{
	if(k==s.size())
	bt = false;
	else
	{
		if(i+c>=0 && i+c<a && j+d>=0 && j+d<b)
		{
			if(arr[i+c][j+d]==s[k])
			check(i+c,j+d,s,k+1,c,d);
		}
		else
		return;
	}
}
int main()
{
	int n =0;
	cin>>n;
	int tc =0;
	while(n!=0)
	{
		if(tc!=0)
		cout<<endl;
		tc++;
		cin>>a>>b;
		for(int i =0;i<a;i++)
		{
			scanf("%s",arr[i]);
		}
		update();
		int c =0;
		scanf("%d",&c);
		string t;getline(cin,t);
		
		for(int i =0;i<c;i++)
		{
			bt = true;
			getline(cin,t);
			string s = change(t);
			//cout<<s<<endl;
			for(int i =0;i<a && bt;i++)
			{
				for(int j =0;j<b && bt;j++)
				{
					if(arr[i][j] == s[0])
					{
						if(bt)
						check(i,j,s,1,-1,-1);
						if(bt)
						check(i,j,s,1,-1,0);
						if(bt)
						check(i,j,s,1,-1,1);
						if(bt)
						check(i,j,s,1,0,-1);
						if(bt)
						check(i,j,s,1,0,1);
						if(bt)
						check(i,j,s,1,1,-1);
						if(bt)
						check(i,j,s,1,1,0);
						if(bt)
						check(i,j,s,1,1,1);
						if(!bt)
						cout<<i+1<<" "<<j+1<<endl;
					}
				}
			}
		}
		n--;
	}
	return 0;
}