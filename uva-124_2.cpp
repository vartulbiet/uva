#include <vector>
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
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define pi 3.141592653589793
using namespace std;

/*
a b f g
a b b f
v w x y z
v y x v z v w v*/
map<vector<char>,bool>mymap;
string toString(vector<char>x)
{
	string y;
	for(int i =0;i<x.size();i++)
	y.push_back(x[i]);
	return y;
}
void permute(vector<char> x)
{
	if(mymap.find(x) ==mymap.end())
	{
		mymap[x] =true;
	for(int i =0;i<x.size()-1;i++)
	{
		char temp =x[i+1];
		x[i+1] = x[i];
		x[i] = temp;
		permute(x);
		temp = x[i+1];
		x[i+1] = x[i];
		x[i] = temp;
	}
	}else
	return;
}
	vector<char>arr;
	vector<pair<char,char> >vec;
	bool check(pair<char,char>v)
	{
		for(int i =0;i<vec.size();i++)
		if(v == vec[i])
		return false;
		return true;
	}
int main()
{

	char a,b;
	string x,y;
	int h =0;
	while(getline(cin,x))
	{
		getline(cin,y);
		if(h!=0)
		cout<<endl;
		h++;
	//	cout<<x<<y;
		for(int i =0;i<x.size();i++)
		{
			if(x[i]>='a' && y[i]<='z')
			arr.push_back(x[i]);
		}
		for(int i =0;i<y.size();i=i+4)
		{
			vec.push_back(make_pair(y[i],y[i+2]));
		}
		permute(arr);
		vector<string >hold;
		for(std::map<vector<char>,bool>::iterator it = mymap.begin();it!=mymap.end();it++)
		{
			vector<char>tt= it->first;
			bool xx =true;
			for(int i =0;i<tt.size();i++)
			{
				for(int j =i+1;j<tt.size();j++)
				{
					if(!check(make_pair(tt[i],tt[j])))
					{
						xx= false;
						break;
					}
				}
				if(!xx)
				break;
			}
			if(xx)
			{
			string y=toString(tt);
			reverse(y.begin(),y.end());
				hold.push_back(y);
			}

		}
		mymap.erase(mymap.begin(),mymap.end());
			sort(hold.begin(),hold.end());
			int u =0;
		while(hold.size()!=0)
			{
				string ff = hold[u];
				hold.erase(hold.begin()+u);
				for(int j =0;j<ff.size();j++)
				cout<<ff[j];
				cout<<endl;
			}
		
		vec.erase(vec.begin(),vec.end());
		arr.erase(arr.begin(),arr.end());
	}
	return 0;
}