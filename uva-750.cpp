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
int arr[8][8];
vector<map<int,int> >mymap;
bool check(map<int,int>vec,int r,int c)
{
	for(std::map<int,int>::iterator it = vec.begin();it!=vec.end();it++)
	if(abs(it->second-r) == abs(it->first-c))
	return false;
	return true;
}
int c =1;
void traverse(int i,map<int,int >vec,map<int,bool>row,map<int,bool>col)
{
	if(vec.size()==8)
	{
		bool bt = true;
		for(int i =0;i<mymap.size();i++)
		{
			if(mymap[i]==vec)
				bt =false;
		}
		if(bt)
		mymap.PB(vec);
	}
	else
	{
			if(i+1>7)
			i =0;
			else
			i++;
			for(int j =0;j<8;j++)
			{
				if(row.find(i) ==row.end() && col.find(j) ==col.end() && check(vec,i,j))
				{
					map<int,int>temp = vec;
					map<int,bool>t =row;
					map<int,bool>f= col;
					t[i] =true;
					f[j] = true;
					temp[j] =i;
					traverse(i,temp,t,f);
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
		int a,b;
		if(i!=0)
		cout<<endl;
			cout<<"SOLN       COLUMN"<<endl;
	cout<<" #      1 2 3 4 5 6 7 8"<<endl;
		cout<<endl;
		cin>>a>>b;
		map<int,bool>row;
		map<int,bool>col;
		map<int,int >vec;
		row[a-1] = true;
		col[b-1] = true;
		vec[b-1] =a-1;
		traverse(a-1,vec,row,col);
		sort(mymap.begin(),mymap.end());
			for(int j=0;j<mymap.size();j++)
			{//cout<<" "<<c++<<"     ";
			printf("%2d     ",c++);
				map<int,int>temp = mymap[j];
			for(int i =0;i<temp.size();i++)
				cout<<" "<<temp[i]+1;
			cout<<endl;
			}
		mymap.erase(mymap.begin(),mymap.end());
		c =1;
	}
	return 0;
}