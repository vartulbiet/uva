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
char arr[10][10];
string s;
int m,n;
void init()
{
	for(int i =0;i<10;i++)
	{
		for(int j =0;j<10;j++)
			arr[i][j] = '0';
	}
}
void DFS(int a,int b,int ind)
{
	if(s[ind-1] =='#')
	return;
	else
	{
			if(ind !=0)
			cout<<" ";
		if(a>0&& arr[a-1][b]==s[ind])
		{
			//cout<<arr[a-1][b]<<endl;
			cout<<"forth";
			DFS(a-1,b,ind+1);
		}
		else if(b>0 && arr[a][b-1]==s[ind])
		{
			//cout<<arr[a][b-1]<<endl;
			cout<<"left";
			DFS(a,b-1,ind+1);
		}
		else if(b<n-1 && arr[a][b+1]==s[ind])
		{
			//cout<<arr[a][b+1]<<endl;
			cout<<"right";
			DFS(a,b+1,ind+1);
		}
		else
		return;
	}
}
int main()
{
	int tc =0;
	cin>>tc;
	while(tc>0)
	{
		cin>>m>>n;
		int a,b;
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<n;j++)
			{
				char x;
				cin>>x;
				if(x=='@')
				{
					a=i;
					b= j;
				}
				arr[i][j] = x;
			}
		}
		s ="IEHOVA#";
		DFS(a,b,0);
		cout<<endl;
		tc--;
	}
	return 0;
}