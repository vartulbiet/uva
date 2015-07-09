#include <cmath>
#include <cstdio>
#include <vector>
#include<string>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
void get_print(vector<string>x)
{
	for(int i =0;i<x.size();i++)
	{
		string d =x[i];
		for(int j =0;j<d.size();j++)
		{
			cout<<d[j];
		}
		cout<<endl;
	}
}
void start_colour(vector<string>&z,int a,int b,char ch)
{
	if(a>=0 && a<z.size())
	{
	string t =z[a];
	int n = t.size();
	if(b>=0 && b<n && (t[b]==' '))
	{
		t[b]=ch;
		z[a] =t;
		//cout<<z[a]<<endl;
		//start_colour(z,a-1,b-1);
		//start_colour(z,a+1,b-1);
		//start_colour(z,a-1,b+1);
		//start_colour(z,a+1,b+1);
		start_colour(z,a-1,b,ch);
		start_colour(z,a+1,b,ch);
		start_colour(z,a,b-1,ch);
		start_colour(z,a,b+1,ch);
	}
	else
	return;
	}
	else
	return;
}
void d_colouring(vector<string>&s)
{
	for(int i =0;i<s.size();i++)
	{
		string x =s[i];
		for(int j =0;j<x.size();j++)
		{
			if(x[j]!='X' && x[j]!=' ')
			{
				start_colour(s,i-1,j,x[j]);
				start_colour(s,i+1,j,x[j]);
				start_colour(s,i,j-1,x[j]);
				start_colour(s,i,j+1,x[j]);
			}
		}
	}
}
int main()
{
	int n =0;
	string s;
	vector<string>x;
	while(getline(cin,s))
	{
		while(s[0]!='_')
		{
			x.push_back(s);
			getline(cin,s);
		}
		d_colouring(x);
		get_print(x);
		x.erase(x.begin(),x.end());
		cout<<s<<endl;;
		n--;
	}
}