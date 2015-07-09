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
bool check(int a,int b)
{
	if(a>=0 && a<8 && b>=0 && b<8)
	return true;
	else return false;
}
int bfs(string a,string b)
{
	int ans =0;
	pair<int,int>x = make_pair((int)(a[0]-'a'),(int)(a[1]-'1'));
	pair<int,int>y = make_pair((int)(b[0]-'a'),(int)(b[1]-'1'));
	//cout<<x.first<<x.second;
	//cout<<y.first<<y.second;
	bool visited[8][8];
	for(int i = 0;i<8;i++)
	{
		for(int j =0;j<8;j++)
			visited[i][j] =false;
	}
	queue<pair<int,int> >q;
	q.push(x);bool bt = false;
	visited[x.first][x.second] = true;
	while(!q.empty())
	{
		queue<pair<int,int> >p;
		while(!q.empty())
		{
			pair<int,int> m = q.front();
			
			int c =m.first;
			int d =m.second;
		//	cout<<c<<d<<"  ";
			if(m==y)
			{
			bt =true;
			break;
			}
			q.pop();
			if(check(c-2,d-1) && visited[c-2][d-1]==false)
			{
				visited[c-2][d-1] = true;
				p.push(make_pair(c-2,d-1));
			}
			if(check(c-1,d-2) && visited[c-1][d-2]==false)
			{
				visited[c-1][d-2] = true;
				p.push(make_pair(c-1,d-2));
			}
			if(check(c+2,d-1) && visited[c+2][d-1]==false)
			{
				visited[c+2][d-1] = true;
				p.push(make_pair(c+2,d-1));
			}
			if(check(c-2,d+1) && visited[c-2][d+1]==false)
			{
				visited[c-2][d+1] = true;
				p.push(make_pair(c-2,d+1));
			}
			if(check(c-1,d+2) && visited[c-1][d+2]==false)
			{
				visited[c-1][d+2] = true;
				p.push(make_pair(c-1,d+2));
			}
			if(check(c+2,d+1) && visited[c+2][d+1]==false)
			{
				visited[c+2][d+1] = true;
				p.push(make_pair(c+2,d+1));
			}
			if(check(c+1,d-2) && visited[c+1][d-2]==false)
			{
				visited[c+1][d-2] = true;
				p.push(make_pair(c+1,d-2));
			}
			if(check(c+1,d+2) && visited[c+1][d+2]==false)
			{
				visited[c+1][d+2] = true;
				p.push(make_pair(c+1,d+2));
			}
		}
		if(bt)
		break;
		if(q.empty())
		{
			ans++;
			
			swap(p,q);
		}
	}
	return ans;
}

int main()
{
	string a;
	while(cin>>a)
	{
		string b;
		cin>>b;
		cout<<"To get from "<<a<<" to "<<b<<" takes "<<bfs(a,b)<<" knight moves."<<endl;
	}
	return 0;
}