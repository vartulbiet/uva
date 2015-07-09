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
#define INF 1<<30
using namespace std;
int ct  =0;
char mat[105][105];
void traverse(string s,char ori,int ind,int m,int n,int ci,int cj)
{
	//cout<<ci<<cj<<endl;
	if(mat[ci][cj] == '*')
	{ct++;mat[ci][cj] = '.';}
	if(ind >= s.size())
	return;
	else
	{
	if(ind<s.size() && s[ind] == 'F')
	{
		if(ori == 'N')
		{
			int ni = ci -1;
			int nj = cj;
			if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj] != '#')
			{
				 traverse(s,ori,ind+1,m,n,ni,nj);
			}
			else
				traverse(s,ori,ind+1,m,n,ci,cj);
		}
		else if(ori == 'S')
		{
			int ni = ci+1;
			int nj = cj;
			if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj] != '#')
			{
				traverse(s,ori,ind+1,m,n,ni,nj);
			}
			else
				traverse(s,ori,ind+1,m,n,ci,cj);
		}
		else if(ori == 'L')
		{
			int ni = ci;
			int nj = cj+1;
			if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj] != '#')
			{
				traverse(s,ori,ind+1,m,n,ni,nj);
			}
			else
				traverse(s,ori,ind+1,m,n,ci,cj);
		}
		else if(ori == 'O')
		{
			int ni = ci;
			int nj = cj-1;
			if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj] != '#')
			{
					 traverse(s,ori,ind+1,m,n,ni,nj);
			}
			else
				traverse(s,ori,ind+1,m,n,ci,cj);
		}
	}
	else if( ind<s.size() && s[ind] == 'E')
	{
		if(ori == 'N')
		{
		 traverse(s,'O',ind+1,m,n,ci,cj);
		}
		else if(ori == 'S')
		{
		 traverse(s,'L',ind+1,m,n,ci,cj);
		}
		else if(ori == 'L')
		{
		 traverse(s,'N',ind+1,m,n,ci,cj);
		}
		else if(ori == 'O')
		{
		 traverse(s,'S',ind+1,m,n,ci,cj);
		}
	}
	else if(ind<s.size() && s[ind] == 'D')
	{
		if(ori == 'N')
		{
		 traverse(s,'L',ind+1,m,n,ci,cj);
		}
		else if(ori == 'S')
		{
		 traverse(s,'O',ind+1,m,n,ci,cj);
		}
		else if(ori == 'L')
		{
		 traverse(s,'S',ind+1,m,n,ci,cj);
		}
		else if(ori == 'O')
		{
		 traverse(s,'N',ind+1,m,n,ci,cj);
		}
	}
	else
	return;
	}
}
int main()
{
	int m,n,p;
	cin>>m>>n>>p;

	while(m!=0 && n!=0 && p!=0)
	{
		//cout<<m<<n<<p;
		int x,y;
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<n;j++)
			{
				cin>>mat[i][j];//cout<<mat[i][j];
				if(mat[i][j] == 'N' || mat[i][j] == 'S' || mat[i][j] == 'L' || mat[i][j] == 'O')
				{
					x = i;
					y = j;
				}
			}
		}
		string s;
		getline(cin,s);
		getline(cin,s);
		//cout<<s<<endl;
		traverse(s,mat[x][y],0,m,n,x,y);
		cout<<ct<<endl;
		ct = 0;
		cin>>m>>n>>p;
	}
}