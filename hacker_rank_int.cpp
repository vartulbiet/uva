// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.
// The code fragment below shows you how to read from STDIN and write out to STDOUT. 
// When you press "Run Code", the inputs are taken from the contents of the INPUT tab below
// Your program's output (or compiler errors etc.) will appear in the OUTPUT tab.

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
int ans;
bool arr[16][16];
int n;
void init()
{
	for(int i =0;i<16;i++)
	for(int j =0;j<16;j++)
	{
	arr[i][j] = true;
	}
}
int x[8] = {-1,-1,-2,-2,1,1,2,2};
int y[8] = {-2,2,-1,1,-2,2,-1,1};
void serialize(int row,int col)
{
	arr[row][col] = false;
	for(int i =0;i<n;i++)
	arr[row][i] = false;
	for(int j =0 ;j<n;j++)
	arr[j][col ] = false;
	for(int i  = 0;i<8;i++)
	if(row+x[i]>=0 && col+y[i]>=0 && (row+x[i])<n && (col+y[i])<n)
	arr[row+x[i]][col+y[i]] = false;
	for(int i = -20;i<20;i++)
	{
		if(row+i>=0 && col+i>=0 && (row+i)<n && (col+i)<n)
		arr[row+i][col+i] = false;
		if(row+i>=0 && col-i>=0 && (row+i)<n && (col-i)<n)
		arr[row+i][col-i] = false;
		if(row-i>=0 && col-i>=0 && (row-i)<n && (col-i)<n)
		arr[row-i][col-i] = false;
		if(row-i>=0 && col+i>=0 && (row-i)<n && (col+i)<n)
		arr[row-i][col+i] = false;
	}
}
void coppy(vector<vector<int> >&temp)
{
	for(int i =0;i<n;i++)
	for(int j =0;j<n;j++)
	temp[i][j] = arr[i][j];
}
void d_copy(vector<vector<int> >&temp)
{
	for(int i =0;i<n;i++)
	for(int j =0;j<n;j++)
	arr[i][j] = temp[i][j];
}
map<vector<int>,bool>mymap;
void recursion(int count,int row,vector<int>store)
{
	if(count  == 0)
	{
	    if(mymap.find(store) ==mymap.end())
		{
		 ans++;
			mymap[store] = true;
		}
		return;
	}
		
	for(int c = 0;c<n;c++)
	{
		if(arr[row][c])
		{
			vector<vector<int> >vec;
			for(int i =0;i<16;i++)
			{
			vector<int>vecc(16);
			vec.PB(vecc);
			}
			coppy(vec);
			serialize(row,c);
			vector<int>st = store;
			st[row] = c;
			recursion(count-1,row+1,st);
			d_copy(vec);
		
		}
	}
}
int main()
{
	cin>>n;
	init();ans =0;
	for(int c =0;c<n;c++)
	{
		vector<vector<int> >vec;
		for(int i =0;i<16;i++)
			{
			vector<int>vecc(16);
			vec.PB(vecc);
			}
		init();
		vector<int>store(n);
		fill(store.begin(),store.end(),0);
		coppy(vec);
		serialize(0,c);
		store[0] = c;
		recursion(n-1,1,store);//cout<<endl;
	
	}
	cout<<ans<<endl;
	return 0;
}