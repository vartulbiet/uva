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
void subset_sum(vector<pair<int,int> >arr,map<int,int>&xxx,int value,int t)
{
	int m = arr.size()+1;
	int n = value+1;
	int table[m][n];char hold[m][n];
	//for(int i =0;i<arr.size();i++)
		//	cout<<arr[i].first<<" ";
			//cout<<endl;
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<n;j++)
		table[i][j] = 0;
	}
	for(int i =1;i<m;i++)
	{
		for(int j =1;j<n;j++)
		{
			if(arr[i-1].first>j)
			{
				table[i][j] = table[i-1][j];
				hold[i][j] = 'u';
			}
			else if(arr[i-1].first == j)
			{
				table[i][j] =1;
				hold[i][j] = 'c';
			}
			else if(table[i-1][j-arr[i-1].first]==1)
			{
			table[i][j] = 1;hold[i][j] = 'd';
			}
		}
	}
	int w =0;
	for(int i =0;i<=value;i++)
	{
		cout<<table[m-1][i]<<"--";
		if(table[m-1][i]==1)
		{
			w =i;
		}
	}
	cout<<"-----------------------------------------------------";
	cout<<w<<" "<<value;
	vector<pair<int,int>  >e;
	while(w!=0)
	{
		if(hold[m-1][w]=='c'){
		e.PB(arr[m-1]);break;}
		else if(hold[m-1][w]=='d'){
		e.PB(arr[m-1]);w=w-arr[m-1].first;m--;}
		else
		if(hold[m-1][w]=='u')
		m--;
	}
	for(int i =0;i<e.size();i++)
	{
		cout<<e[i].first<<" ";
		xxx[e[i].second] = t;
	}
	cout<<endl;
}

int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int m;
		cin>>m;
		int value;
		value =m*100;
		vector<pair<int,int> >arr;
		//map<int,int>mymap;
		map<int,int>xxx;
		int tt =0;
		while(scanf("%d",&m)==1 && m!=0)
		{
			arr.PB(make_pair(m,tt));
			xxx[tt++] = 0;
		}
		sort(arr.begin(),arr.end());
		subset_sum(arr,xxx,value,1);
		vector<pair<int,int> >crr;
		for(int i =0;i<arr.size();i++)
		{
			if(xxx[arr[i].second]==0)
			crr.PB(arr[i]);
		}
		subset_sum(crr,xxx,value,2);
		for(std::map<int,int>::iterator j =xxx.begin();j!=xxx.end();j++)
		{
			if(j->second==1)
			{
				cout<<"port"<<endl;
			}
			if(j->second==2)
			{
				cout<<"starboard"<<endl;
			}
		}
		n--;
	}
	return 0;
}