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
bool bt;
map<pair<int,int>,bool>mymap;
void recurse(vector<int>arr,vector<bool>vertex,vector<bool>pp)
{
	if(!bt)
	return;
	if(arr.size()==vertex.size()+1)
	{
		for(int i =0;i<arr.size();i++)
		cout<<arr[i]<<" ";
		cout<<endl;
		bt =false;
	}
	else if(arr.size()<=vertex.size())
	{
		for(int i =0;i<pp.size();i++)
		{
			if(pp[i]==false && vertex[]
		}
	}
}
int main()
{
	int n =0;
	while(scanf("&d",&n)==1)
	{
		bt =true;
		int a;
		cin>>a;
		while(a!=(int)('#'))
		{
			int b;
			cin>>b;
			mymap[make_pair(a,b)] = true;
			cin>>a;
		}
		vector<int>arr;
		vector<bool>vertex(n);
		vector<bool>pp(n);
		fill(pp.begin(),pp.end(),false);
		fill(vertex.begin(),vertex.end(),false);
		recurse(arr,vertex,pp);
		if(bt)
		cout<<"N"<<endl;
	}
}