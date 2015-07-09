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
bool bt = true;
bool visited[51][51];
int a,b;char c;
int m,n;
void move(char x)
{
	if(bt == false)
	return;
	if(x=='R')
	{
		if(c=='E')
			c='S';
		else if(c=='W')
			c='N';
		else if(c=='N')
			c='E';
		else if(c=='S')
			c='W';
	}
	else if(x=='L')
	{
		if(c=='E')
			c='N';
		else if(c=='W')
			c='S';
		else if(c=='N')
			c='W';
		else if(c=='S')
			c='E';
	}
	else
	{
		if(c=='E')
		{
			if(visited[a][b] && a+1>m)
			return;
			if(a+1>m)
			{
			visited[a][b] = true;
			bt= false;
			}
			else
			a++;
		}
		else if(c=='W')
		{
			if(visited[a][b] && a-1<0)
			return;
			if(a-1<0)
			{
			visited[a][b] = true;
			bt= false;
			}
			else
			a--;
		}
		else if(c=='N')
		{
		if(visited[a][b] && b+1>n)
			return;
			if(b+1>n)
			{
			visited[a][b] = true;
			bt= false;
			}
			else
			b++;
		}
		else if(c=='S')
		{
			if(visited[a][b] && b-1<0)
			return;
			if(b-1<0)
			{
			visited[a][b] = true;
			bt= false;
			}
			else
			b--;
		}
	}
}

void travel()
{
	for(int i =0;i<51;i++)
		for(int j=0;j<51;j++)
		visited[i][j] = false;
}
int main()
{
	cin>>m>>n;
	travel();
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		cin>>c;
		string s;
		cin>>s;
		//cout<<s<<endl;
		for(int i =0;i<s.size();i++)
		{
			if(bt == false)
			break;
			move(s[i]);
		}
		cout<<a<<" "<<b<<" "<<c;
		if(bt== false)
		cout<<" LOST";
		cout<<endl;
		bt = true;
	}
	return 0;
}