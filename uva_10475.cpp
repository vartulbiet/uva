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
map<pair<int,string>,bool>mymappp;
string check(string s)
{
	string ans;
	for(int i =0;i<s.size();i++)
	{
		if(islower(s[i]))
		s[i]= toupper(s[i]);
		
	}
	return s;
}
bool checkk(vector<pair<string,string> >mymap,string a,string b)
{
	bool bt = true;
	for(int i=0;i<mymap.size();i++)
	{
		if((mymap[i].first == a && mymap[i].second ==b) || (mymap[i].first == b && mymap[i].second ==a))
		return true;
	}
	return false;
}
void recurse(vector<string>vec,vector<pair<string,string> >mymap,int c,vector<string>ans,vector<bool>keep,int ind)
{
	if(c==0)
	{
		for(int i =0;i<ans.size();i++)
		{
			if(i!=0)
			cout<<" ";
			cout<<ans[i];
			
		}
		cout<<endl;
	}
	else if(c>0)
	{
		for(int i = ind; i < vec.size() && keep[i]==false ; i++)
		{
			vector<string>temp = ans;
			vector<bool>visited = keep;
			bool bt = true;
			for(int j =0;j<temp.size() && bt;j++)
			{
				if(checkk(mymap,temp[j],vec[i]))
				bt= false;
			}
			if(bt)
			{
			temp.PB(vec[i]);
			visited[i] = true;
			recurse(vec,mymap,c-1,temp,visited,i+1);
			}
 		}
	}
}
bool compare(string a,string b)
{
	if(a.size()>b.size())
	return true;
	else if(a.size()== b.size())
	return a<b;
	else
	return false;
}
int main()
{
	int tc =0;
	cin>>tc;
	int y =1;
	while(tc--)
	{
		int a,b,c;
		cout<<"Set "<<y++<<":"<<endl;
		cin>>a>>b>>c;
		string s;
		vector<string>vec;
		for(int i =0;i<a;i++)
		{
			cin>>s;
			string y =check(s);
			vec.PB(y);
		}
		sort(vec.begin(),vec.end(),compare);
		vector<pair<string,string> >mymap;
		for(int i =0;i<b;i++)
		{
			string h;
			cin>>s>>h;
			string y =check(s);
			string tt =check(h);
			mymap.PB(make_pair(y,tt));
		}
		vector<string>ans;
		vector<bool>keep(a);
		fill(keep.begin(),keep.end(),false);
		recurse(vec,mymap,c,ans,keep,0);
		cout<<endl;
	}
	return 0;
}