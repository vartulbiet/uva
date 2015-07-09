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
int arr[8][8];
bool check(vector<pair<int,int> >vec,int r,int c)
{
	for(int i =0;i<vec.size();i++)
	if(abs(vec[i].first-r) == abs(vec[i].second-c))
	return false;
	return true;
}
void traverse(int r,vector<pair<int,int> >vec,map<int,bool>row,map<int,bool>col)
{
	if(vec.size()==8)
	{
		int val =0;
		for(int i =0;i<vec.size();i++)
			val+=arr[vec[i].first][vec[i].second];
		if(val>ans)
		ans= val;
	}
	else
	{
			for(int j =0;j<8;j++)
			{
				if(row.find(r+1) ==row.end() && col.find(j) ==col.end() && check(vec,r+1,j))
				{
					vector<pair<int,int> >temp = vec;
					map<int,bool>t =row;
					map<int,bool>f= col;
					t[r+1] =true;
					f[j] = true;
					temp.PB(make_pair(r+1,j));
					traverse(r+1,temp,t,f);
				}
			}
	}
}
int main()
{
	int t =0;
	cin>>t;
	for(int i =0;i<t;i++)
	{
		for(int i =0;i<8;i++)
		{
			for(int j =0;j<8;j++)
			cin>>arr[i][j];
		}
		ans =0;
	map<int,bool>row;
		map<int,bool>col;
		vector<pair<int,int> >vec;
		for(int j =0;j<8;j++)
		{
			row[0] = true;
			col[j] = true;
			vec.PB(make_pair(0,j));
			traverse(0,vec,row,col);
			row.erase(row.begin(),row.end());
			col.erase(col.begin(),col.end());
			vec.erase(vec.begin(),vec.end());
		}
	printf("%5d\n",ans);
	}
	return 0;
}