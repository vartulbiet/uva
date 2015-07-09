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
char arr[105][105];
int end1,end2;
bool bt;
int n =0;
void check(int a,int b,string s,int i,int c,int d)
{
	if(i==s.size())
	{
		end1=a;
		end2=b;
		bt = false;
		return;
	}
	else
	{
		if(arr[a+c][b+d]==s[i])
		{
			int x = a+c;
			int y= b+d;
			if((x+c>=0 && x+c<n && y+d>=0 && y+d<n)|| i==s.size()-1)
			check(x,y,s,i+1,c,d);
		}
		else
		return;
	}
}
int main()
{
	cin>>n;
	for(int i =0;i<n;i++)
	{
		scanf("%s",arr[i]);
	}
	string s;
	getline(cin,s);bt = true;
			getline(cin,s);
	while(s!="0")
	{
		for(int i =0;i<n && bt;i++)
		{
			for(int j=0;j<n && bt;j++)
			{
				if(arr[i][j] == s[0] )
				{
					if(i+1>=0 && i+1<n && j+1>=0 && j+1<n && bt)
					check(i,j,s,1,1,1);
					if(i-1>=0 && i-1<n && j-1>=0 && j-1<n && bt)
					check(i,j,s,1,-1,-1);
					if(i-1>=0 && i-1<n && j>=0 && j<n && bt)
					check(i,j,s,1,-1,0);
					if(i-1>=0 && i-1<n && j+1>=0 && j+1<n && bt)
					check(i,j,s,1,-1,1);
					if(i>=0 && i<n && j-1>=0 && j-1<n && bt)
					check(i,j,s,1,0,-1);
					if(i>=0 && i<n && j+1>=0 && j+1<n && bt)
					check(i,j,s,1,0,1);
					if(i+1>=0 && i+1<n && j-1>=0 && j-1<n && bt)
					check(i,j,s,1,1,-1);
					if(i+1>=0 && i+1<n && j>=0 && j<n && bt)
					check(i,j,s,1,1,0);
					if(!bt)
					cout<<i+1<<","<<j+1<<" "<<end1+1<<","<<end2+1<<endl;
				}
			}
		}
		if(bt)
		cout<<"Not found"<<endl;
		getline(cin,s);
		bt = true;
	}
	return 0;
}